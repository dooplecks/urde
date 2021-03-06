#pragma once

#include "DataSpec/DNACommon/DNACommon.hpp"
#include "DataSpec/DNACommon/GX.hpp"
#include "../DNAMP1/CMDLMaterials.hpp"
#include "DNAMP2.hpp"

namespace DataSpec::DNAMP2 {

/* Structurally identical to DNAMP1::MaterialSet except unk0 and unk1 fields */
struct MaterialSet : BigDNA {
  static constexpr bool OneSection() { return false; }

  AT_DECL_DNA
  DNAMP1::MaterialSet::MaterialSetHead head;

  struct Material : BigDNA {
    AT_DECL_DNA
    using Flags = DNAMP1::MaterialSet::Material::Flags;
    Flags flags;
    const Flags& getFlags() const { return flags; }

    Value<atUint32> textureCount;
    Vector<atUint32, AT_DNA_COUNT(textureCount)> textureIdxs;
    using VAFlags = DNAMP1::MaterialSet::Material::VAFlags;
    DNAMP1::MaterialSet::Material::VAFlags vaFlags;
    const VAFlags& getVAFlags() const { return vaFlags; }
    Value<atUint32> unk0; /* MP2 only */
    Value<atUint32> unk1; /* MP2 only */
    Value<atUint32> uniqueIdx;

    Vector<atUint32, AT_DNA_COUNT(flags.konstValuesEnabled())> konstCount;
    Vector<GX::Color, AT_DNA_COUNT(flags.konstValuesEnabled() ? konstCount[0] : 0)> konstColors;

    using BlendFactor = GX::BlendFactor;
    Value<BlendFactor> blendDstFac;
    Value<BlendFactor> blendSrcFac;
    Vector<atUint32, AT_DNA_COUNT(flags.samusReflectionIndirectTexture())> indTexSlot;

    Value<atUint32> colorChannelCount;
    Vector<DNAMP1::MaterialSet::Material::ColorChannel, AT_DNA_COUNT(colorChannelCount)> colorChannels;

    Value<atUint32> tevStageCount;
    Vector<DNAMP1::MaterialSet::Material::TEVStage, AT_DNA_COUNT(tevStageCount)> tevStages;
    Vector<DNAMP1::MaterialSet::Material::TEVStageTexInfo, AT_DNA_COUNT(tevStageCount)> tevStageTexInfo;

    Value<atUint32> tcgCount;
    Vector<DNAMP1::MaterialSet::Material::TexCoordGen, AT_DNA_COUNT(tcgCount)> tcgs;

    Value<atUint32> uvAnimsSize;
    Value<atUint32> uvAnimsCount;
    Vector<DNAMP1::MaterialSet::Material::UVAnimation, AT_DNA_COUNT(uvAnimsCount)> uvAnims;
  };
  Vector<Material, AT_DNA_COUNT(head.materialCount)> materials;

  static void RegisterMaterialProps(hecl::blender::PyOutStream& out) {
    DNAMP1::MaterialSet::RegisterMaterialProps(out);
  }
  static void ConstructMaterial(hecl::blender::PyOutStream& out, const MaterialSet::Material& material,
                                unsigned groupIdx, unsigned matIdx);

  void readToBlender(hecl::blender::PyOutStream& os, const PAKRouter<PAKBridge>& pakRouter,
                     const PAKRouter<PAKBridge>::EntryType& entry, unsigned setIdx) {
    DNACMDL::ReadMaterialSetToBlender_1_2(os, *this, pakRouter, entry, setIdx);
  }

  void ensureTexturesExtracted(PAKRouter<PAKBridge>& pakRouter) const { head.ensureTexturesExtracted(pakRouter); }
};

} // namespace DataSpec::DNAMP2
