#pragma once

#include <cstdint>
#include <unordered_map>
#include <vector>

#include "DataSpec/DNACommon/DNACommon.hpp"
#include "DataSpec/DNACommon/ParticleCommon.hpp"

#include <athena/DNA.hpp>

namespace DataSpec {
class PAKEntryReadStream;
}

namespace hecl {
class ProjectPath;
}

namespace DataSpec::DNAParticle {

template <class IDType>
struct _CRSM {
  static constexpr ParticleType Type = ParticleType::CRSM;
  ChildResourceFactory<IDType> NODP;
  ChildResourceFactory<IDType> DEFS;
  ChildResourceFactory<IDType> CRTS;
  ChildResourceFactory<IDType> MTLS;
  ChildResourceFactory<IDType> GRAS;
  ChildResourceFactory<IDType> ICEE;
  ChildResourceFactory<IDType> GOOO;
  ChildResourceFactory<IDType> WODS;
  ChildResourceFactory<IDType> WATR;
  ChildResourceFactory<IDType> _1MUD;
  ChildResourceFactory<IDType> _1LAV;
  ChildResourceFactory<IDType> _1SAN;
  ChildResourceFactory<IDType> _1PRJ;
  ChildResourceFactory<IDType> DCHR;
  ChildResourceFactory<IDType> DCHS;
  ChildResourceFactory<IDType> DCSH;
  ChildResourceFactory<IDType> DENM;
  ChildResourceFactory<IDType> DESP;
  ChildResourceFactory<IDType> DESH;
  ChildResourceFactory<IDType> BTLE;
  ChildResourceFactory<IDType> WASP;
  ChildResourceFactory<IDType> TALP;
  ChildResourceFactory<IDType> PTGM;
  ChildResourceFactory<IDType> SPIR;
  ChildResourceFactory<IDType> FPIR;
  ChildResourceFactory<IDType> FFLE;
  ChildResourceFactory<IDType> PARA;
  ChildResourceFactory<IDType> BMON;
  ChildResourceFactory<IDType> BFLR;
  ChildResourceFactory<IDType> PBOS;
  ChildResourceFactory<IDType> IBOS;
  ChildResourceFactory<IDType> _1SVA;
  ChildResourceFactory<IDType> _1RPR;
  ChildResourceFactory<IDType> _1MTR;
  ChildResourceFactory<IDType> _1PDS;
  ChildResourceFactory<IDType> _1FLB;
  ChildResourceFactory<IDType> _1DRN;
  ChildResourceFactory<IDType> _1MRE;
  ChildResourceFactory<IDType> CHOZ;
  ChildResourceFactory<IDType> JZAP;
  ChildResourceFactory<IDType> _1ISE;
  ChildResourceFactory<IDType> _1BSE;
  ChildResourceFactory<IDType> _1ATB;
  ChildResourceFactory<IDType> _1ATA;
  ChildResourceFactory<IDType> BTSP;
  ChildResourceFactory<IDType> WWSP;
  ChildResourceFactory<IDType> TASP;
  ChildResourceFactory<IDType> TGSP;
  ChildResourceFactory<IDType> SPSP;
  ChildResourceFactory<IDType> FPSP;
  ChildResourceFactory<IDType> FFSP;
  ChildResourceFactory<IDType> PSSP;
  ChildResourceFactory<IDType> BMSP;
  ChildResourceFactory<IDType> BFSP;
  ChildResourceFactory<IDType> PBSP;
  ChildResourceFactory<IDType> IBSP;
  ChildResourceFactory<IDType> _2SVA;
  ChildResourceFactory<IDType> _2RPR;
  ChildResourceFactory<IDType> _2MTR;
  ChildResourceFactory<IDType> _2PDS;
  ChildResourceFactory<IDType> _2FLB;
  ChildResourceFactory<IDType> _2DRN;
  ChildResourceFactory<IDType> _2MRE;
  ChildResourceFactory<IDType> CHSP;
  ChildResourceFactory<IDType> JZSP;
  ChildResourceFactory<IDType> _3ISE;
  ChildResourceFactory<IDType> _3BSE;
  ChildResourceFactory<IDType> _3ATB;
  ChildResourceFactory<IDType> _3ATA;
  ChildResourceFactory<IDType> BTSH;
  ChildResourceFactory<IDType> WWSH;
  ChildResourceFactory<IDType> TASH;
  ChildResourceFactory<IDType> TGSH;
  ChildResourceFactory<IDType> SPSH;
  ChildResourceFactory<IDType> FPSH;
  ChildResourceFactory<IDType> FFSH;
  ChildResourceFactory<IDType> PSSH;
  ChildResourceFactory<IDType> BMSH;
  ChildResourceFactory<IDType> BFSH;
  ChildResourceFactory<IDType> PBSH;
  ChildResourceFactory<IDType> IBSH;
  ChildResourceFactory<IDType> _3SVA;
  ChildResourceFactory<IDType> _3RPR;
  ChildResourceFactory<IDType> _3MTR;
  ChildResourceFactory<IDType> _3PDS;
  ChildResourceFactory<IDType> _3FLB;
  ChildResourceFactory<IDType> _3DRN;
  ChildResourceFactory<IDType> _3MRE;
  ChildResourceFactory<IDType> CHSH;
  ChildResourceFactory<IDType> JZSH;
  ChildResourceFactory<IDType> _5ISE;
  ChildResourceFactory<IDType> _5BSE;
  ChildResourceFactory<IDType> _5ATB;
  ChildResourceFactory<IDType> _5ATA;
  ChildResourceFactory<IDType> NCDL;
  ChildResourceFactory<IDType> DDCL;
  ChildResourceFactory<IDType> CODL;
  ChildResourceFactory<IDType> MEDL;
  ChildResourceFactory<IDType> GRDL;
  ChildResourceFactory<IDType> ICDL;
  ChildResourceFactory<IDType> GODL;
  ChildResourceFactory<IDType> WODL;
  ChildResourceFactory<IDType> WTDL;
  ChildResourceFactory<IDType> _3MUD;
  ChildResourceFactory<IDType> _3LAV;
  ChildResourceFactory<IDType> _3SAN;
  ChildResourceFactory<IDType> CHDL;
  ChildResourceFactory<IDType> ENDL;
  uint32_t NSFX = ~0;
  uint32_t DSFX = ~0;
  uint32_t CSFX = ~0;
  uint32_t MSFX = ~0;
  uint32_t GRFX = ~0;
  uint32_t ICFX = ~0;
  uint32_t GOFX = ~0;
  uint32_t WSFX = ~0;
  uint32_t WTFX = ~0;
  uint32_t _2MUD = ~0;
  uint32_t _2LAV = ~0;
  uint32_t _2SAN = ~0;
  uint32_t _2PRJ = ~0;
  uint32_t DCFX = ~0;
  uint32_t DSHX = ~0;
  uint32_t DEFX = ~0;
  uint32_t ESFX = ~0;
  uint32_t SHFX = ~0;
  uint32_t BEFX = ~0;
  uint32_t WWFX = ~0;
  uint32_t TAFX = ~0;
  uint32_t GTFX = ~0;
  uint32_t SPFX = ~0;
  uint32_t FPFX = ~0;
  uint32_t FFFX = ~0;
  uint32_t PAFX = ~0;
  uint32_t BMFX = ~0;
  uint32_t BFFX = ~0;
  uint32_t PBFX = ~0;
  uint32_t IBFX = ~0;
  uint32_t _4SVA = ~0;
  uint32_t _4RPR = ~0;
  uint32_t _4MTR = ~0;
  uint32_t _4PDS = ~0;
  uint32_t _4FLB = ~0;
  uint32_t _4DRN = ~0;
  uint32_t _4MRE = ~0;
  uint32_t CZFX = ~0;
  uint32_t JZAS = ~0;
  uint32_t _2ISE = ~0;
  uint32_t _2BSE = ~0;
  uint32_t _2ATB = ~0;
  uint32_t _2ATA = ~0;
  uint32_t BSFX = ~0;
  uint32_t TSFX = ~0;
  uint32_t GSFX = ~0;
  uint32_t SSFX = ~0;
  uint32_t FSFX = ~0;
  uint32_t SFFX = ~0;
  uint32_t PSFX = ~0;
  uint32_t SBFX = ~0;
  uint32_t PBSX = ~0;
  uint32_t IBSX = ~0;
  uint32_t _5SVA = ~0;
  uint32_t _5RPR = ~0;
  uint32_t _5MTR = ~0;
  uint32_t _5PDS = ~0;
  uint32_t _5FLB = ~0;
  uint32_t _5DRN = ~0;
  uint32_t _5MRE = ~0;
  uint32_t JZPS = ~0;
  uint32_t _4ISE = ~0;
  uint32_t _4BSE = ~0;
  uint32_t _4ATB = ~0;
  uint32_t _4ATA = ~0;
  uint32_t BHFX = ~0;
  uint32_t WHFX = ~0;
  uint32_t THFX = ~0;
  uint32_t GHFX = ~0;
  uint32_t FHFX = ~0;
  uint32_t HFFX = ~0;
  uint32_t PHFX = ~0;
  uint32_t MHFX = ~0;
  uint32_t HBFX = ~0;
  uint32_t PBHX = ~0;
  uint32_t IBHX = ~0;
  uint32_t _6SVA = ~0;
  uint32_t _6RPR = ~0;
  uint32_t _6MTR = ~0;
  uint32_t _6PDS = ~0;
  uint32_t _6FLB = ~0;
  uint32_t _6DRN = ~0;
  uint32_t _6MRE = ~0;
  uint32_t CHFX = ~0;
  uint32_t JZHS = ~0;
  uint32_t _6ISE = ~0;
  uint32_t _6BSE = ~0;
  uint32_t _6ATB = ~0;
  uint32_t _6ATA = ~0;
  float x30_RNGE = 0.f;
  float x34_FOFF = 0.f;

