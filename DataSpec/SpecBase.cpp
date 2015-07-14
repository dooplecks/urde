#include "SpecBase.hpp"

namespace Retro
{

LogVisor::LogModule LogModule("RetroDataSpec");

bool SpecBase::canExtract(const ExtractPassInfo& info, std::vector<ExtractReport>& reps)
{
    bool isWii;
    std::unique_ptr<NOD::DiscBase> disc = NOD::OpenDiscFromImage(info.srcpath.c_str(), isWii);
    if (!disc)
        return false;
    const char* gameID = disc->getHeader().gameID;

    bool standalone = true;
    if (isWii)
    {
        if (!memcmp(gameID, "R3M", 3))
            standalone = false;
    }

    if (standalone && !checkStandaloneID(gameID))
        return false;

    char region = disc->getHeader().gameID[3];
    static const HECL::SystemString regNONE = _S("");
    static const HECL::SystemString regE = _S("NTSC");
    static const HECL::SystemString regJ = _S("NTSC-J");
    static const HECL::SystemString regP = _S("PAL");
    const HECL::SystemString* regstr = &regNONE;
    switch (region)
    {
    case 'E':
        regstr = &regE;
        break;
    case 'J':
        regstr = &regJ;
        break;
    case 'P':
        regstr = &regP;
        break;
    }

    if (standalone)
        return checkFromStandaloneDisc(*disc.get(), *regstr, info.extractArgs, reps);
    else
        return checkFromTrilogyDisc(*disc.get(), *regstr, info.extractArgs, reps);
}

void SpecBase::doExtract(const HECL::Database::Project& project, const ExtractPassInfo& info)
{
}

bool SpecBase::canCook(const HECL::Database::Project& project, const CookTaskInfo& info)
{
}

void SpecBase::doCook(const HECL::Database::Project& project, const CookTaskInfo& info)
{
}

bool SpecBase::canPackage(const HECL::Database::Project& project, const PackagePassInfo& info)
{
}

void SpecBase::gatherDependencies(const HECL::Database::Project& project, const PackagePassInfo& info,
                                  std::unordered_set<HECL::ProjectPath>& implicitsOut)
{
}

void SpecBase::doPackage(const HECL::Database::Project& project, const PackagePassInfo& info)
{
}

}
