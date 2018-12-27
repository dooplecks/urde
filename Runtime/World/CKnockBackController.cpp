#include "CKnockBackController.hpp"
#include "CPatterned.hpp"
#include "CStateManager.hpp"
#include "Character/CPASAnimParmData.hpp"

namespace urde {

static const CKnockBackController::KnockBackParms KnockBackParmsTable[3][19][4] = {
    {
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 1.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 2.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 2.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Shock, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 0.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 2.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 2.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 5.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 5.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 8.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 4.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::ExplodeDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
    },
    {
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 2.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 1.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::Shock, 2.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 2.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 2.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Shock, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 0.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 2.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 2.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 5.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 5.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 8.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 8.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 4.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 4.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::Burn, 6.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::BurnDeath, 6.000000f, -1.000000f},
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::Burn, 6.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::BurnDeath, 6.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::BurnDeath, 6.000000f, -1.000000f},
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::Burn, 6.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Burn, 6.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::BurnDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::Burn, 6.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::LaggedBurnDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::LaggedBurnDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::PhazeOut, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
    },
    {
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 2.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 1.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::Shock, 2.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 2.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 2.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Shock, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Shock, 4.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 4.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::Shock, 4.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 2.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 2.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 2.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 2.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 4.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 4.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 2.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Freeze, 2.500000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::Burn, 6.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Burn, 6.000000f, -1.000000f},
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::Burn, 6.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::Burn, 6.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::Burn, 6.000000f, -1.000000f},
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::Burn, 6.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::Burn, 6.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::BurnDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::Burn, 6.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::KnockBack, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::None, EKnockBackAnimationFollowUp::None, 0.000000f, 0.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::LaggedBurnDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::LaggedBurnDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
        {
            {EKnockBackAnimationState::Flinch, EKnockBackAnimationFollowUp::None, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::PhazeOut, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Hurled, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
            {EKnockBackAnimationState::Fall, EKnockBackAnimationFollowUp::IceDeath, 0.000000f, -1.000000f},
        },
    },
};

CKnockBackController::CKnockBackController(EKnockBackVariant variant) : x0_variant(variant) {
  x81_24_autoResetImpulse = true;
  x81_25_enableFreeze = true;
  x81_27_enableBurn = true;
  x81_28_enableBurnDeath = true;
  x81_29_enableExplodeDeath = true;
  x81_30_enableLaggedBurnDeath = true;
  x81_31_ = true;
  x82_24_ = true;
  for (int i = 0; i < 5; ++i) {
    x24_.push_back(std::make_pair(0.f, FLT_MAX));
    x80_availableStates.set(i);
  }
}

static const float ImpulseDurationTable[] = {0.1f, 0.3f};

void CKnockBackController::ApplyImpulse(float dt, CPatterned& parent) {
  x60_impulseRemTime = std::max(0.f, x60_impulseRemTime - dt);
  if (!parent.GetMaterialList().HasMaterial(EMaterialTypes::Immovable) && x60_impulseRemTime > 0.f) {
    float remFac = 1.f;
    if (x20_impulseDurationIdx == 1)
      remFac = x60_impulseRemTime / ImpulseDurationTable[x20_impulseDurationIdx];
    parent.ApplyImpulseWR(
        parent.GetMoveToORImpulseWR(
            parent.GetTransform().transposeRotate(
                x50_impulseDir * (remFac * x5c_impulseMag * dt / ImpulseDurationTable[x20_impulseDurationIdx])),
            dt),
        zeus::CAxisAngle::sIdentity);
  }
}

bool CKnockBackController::TickDeferredTimer(float dt) {
  x68_deferRemTime -= dt;
  if (x14_deferWeaponType != EWeaponType::None)
    return x68_deferRemTime <= 0.f;
  return false;
}