  template<typename _Func>
  void constexpr Enumerate(_Func f) {
    f(FOURCC('NODP'), NODP);
    f(FOURCC('DEFS'), DEFS);
    f(FOURCC('CRTS'), CRTS);
    f(FOURCC('MTLS'), MTLS);
    f(FOURCC('GRAS'), GRAS);
    f(FOURCC('ICEE'), ICEE);
    f(FOURCC('GOOO'), GOOO);
    f(FOURCC('WODS'), WODS);
    f(FOURCC('WATR'), WATR);
    f(FOURCC('1MUD'), _1MUD);
    f(FOURCC('1LAV'), _1LAV);
    f(FOURCC('1SAN'), _1SAN);
    f(FOURCC('1PRJ'), _1PRJ);
    f(FOURCC('DCHR'), DCHR);
    f(FOURCC('DCHS'), DCHS);
    f(FOURCC('DCSH'), DCSH);
    f(FOURCC('DENM'), DENM);
    f(FOURCC('DESP'), DESP);
    f(FOURCC('DESH'), DESH);
    f(FOURCC('BTLE'), BTLE);
    f(FOURCC('WASP'), WASP);
    f(FOURCC('TALP'), TALP);
    f(FOURCC('PTGM'), PTGM);
    f(FOURCC('SPIR'), SPIR);
    f(FOURCC('FPIR'), FPIR);
    f(FOURCC('FFLE'), FFLE);
    f(FOURCC('PARA'), PARA);
    f(FOURCC('BMON'), BMON);
    f(FOURCC('BFLR'), BFLR);
    f(FOURCC('PBOS'), PBOS);
    f(FOURCC('IBOS'), IBOS);
    f(FOURCC('1SVA'), _1SVA);
    f(FOURCC('1RPR'), _1RPR);
    f(FOURCC('1MTR'), _1MTR);
    f(FOURCC('1PDS'), _1PDS);
    f(FOURCC('1FLB'), _1FLB);
    f(FOURCC('1DRN'), _1DRN);
    f(FOURCC('1MRE'), _1MRE);
    f(FOURCC('CHOZ'), CHOZ);
    f(FOURCC('JZAP'), JZAP);
    f(FOURCC('1ISE'), _1ISE);
    f(FOURCC('1BSE'), _1BSE);
    f(FOURCC('1ATB'), _1ATB);
    f(FOURCC('1ATA'), _1ATA);
    f(FOURCC('BTSP'), BTSP);
    f(FOURCC('WWSP'), WWSP);
    f(FOURCC('TASP'), TASP);
    f(FOURCC('TGSP'), TGSP);
    f(FOURCC('SPSP'), SPSP);
    f(FOURCC('FPSP'), FPSP);
    f(FOURCC('FFSP'), FFSP);
    f(FOURCC('PSSP'), PSSP);
    f(FOURCC('BMSP'), BMSP);
    f(FOURCC('BFSP'), BFSP);
    f(FOURCC('PBSP'), PBSP);
    f(FOURCC('IBSP'), IBSP);
    f(FOURCC('2SVA'), _2SVA);
    f(FOURCC('2RPR'), _2RPR);
    f(FOURCC('2MTR'), _2MTR);
    f(FOURCC('2PDS'), _2PDS);
    f(FOURCC('2FLB'), _2FLB);
    f(FOURCC('2DRN'), _2DRN);
    f(FOURCC('2MRE'), _2MRE);
    f(FOURCC('CHSP'), CHSP);
    f(FOURCC('JZSP'), JZSP);
    f(FOURCC('3ISE'), _3ISE);
    f(FOURCC('3BSE'), _3BSE);
    f(FOURCC('3ATB'), _3ATB);
    f(FOURCC('3ATA'), _3ATA);
    f(FOURCC('BTSH'), BTSH);
    f(FOURCC('WWSH'), WWSH);
    f(FOURCC('TASH'), TASH);
    f(FOURCC('TGSH'), TGSH);
    f(FOURCC('SPSH'), SPSH);
    f(FOURCC('FPSH'), FPSH);
    f(FOURCC('FFSH'), FFSH);
    f(FOURCC('PSSH'), PSSH);
    f(FOURCC('BMSH'), BMSH);
    f(FOURCC('BFSH'), BFSH);
    f(FOURCC('PBSH'), PBSH);
    f(FOURCC('IBSH'), IBSH);
    f(FOURCC('3SVA'), _3SVA);
    f(FOURCC('3RPR'), _3RPR);
    f(FOURCC('3MTR'), _3MTR);
    f(FOURCC('3PDS'), _3PDS);
    f(FOURCC('3FLB'), _3FLB);
    f(FOURCC('3DRN'), _3DRN);
    f(FOURCC('3MRE'), _3MRE);
    f(FOURCC('CHSH'), CHSH);
    f(FOURCC('JZSH'), JZSH);
    f(FOURCC('5ISE'), _5ISE);
    f(FOURCC('5BSE'), _5BSE);
    f(FOURCC('5ATB'), _5ATB);
    f(FOURCC('5ATA'), _5ATA);
    f(FOURCC('NCDL'), NCDL);
    f(FOURCC('DDCL'), DDCL);
    f(FOURCC('CODL'), CODL);
    f(FOURCC('MEDL'), MEDL);
    f(FOURCC('GRDL'), GRDL);
    f(FOURCC('ICDL'), ICDL);
    f(FOURCC('GODL'), GODL);
    f(FOURCC('WODL'), WODL);
    f(FOURCC('WTDL'), WTDL);
    f(FOURCC('3MUD'), _3MUD);
    f(FOURCC('3LAV'), _3LAV);
    f(FOURCC('3SAN'), _3SAN);
    f(FOURCC('CHDL'), CHDL);
    f(FOURCC('ENDL'), ENDL);
    f(FOURCC('NSFX'), NSFX);
    f(FOURCC('DSFX'), DSFX);
    f(FOURCC('CSFX'), CSFX);
    f(FOURCC('MSFX'), MSFX);
    f(FOURCC('GRFX'), GRFX);
    f(FOURCC('ICFX'), ICFX);
    f(FOURCC('GOFX'), GOFX);
    f(FOURCC('WSFX'), WSFX);
    f(FOURCC('WTFX'), WTFX);
    f(FOURCC('2MUD'), _2MUD);
    f(FOURCC('2LAV'), _2LAV);
    f(FOURCC('2SAN'), _2SAN);
    f(FOURCC('2PRJ'), _2PRJ);
    f(FOURCC('DCFX'), DCFX);
    f(FOURCC('DSHX'), DSHX);
    f(FOURCC('DEFX'), DEFX);
    f(FOURCC('ESFX'), ESFX);
    f(FOURCC('SHFX'), SHFX);
    f(FOURCC('BEFX'), BEFX);
    f(FOURCC('WWFX'), WWFX);
    f(FOURCC('TAFX'), TAFX);
    f(FOURCC('GTFX'), GTFX);
    f(FOURCC('SPFX'), SPFX);
    f(FOURCC('FPFX'), FPFX);
    f(FOURCC('FFFX'), FFFX);
    f(FOURCC('PAFX'), PAFX);
    f(FOURCC('BMFX'), BMFX);
    f(FOURCC('BFFX'), BFFX);
    f(FOURCC('PBFX'), PBFX);
    f(FOURCC('IBFX'), IBFX);
    f(FOURCC('4SVA'), _4SVA);
    f(FOURCC('4RPR'), _4RPR);
    f(FOURCC('4MTR'), _4MTR);
    f(FOURCC('4PDS'), _4PDS);
    f(FOURCC('4FLB'), _4FLB);
    f(FOURCC('4DRN'), _4DRN);
    f(FOURCC('4MRE'), _4MRE);
    f(FOURCC('CZFX'), CZFX);
    f(FOURCC('JZAS'), JZAS);
    f(FOURCC('2ISE'), _2ISE);
    f(FOURCC('2BSE'), _2BSE);
    f(FOURCC('2ATB'), _2ATB);
    f(FOURCC('2ATA'), _2ATA);
    f(FOURCC('BSFX'), BSFX);
    f(FOURCC('TSFX'), TSFX);
    f(FOURCC('GSFX'), GSFX);
    f(FOURCC('SSFX'), SSFX);
    f(FOURCC('FSFX'), FSFX);
    f(FOURCC('SFFX'), SFFX);
    f(FOURCC('PSFX'), PSFX);
    f(FOURCC('SBFX'), SBFX);
    f(FOURCC('PBSX'), PBSX);
    f(FOURCC('IBSX'), IBSX);
    f(FOURCC('5SVA'), _5SVA);
    f(FOURCC('5RPR'), _5RPR);
    f(FOURCC('5MTR'), _5MTR);
    f(FOURCC('5PDS'), _5PDS);
    f(FOURCC('5FLB'), _5FLB);
    f(FOURCC('5DRN'), _5DRN);
    f(FOURCC('5MRE'), _5MRE);
    f(FOURCC('JZPS'), JZPS);
    f(FOURCC('4ISE'), _4ISE);
    f(FOURCC('4BSE'), _4BSE);
    f(FOURCC('4ATB'), _4ATB);
    f(FOURCC('4ATA'), _4ATA);
    f(FOURCC('BHFX'), BHFX);
    f(FOURCC('WHFX'), WHFX);
    f(FOURCC('THFX'), THFX);
    f(FOURCC('GHFX'), GHFX);
    f(FOURCC('FHFX'), FHFX);
    f(FOURCC('HFFX'), HFFX);
    f(FOURCC('PHFX'), PHFX);
    f(FOURCC('MHFX'), MHFX);
    f(FOURCC('HBFX'), HBFX);
    f(FOURCC('PBHX'), PBHX);
    f(FOURCC('IBHX'), IBHX);
    f(FOURCC('6SVA'), _6SVA);
    f(FOURCC('6RPR'), _6RPR);
    f(FOURCC('6MTR'), _6MTR);
    f(FOURCC('6PDS'), _6PDS);
    f(FOURCC('6FLB'), _6FLB);
    f(FOURCC('6DRN'), _6DRN);
    f(FOURCC('6MRE'), _6MRE);
    f(FOURCC('CHFX'), CHFX);
    f(FOURCC('JZHS'), JZHS);
    f(FOURCC('6ISE'), _6ISE);
    f(FOURCC('6BSE'), _6BSE);
    f(FOURCC('6ATB'), _6ATB);
    f(FOURCC('6ATA'), _6ATA);
    f(FOURCC('RNGE'), x30_RNGE);
    f(FOURCC('FOFF'), x34_FOFF);
  }

