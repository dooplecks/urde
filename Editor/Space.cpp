#include "Space.hpp"
#include "ViewManager.hpp"
#include "ResourceBrowser.hpp"

namespace URDE
{
static LogVisor::LogModule Log("URDE::Space");

Specter::View* Space::buildSpaceView(Specter::ViewResources& res)
{
    if (usesToolbar())
    {
        m_space.reset(new Specter::Space(res, m_vm.rootView(), Specter::Toolbar::Position::Bottom));
        Specter::View* sview = buildContentView(res);
        m_space->setContentView(sview);
        buildToolbarView(res, *m_space->toolbar());
        return m_space.get();
    }
    else
    {
        m_space.reset(new Specter::Space(res, m_vm.rootView(), Specter::Toolbar::Position::None));
        Specter::View* sview = buildContentView(res);
        m_space->setContentView(sview);
        return m_space.get();
    }
}

Specter::View* SplitSpace::buildContentView(Specter::ViewResources& res)
{
    m_splitView.reset(new Specter::SplitView(res, m_vm.rootView(), Specter::SplitView::Axis::Horizontal));
    if (m_slots[0])
        m_splitView->setContentView(0, m_slots[0]->buildSpaceView(res));
    if (m_slots[1])
        m_splitView->setContentView(1, m_slots[1]->buildSpaceView(res));
    return m_splitView.get();
}

void SplitSpace::setSpaceSlot(unsigned slot, std::unique_ptr<Space>&& space)
{
    if (slot > 1)
        Log.report(LogVisor::FatalError, "invalid slot %u for SplitView", slot);
    m_slots[slot] = std::move(space);
}

template <class Reader>
static Space* BuildNewSpace(ViewManager& vm, Space::Class cls, Reader& r)
{
    using Class = Space::Class;
    switch (cls)
    {
    case Class::SplitSpace:
        return new SplitSpace(vm, r);
    case Class::ResourceBrowser:
        return new ResourceBrowser(vm, r);
    default: break;
    }
    return nullptr;
}

void Space::saveState(Athena::io::IStreamWriter& w) const
{
    w.writeUint32Big(atUint32(m_class));
    spaceState().write(w);
}

void Space::saveState(Athena::io::YAMLDocWriter& w) const
{
    w.writeUint32("class", atUint32(m_class));
    spaceState().write(w);
}

Space* Space::NewSpaceFromConfigStream(ViewManager& vm, ConfigReader& r)
{
#ifdef URDE_BINARY_CONFIGS
    Class cls = Class(r.readUint32Big());
    return BuildNewSpace(vm, cls, r);
#else
    Class cls = Class(r.readUint32("class"));
    return BuildNewSpace(vm, cls, r);
#endif
}

}