EKnockBackCharacterState CKnockBackController::GetKnockBackCharacterState(CPatterned& parent) {
  if (parent.BodyController()->IsFrozen())
    return parent.IsAlive() ? EKnockBackCharacterState::FrozenAlive : EKnockBackCharacterState::FrozenDead;
  return parent.IsAlive() ? EKnockBackCharacterState::Alive : EKnockBackCharacterState::Dead;
}

void CKnockBackController::ValidateState(CPatterned& parent) {
  if (x4_activeParms.x0_animState < x18_minAnimState)
    x4_activeParms.x0_animState = x18_minAnimState;
  else if (x4_activeParms.x0_animState > x1c_maxAnimState)
    x4_activeParms.x0_animState = x1c_maxAnimState;

  EKnockBackAnimationState useState = EKnockBackAnimationState::Invalid;
  if (parent.IsAlive()) {
    if (parent.BodyController()->HasBodyState(pas::EAnimationState::Hurled) && x80_availableStates.test(3) &&
        x4_activeParms.x0_animState >= EKnockBackAnimationState::Hurled) {
      useState = EKnockBackAnimationState::Hurled;
    } else if (parent.BodyController()->HasBodyState(pas::EAnimationState::KnockBack) && x80_availableStates.test(2) &&
               x4_activeParms.x0_animState >= EKnockBackAnimationState::KnockBack) {
      useState = EKnockBackAnimationState::KnockBack;
    } else if (parent.BodyController()->HasBodyState(pas::EAnimationState::AdditiveFlinch) &&
               x80_availableStates.test(1) && x4_activeParms.x0_animState >= EKnockBackAnimationState::Flinch) {
      useState = EKnockBackAnimationState::Flinch;
    }
  } else {
    if (parent.BodyController()->HasBodyState(pas::EAnimationState::Fall) && x80_availableStates.test(4) &&
        (x4_activeParms.x0_animState >= EKnockBackAnimationState::Fall ||
         (!parent.BodyController()->HasBodyState(pas::EAnimationState::Hurled) &&
          x4_activeParms.x0_animState >= EKnockBackAnimationState::Hurled))) {
      useState = EKnockBackAnimationState::Fall;
    } else if (parent.BodyController()->HasBodyState(pas::EAnimationState::Hurled) && x80_availableStates.test(3) &&
               x4_activeParms.x0_animState >= EKnockBackAnimationState::Hurled) {
      useState = EKnockBackAnimationState::Hurled;
    }
  }

  x4_activeParms.x0_animState =
      (useState != EKnockBackAnimationState::Invalid) ? useState : EKnockBackAnimationState::None;

  bool disableFollowup = false;
  switch (x4_activeParms.x4_animFollowup) {
  case EKnockBackAnimationFollowUp::Freeze:
    disableFollowup = !x81_25_enableFreeze;
    break;
  case EKnockBackAnimationFollowUp::Shock:
    disableFollowup = !x81_26_enableShock;
    break;
  case EKnockBackAnimationFollowUp::Burn:
    disableFollowup = !x81_27_enableBurn;
    break;
  case EKnockBackAnimationFollowUp::ExplodeDeath:
    disableFollowup = !x81_29_enableExplodeDeath;
    break;
  case EKnockBackAnimationFollowUp::IceDeath:
    disableFollowup = !x81_29_enableExplodeDeath;
    break;
  case EKnockBackAnimationFollowUp::BurnDeath:
    disableFollowup = !x81_28_enableBurnDeath;
    break;
  case EKnockBackAnimationFollowUp::LaggedBurnDeath:
    disableFollowup = !x81_30_enableLaggedBurnDeath;
    break;
  default:
    break;
  }

  if (disableFollowup) {
    x4_activeParms.x4_animFollowup = EKnockBackAnimationFollowUp::None;
    x4_activeParms.x8_followupDuration = 0.f;
  }
}

float CKnockBackController::CalculateExtraHurlVelocity(CStateManager& mgr, float magnitude, float kbResistance) {
  if (magnitude > kbResistance)
    return (1.1f - 0.2f * mgr.GetActiveRandom()->Float()) * 2.f * (magnitude - kbResistance);
  return 0.f;
}

