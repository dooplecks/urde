#pragma once

#include <memory>
#include <utility>
#include <vector>

#include "Runtime/IOStreams.hpp"
#include "Runtime/Character/IMetaAnim.hpp"

namespace urde {

class CMetaAnimRandom : public IMetaAnim {
  using RandomData = std::vector<std::pair<std::shared_ptr<IMetaAnim>, u32>>;
  RandomData x4_randomData;
  static RandomData CreateRandomData(CInputStream& in);

public:
  CMetaAnimRandom(CInputStream& in);
  EMetaAnimType GetType() const override { return EMetaAnimType::Random; }

  void GetUniquePrimitives(std::set<CPrimitive>& primsOut) const override;
  std::shared_ptr<CAnimTreeNode> VGetAnimationTree(const CAnimSysContext& animSys,
                                                   const CMetaAnimTreeBuildOrders& orders) const override;
};

} // namespace urde
