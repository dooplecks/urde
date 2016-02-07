#ifndef __RETRO_CCOLORELEMENT_HPP__
#define __RETRO_CCOLORELEMENT_HPP__

#include "IElement.hpp"

namespace Retro
{

class CCEKeyframeEmitter : public CColorElement
{
    u32 x4_percent;
    u32 x8_unk1;
    bool xc_loop;
    bool xd_unk2;
    u32 x10_loopEnd;
    u32 x14_loopStart;
    std::vector<Zeus::CColor> x18_keys;
public:
    CCEKeyframeEmitter(CInputStream& in);
    bool GetValue(int frame, Zeus::CColor& colorOut) const;
};

class CCEConstant : public CColorElement
{
    std::unique_ptr<CRealElement> x4_a;
    std::unique_ptr<CRealElement> x8_b;
    std::unique_ptr<CRealElement> xc_c;
    std::unique_ptr<CRealElement> x10_d;
public:
    CCEConstant(CRealElement* a, CRealElement* b, CRealElement* c, CRealElement* d)
    : x4_a(a), x8_b(b), xc_c(c), x10_d(d) {}
    bool GetValue(int frame, Zeus::CColor& colorOut) const;
};

class CCEFastConstant : public CColorElement
{
    Zeus::CColor x4_val;
public:
    CCEFastConstant(float a, float b, float c, float d)
    : x4_val(a, b, c, d) {}
    bool GetValue(int frame, Zeus::CColor& colorOut) const;
};

class CCETimeChain : public CColorElement
{
    std::unique_ptr<CColorElement> x4_a;
    std::unique_ptr<CColorElement> x8_b;
    std::unique_ptr<CIntElement> xc_c;
public:
    CCETimeChain(CColorElement* a, CColorElement* b, CIntElement* c)
    : x4_a(a), x8_b(b), xc_c(c) {}
    bool GetValue(int frame, Zeus::CColor& colorOut) const;
};

class CCEFadeEnd : public CColorElement
{
    std::unique_ptr<CColorElement> x4_a;
    std::unique_ptr<CColorElement> x8_b;
    std::unique_ptr<CRealElement> xc_c;
    std::unique_ptr<CRealElement> x10_d;
public:
    CCEFadeEnd(CColorElement* a, CColorElement* b, CRealElement* c, CRealElement* d)
    : x4_a(a), x8_b(b), xc_c(c), x10_d(d) {}
    bool GetValue(int frame, Zeus::CColor& colorOut) const;
};

class CCEFade : public CColorElement
{
    std::unique_ptr<CColorElement> x4_a;
    std::unique_ptr<CColorElement> x8_b;
    std::unique_ptr<CRealElement> xc_c;
public:
    CCEFade(CColorElement* a, CColorElement* b, CRealElement* c)
    : x4_a(a), x8_b(b), xc_c(c) {}
    bool GetValue(int frame, Zeus::CColor& colorOut) const;
};

class CCEPulse : public CColorElement
{
    std::unique_ptr<CIntElement> x4_a;
    std::unique_ptr<CIntElement> x8_b;
    std::unique_ptr<CColorElement> xc_c;
    std::unique_ptr<CColorElement> x10_d;
public:
    CCEPulse(CIntElement* a, CIntElement* b, CColorElement* c, CColorElement* d)
    : x4_a(a), x8_b(b), xc_c(c), x10_d(d) {}
    bool GetValue(int frame, Zeus::CColor& colorOut) const;
};

}

#endif // __RETRO_CCOLORELEMENT_HPP__