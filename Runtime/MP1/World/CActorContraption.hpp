#pragma once

#include <string_view>
#include <vector>

#include "Runtime/RetroTypes.hpp"
#include "Runtime/World/CDamageInfo.hpp"
#include "Runtime/World/CScriptActor.hpp"

namespace urde {
class CFlameThrower;
namespace MP1 {
class CActorContraption : public CScriptActor {
  /* AKA Why Zoid?!?!?!? */
  std::vector<std::pair<TUniqueId, std::string>> x2e8_children;
  TToken<CGenDescription> x300_flameThrowerGen;
  CAssetId x308_flameFxId;
  CDamageInfo x30c_dInfo;

public:
  CActorContraption(TUniqueId, std::string_view, const CEntityInfo&, const zeus::CTransform&, CModelData&&,
                    const zeus::CAABox&, const CMaterialList&, float, float, const CHealthInfo&,
                    const CDamageVulnerability&, const CActorParameters&, CAssetId, const CDamageInfo&, bool);

  void Accept(IVisitor& visitor) override;
  void AcceptScriptMsg(EScriptObjectMessage, TUniqueId, CStateManager&) override;
  void Think(float, CStateManager&) override;
  void DoUserAnimEvent(CStateManager&, const CInt32POINode&, EUserEventType, float dt) override;
  CFlameThrower* CreateFlameThrower(std::string_view, CStateManager&);
  void ResetFlameThrowers(CStateManager& mgr);
};
} // namespace MP1
} // namespace urde