void CKnockBackController::DoKnockBackAnimation(const zeus::CVector3f& backVec, CStateManager& mgr, CPatterned& parent,
                                                float magnitude) {
  switch (x4_activeParms.x0_animState) {
  case EKnockBackAnimationState::Hurled: {
    float hurlVel = 5.f;
    if (CHealthInfo* hInfo = parent.HealthInfo(mgr))
      hurlVel += CalculateExtraHurlVelocity(mgr, magnitude, hInfo->GetKnockbackResistance());
    hurlVel = std::sqrt(parent.GetGravityConstant() * 0.5f * hurlVel);
    zeus::CVector3f backUpVec = backVec + backVec.magnitude() * zeus::CVector3f::skUp;
    if (backUpVec.canBeNormalized()) {
      parent.BodyController()->GetCommandMgr().DeliverCmd(CBCHurledCmd(-backVec, backUpVec.normalized() * hurlVel));
      parent.SetMomentumWR({0.f, 0.f, parent.GetGravityConstant() * -parent.GetMass()});
    }
    break;
  }
  case EKnockBackAnimationState::Fall: {
    parent.BodyController()->GetCommandMgr().DeliverCmd(CBCKnockDownCmd(-backVec, x7c_severity));
    break;
  }
  case EKnockBackAnimationState::KnockBack: {
    parent.BodyController()->GetCommandMgr().DeliverCmd(CBCKnockBackCmd(-backVec, x7c_severity));
    break;
  }
  case EKnockBackAnimationState::Flinch: {
    std::pair<float, s32> bestAnim =
        parent.BodyController()->GetPASDatabase().FindBestAnimation(CPASAnimParmData(23), *mgr.GetActiveRandom(), -1);
    if (bestAnim.first > 0.f) {
      parent.ModelData()->AnimationData()->AddAdditiveAnimation(bestAnim.second, 1.f, false, true);
      x64_flinchRemTime =
          std::max(parent.ModelData()->AnimationData()->GetAnimationDuration(bestAnim.second), x64_flinchRemTime);
    }
    break;
  }
  default:
    break;
  }
}

void CKnockBackController::ResetKnockBackImpulse(CPatterned& parent, const zeus::CVector3f& backVec, float magnitude) {
  if (x81_24_autoResetImpulse && x4_activeParms.x0_animState == EKnockBackAnimationState::KnockBack &&
      x4_activeParms.x4_animFollowup != EKnockBackAnimationFollowUp::Freeze) {
    x50_impulseDir = backVec.canBeNormalized() ? backVec.normalized() : -parent.GetTransform().basis[1];
    if (x60_impulseRemTime <= 0.f)
      x5c_impulseMag = magnitude;
    else
      x5c_impulseMag += magnitude * (1.f - x60_impulseRemTime / ImpulseDurationTable[x20_impulseDurationIdx]);
    x60_impulseRemTime = ImpulseDurationTable[x20_impulseDurationIdx];
  }
}

void CKnockBackController::DoDeferredKnockBack(CStateManager& mgr, CPatterned& parent) {
  if (x14_deferWeaponType == EWeaponType::Wave) {
    x4_activeParms = KnockBackParmsTable[int(x0_variant)][int(EKnockBackWeaponType::WaveComboedDirect)]
                                        [int(GetKnockBackCharacterState(parent))];
    ValidateState(parent);
    if (CHealthInfo* hInfo = parent.HealthInfo(mgr)) {
      zeus::CVector3f backVec = -parent.GetTransform().basis[1];
      DoKnockBackAnimation(backVec, mgr, parent, 10.f);
      ResetKnockBackImpulse(parent, backVec, 2.f);
      x82_25_inDeferredKnockBack = true;
      parent.KnockBack(backVec, mgr, CDamageInfo({x14_deferWeaponType, false, true, false}, 0.f, 0.f, 10.f),
                       EKnockBackType::Radius, x82_25_inDeferredKnockBack, 10.f);
      x82_25_inDeferredKnockBack = false;
    }
  }
  x68_deferRemTime = 0.f;
  x4_activeParms = KnockBackParms{};
  x14_deferWeaponType = EWeaponType::None;
}

