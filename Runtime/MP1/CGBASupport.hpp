#pragma once

#include <memory>

#include "Runtime/GCNTypes.hpp"
#include "Runtime/CDvdFile.hpp"

namespace urde::MP1 {

class CGBASupport : public CDvdFile {
public:
  enum class EPhase {
    LoadClientPad,
    Standby,
    StartProbeTimeout,
    PollProbe,
    StartJoyBusBoot,
    PollJoyBusBoot,
    DataTransfer,
    Complete,
    Failed
  };

private:
  u32 x28_fileSize;
  std::unique_ptr<u8[]> x2c_buffer;
  EPhase x34_phase = EPhase::LoadClientPad;
  float x38_timeout = 0.f;
  std::shared_ptr<IDvdRequest> x30_dvdReq;
  u8 x3c_status = 0;
  u32 x40_siChan = -1;
  bool x44_fusionLinked = false;
  bool x45_fusionBeat = false;

  static u8 CalculateFusionJBusChecksum(const u8* data, size_t len);

public:
  static void Initialize();
  static void GlobalPoll();

  CGBASupport();
  ~CGBASupport();
  bool PollResponse();
  void Update(float dt);
  bool IsReady();
  void InitializeSupport();
  void StartLink();
  EPhase GetPhase() const { return x34_phase; }
  bool IsFusionLinked() const { return x44_fusionLinked; }
  bool IsFusionBeat() const { return x45_fusionBeat; }
};

} // namespace urde::MP1
