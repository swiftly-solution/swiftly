#include "../../../core/scripting/generated/classes/GCPhysSurfacePropertiesAudio.h"
#include "../core.h"

void SetupLuaClassGCPhysSurfacePropertiesAudio(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysSurfacePropertiesAudio>("CPhysSurfacePropertiesAudio")
        .addProperty("Reflectivity", &GCPhysSurfacePropertiesAudio::GetReflectivity, &GCPhysSurfacePropertiesAudio::SetReflectivity)
        .addProperty("HardnessFactor", &GCPhysSurfacePropertiesAudio::GetHardnessFactor, &GCPhysSurfacePropertiesAudio::SetHardnessFactor)
        .addProperty("RoughnessFactor", &GCPhysSurfacePropertiesAudio::GetRoughnessFactor, &GCPhysSurfacePropertiesAudio::SetRoughnessFactor)
        .addProperty("RoughThreshold", &GCPhysSurfacePropertiesAudio::GetRoughThreshold, &GCPhysSurfacePropertiesAudio::SetRoughThreshold)
        .addProperty("HardThreshold", &GCPhysSurfacePropertiesAudio::GetHardThreshold, &GCPhysSurfacePropertiesAudio::SetHardThreshold)
        .addProperty("HardVelocityThreshold", &GCPhysSurfacePropertiesAudio::GetHardVelocityThreshold, &GCPhysSurfacePropertiesAudio::SetHardVelocityThreshold)
        .addProperty("StaticImpactVolume", &GCPhysSurfacePropertiesAudio::GetStaticImpactVolume, &GCPhysSurfacePropertiesAudio::SetStaticImpactVolume)
        .addProperty("OcclusionFactor", &GCPhysSurfacePropertiesAudio::GetOcclusionFactor, &GCPhysSurfacePropertiesAudio::SetOcclusionFactor)
        .endClass();
}