  template<typename _Func>
  bool constexpr Lookup(FourCC fcc, _Func f) {
    switch (fcc.toUint32()) {
    case SBIG('NODP'): f(NODP); return true;
    case SBIG('DEFS'): f(DEFS); return true;
    case SBIG('CRTS'): f(CRTS); return true;
    case SBIG('MTLS'): f(MTLS); return true;
    case SBIG('GRAS'): f(GRAS); return true;
    case SBIG('ICEE'): f(ICEE); return true;
    case SBIG('GOOO'): f(GOOO); return true;
    case SBIG('WODS'): f(WODS); return true;
    case SBIG('WATR'): f(WATR); return true;
    case SBIG('1MUD'): f(_1MUD); return true;
    case SBIG('1LAV'): f(_1LAV); return true;
    case SBIG('1SAN'): f(_1SAN); return true;
    case SBIG('1PRJ'): f(_1PRJ); return true;
    case SBIG('DCHR'): f(DCHR); return true;
    case SBIG('DCHS'): f(DCHS); return true;
    case SBIG('DCSH'): f(DCSH); return true;
    case SBIG('DENM'): f(DENM); return true;
    case SBIG('DESP'): f(DESP); return true;
    case SBIG('DESH'): f(DESH); return true;
    case SBIG('BTLE'): f(BTLE); return true;
    case SBIG('WASP'): f(WASP); return true;
    case SBIG('TALP'): f(TALP); return true;
    case SBIG('PTGM'): f(PTGM); return true;
    case SBIG('SPIR'): f(SPIR); return true;
    case SBIG('FPIR'): f(FPIR); return true;
    case SBIG('FFLE'): f(FFLE); return true;
    case SBIG('PARA'): f(PARA); return true;
    case SBIG('BMON'): f(BMON); return true;
    case SBIG('BFLR'): f(BFLR); return true;
    case SBIG('PBOS'): f(PBOS); return true;
    case SBIG('IBOS'): f(IBOS); return true;
    case SBIG('1SVA'): f(_1SVA); return true;
    case SBIG('1RPR'): f(_1RPR); return true;
    case SBIG('1MTR'): f(_1MTR); return true;
    case SBIG('1PDS'): f(_1PDS); return true;
    case SBIG('1FLB'): f(_1FLB); return true;
    case SBIG('1DRN'): f(_1DRN); return true;
    case SBIG('1MRE'): f(_1MRE); return true;
    case SBIG('CHOZ'): f(CHOZ); return true;
    case SBIG('JZAP'): f(JZAP); return true;
    case SBIG('1ISE'): f(_1ISE); return true;
    case SBIG('1BSE'): f(_1BSE); return true;
    case SBIG('1ATB'): f(_1ATB); return true;
    case SBIG('1ATA'): f(_1ATA); return true;
    case SBIG('BTSP'): f(BTSP); return true;
    case SBIG('WWSP'): f(WWSP); return true;
    case SBIG('TASP'): f(TASP); return true;
    case SBIG('TGSP'): f(TGSP); return true;
    case SBIG('SPSP'): f(SPSP); return true;
    case SBIG('FPSP'): f(FPSP); return true;
    case SBIG('FFSP'): f(FFSP); return true;
    case SBIG('PSSP'): f(PSSP); return true;
    case SBIG('BMSP'): f(BMSP); return true;
    case SBIG('BFSP'): f(BFSP); return true;
    case SBIG('PBSP'): f(PBSP); return true;
    case SBIG('IBSP'): f(IBSP); return true;
    case SBIG('2SVA'): f(_2SVA); return true;
    case SBIG('2RPR'): f(_2RPR); return true;
    case SBIG('2MTR'): f(_2MTR); return true;
    case SBIG('2PDS'): f(_2PDS); return true;
    case SBIG('2FLB'): f(_2FLB); return true;
    case SBIG('2DRN'): f(_2DRN); return true;
    case SBIG('2MRE'): f(_2MRE); return true;
    case SBIG('CHSP'): f(CHSP); return true;
    case SBIG('JZSP'): f(JZSP); return true;
    case SBIG('3ISE'): f(_3ISE); return true;
    case SBIG('3BSE'): f(_3BSE); return true;
    case SBIG('3ATB'): f(_3ATB); return true;
    case SBIG('3ATA'): f(_3ATA); return true;
    case SBIG('BTSH'): f(BTSH); return true;
    case SBIG('WWSH'): f(WWSH); return true;
    case SBIG('TASH'): f(TASH); return true;
    case SBIG('TGSH'): f(TGSH); return true;
    case SBIG('SPSH'): f(SPSH); return true;
    case SBIG('FPSH'): f(FPSH); return true;
    case SBIG('FFSH'): f(FFSH); return true;
    case SBIG('PSSH'): f(PSSH); return true;
    case SBIG('BMSH'): f(BMSH); return true;
    case SBIG('BFSH'): f(BFSH); return true;
    case SBIG('PBSH'): f(PBSH); return true;
    case SBIG('IBSH'): f(IBSH); return true;
    case SBIG('3SVA'): f(_3SVA); return true;
    case SBIG('3RPR'): f(_3RPR); return true;
    case SBIG('3MTR'): f(_3MTR); return true;
    case SBIG('3PDS'): f(_3PDS); return true;
    case SBIG('3FLB'): f(_3FLB); return true;
    case SBIG('3DRN'): f(_3DRN); return true;
    case SBIG('3MRE'): f(_3MRE); return true;
    case SBIG('CHSH'): f(CHSH); return true;
    case SBIG('JZSH'): f(JZSH); return true;
    case SBIG('5ISE'): f(_5ISE); return true;
    case SBIG('5BSE'): f(_5BSE); return true;
    case SBIG('5ATB'): f(_5ATB); return true;
    case SBIG('5ATA'): f(_5ATA); return true;
    case SBIG('NCDL'): f(NCDL); return true;
    case SBIG('DDCL'): f(DDCL); return true;
    case SBIG('CODL'): f(CODL); return true;
    case SBIG('MEDL'): f(MEDL); return true;
    case SBIG('GRDL'): f(GRDL); return true;
    case SBIG('ICDL'): f(ICDL); return true;
    case SBIG('GODL'): f(GODL); return true;
    case SBIG('WODL'): f(WODL); return true;
    case SBIG('WTDL'): f(WTDL); return true;
    case SBIG('3MUD'): f(_3MUD); return true;
    case SBIG('3LAV'): f(_3LAV); return true;
    case SBIG('3SAN'): f(_3SAN); return true;
    case SBIG('CHDL'): f(CHDL); return true;
    case SBIG('ENDL'): f(ENDL); return true;
    case SBIG('NSFX'): f(NSFX); return true;
    case SBIG('DSFX'): f(DSFX); return true;
    case SBIG('CSFX'): f(CSFX); return true;
    case SBIG('MSFX'): f(MSFX); return true;
    case SBIG('GRFX'): f(GRFX); return true;
    case SBIG('ICFX'): f(ICFX); return true;
    case SBIG('GOFX'): f(GOFX); return true;
    case SBIG('WSFX'): f(WSFX); return true;
    case SBIG('WTFX'): f(WTFX); return true;
    case SBIG('2MUD'): f(_2MUD); return true;
    case SBIG('2LAV'): f(_2LAV); return true;
    case SBIG('2SAN'): f(_2SAN); return true;
    case SBIG('2PRJ'): f(_2PRJ); return true;
    case SBIG('DCFX'): f(DCFX); return true;
    case SBIG('DSHX'): f(DSHX); return true;
    case SBIG('DEFX'): f(DEFX); return true;
    case SBIG('ESFX'): f(ESFX); return true;
    case SBIG('SHFX'): f(SHFX); return true;
    case SBIG('BEFX'): f(BEFX); return true;
    case SBIG('WWFX'): f(WWFX); return true;
    case SBIG('TAFX'): f(TAFX); return true;
    case SBIG('GTFX'): f(GTFX); return true;
    case SBIG('SPFX'): f(SPFX); return true;
    case SBIG('FPFX'): f(FPFX); return true;
    case SBIG('FFFX'): f(FFFX); return true;
    case SBIG('PAFX'): f(PAFX); return true;
    case SBIG('BMFX'): f(BMFX); return true;
    case SBIG('BFFX'): f(BFFX); return true;
    case SBIG('PBFX'): f(PBFX); return true;
    case SBIG('IBFX'): f(IBFX); return true;
    case SBIG('4SVA'): f(_4SVA); return true;
    case SBIG('4RPR'): f(_4RPR); return true;
    case SBIG('4MTR'): f(_4MTR); return true;
    case SBIG('4PDS'): f(_4PDS); return true;
    case SBIG('4FLB'): f(_4FLB); return true;
    case SBIG('4DRN'): f(_4DRN); return true;
    case SBIG('4MRE'): f(_4MRE); return true;
    case SBIG('CZFX'): f(CZFX); return true;
    case SBIG('JZAS'): f(JZAS); return true;
    case SBIG('2ISE'): f(_2ISE); return true;
    case SBIG('2BSE'): f(_2BSE); return true;
    case SBIG('2ATB'): f(_2ATB); return true;
    case SBIG('2ATA'): f(_2ATA); return true;
    case SBIG('BSFX'): f(BSFX); return true;
    case SBIG('TSFX'): f(TSFX); return true;
    case SBIG('GSFX'): f(GSFX); return true;
    case SBIG('SSFX'): f(SSFX); return true;
    case SBIG('FSFX'): f(FSFX); return true;
    case SBIG('SFFX'): f(SFFX); return true;
    case SBIG('PSFX'): f(PSFX); return true;
    case SBIG('SBFX'): f(SBFX); return true;
    case SBIG('PBSX'): f(PBSX); return true;
    case SBIG('IBSX'): f(IBSX); return true;
    case SBIG('5SVA'): f(_5SVA); return true;
    case SBIG('5RPR'): f(_5RPR); return true;
    case SBIG('5MTR'): f(_5MTR); return true;
    case SBIG('5PDS'): f(_5PDS); return true;
    case SBIG('5FLB'): f(_5FLB); return true;
    case SBIG('5DRN'): f(_5DRN); return true;
    case SBIG('5MRE'): f(_5MRE); return true;
    case SBIG('JZPS'): f(JZPS); return true;
    case SBIG('4ISE'): f(_4ISE); return true;
    case SBIG('4BSE'): f(_4BSE); return true;
    case SBIG('4ATB'): f(_4ATB); return true;
    case SBIG('4ATA'): f(_4ATA); return true;
    case SBIG('BHFX'): f(BHFX); return true;
    case SBIG('WHFX'): f(WHFX); return true;
    case SBIG('THFX'): f(THFX); return true;
    case SBIG('GHFX'): f(GHFX); return true;
    case SBIG('FHFX'): f(FHFX); return true;
    case SBIG('HFFX'): f(HFFX); return true;
    case SBIG('PHFX'): f(PHFX); return true;
    case SBIG('MHFX'): f(MHFX); return true;
    case SBIG('HBFX'): f(HBFX); return true;
    case SBIG('PBHX'): f(PBHX); return true;
    case SBIG('IBHX'): f(IBHX); return true;
    case SBIG('6SVA'): f(_6SVA); return true;
    case SBIG('6RPR'): f(_6RPR); return true;
    case SBIG('6MTR'): f(_6MTR); return true;
    case SBIG('6PDS'): f(_6PDS); return true;
    case SBIG('6FLB'): f(_6FLB); return true;
    case SBIG('6DRN'): f(_6DRN); return true;
    case SBIG('6MRE'): f(_6MRE); return true;
    case SBIG('CHFX'): f(CHFX); return true;
    case SBIG('JZHS'): f(JZHS); return true;
    case SBIG('6ISE'): f(_6ISE); return true;
    case SBIG('6BSE'): f(_6BSE); return true;
    case SBIG('6ATB'): f(_6ATB); return true;
    case SBIG('6ATA'): f(_6ATA); return true;
    case SBIG('RNGE'): f(x30_RNGE); return true;
    case SBIG('FOFF'): f(x34_FOFF); return true;
    default: return false;
    }
  }
};
template <class IDType>
using CRSM = PPImpl<_CRSM<IDType>>;

template <class IDType>
bool ExtractCRSM(PAKEntryReadStream& rs, const hecl::ProjectPath& outPath);

template <class IDType>
bool WriteCRSM(const CRSM<IDType>& crsm, const hecl::ProjectPath& outPath);
} // namespace DataSpec::DNAParticle