void CKnockBackController::sub80233d40(int i, float f1, float f2) {
  if (i < 0 || i > 4)
    return;
  x24_[i] = std::make_pair(f1, f2);
}

void CKnockBackController::SetAutoResetImpulse(bool b) {
  x81_24_autoResetImpulse = b;
  if (!b) {
    x5c_impulseMag = 0.f;
    x60_impulseRemTime = 0.f;
  }
}

void CKnockBackController::Update(float dt, CStateManager& mgr, CPatterned& parent) {
  ApplyImpulse(dt, parent);
  x64_flinchRemTime -= dt;
  if (TickDeferredTimer(dt))
    DoDeferredKnockBack(mgr, parent);
  if (x82_26_locomotionDuringElectrocution && parent.BodyController()->IsElectrocuting())
    parent.BodyController()->GetCommandMgr().DeliverCmd(CBodyStateCmd(EBodyStateCmd::Locomotion));
}

EKnockBackWeaponType CKnockBackController::GetKnockBackWeaponType(const CDamageInfo& info, EWeaponType wType,
                                                                  EKnockBackType type) {
  int stacking = 0;
  if (info.GetWeaponMode().IsCharged())
    stacking = 1;
  else if (info.GetWeaponMode().IsComboed())
    stacking = 2;
  if (wType > EWeaponType::Phazon)
    return EKnockBackWeaponType::Invalid;
  switch (wType) {
  case EWeaponType::Power:
    return EKnockBackWeaponType(type != EKnockBackType::Direct ? stacking : stacking + 1);
  case EWeaponType::Ice:
    return EKnockBackWeaponType(type != EKnockBackType::Direct ? stacking + 8 : stacking + 9);
  case EWeaponType::Wave:
    return EKnockBackWeaponType(stacking + 4);
  case EWeaponType::Plasma:
    return EKnockBackWeaponType(stacking + 12);
  case EWeaponType::Bomb:
    return EKnockBackWeaponType::Bomb;
  case EWeaponType::PowerBomb:
    return EKnockBackWeaponType::PowerBomb;
  case EWeaponType::Missile:
    return EKnockBackWeaponType::Missile;
  case EWeaponType::Phazon:
    return EKnockBackWeaponType::Phazon;
  default:
    return EKnockBackWeaponType::Invalid;
  }
}

void CKnockBackController::SelectDamageState(CPatterned& parent, const CDamageInfo& info, EWeaponType wType,
                                             EKnockBackType type) {
  EKnockBackWeaponType weaponType = GetKnockBackWeaponType(info, wType, type);
  if (weaponType != EKnockBackWeaponType::Invalid) {
    x4_activeParms = KnockBackParmsTable[int(x0_variant)][int(weaponType)][int(GetKnockBackCharacterState(parent))];
    ValidateState(parent);
  }
}

void CKnockBackController::KnockBack(const zeus::CVector3f& backVec, CStateManager& mgr, CPatterned& parent,
                                     const CDamageInfo& info, EKnockBackType type, float magnitude) {
  if (!x82_25_inDeferredKnockBack) {
    zeus::CVector3f vec(backVec.toVec2f());
    if (!vec.isMagnitudeSafe())
      vec = -parent.GetTransform().basis[1];
    SelectDamageState(parent, info, info.GetWeaponMode().GetType(), type);
    DoKnockBackAnimation(vec, mgr, parent, magnitude);
    ResetKnockBackImpulse(parent, vec, 2.f);
  }
}

} // namespace urde
