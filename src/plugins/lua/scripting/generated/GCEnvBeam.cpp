#include "../../../core/scripting/generated/classes/GCEnvBeam.h"
#include "../core.h"

void SetupLuaClassGCEnvBeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvBeam>("CEnvBeam")
        .addProperty("Active", &GCEnvBeam::GetActive, &GCEnvBeam::SetActive)
        .addProperty("StartEntity", &GCEnvBeam::GetStartEntity, &GCEnvBeam::SetStartEntity)
        .addProperty("EndEntity", &GCEnvBeam::GetEndEntity, &GCEnvBeam::SetEndEntity)
        .addProperty("Life", &GCEnvBeam::GetLife, &GCEnvBeam::SetLife)
        .addProperty("BoltWidth", &GCEnvBeam::GetBoltWidth, &GCEnvBeam::SetBoltWidth)
        .addProperty("NoiseAmplitude", &GCEnvBeam::GetNoiseAmplitude, &GCEnvBeam::SetNoiseAmplitude)
        .addProperty("Speed", &GCEnvBeam::GetSpeed, &GCEnvBeam::SetSpeed)
        .addProperty("Restrike", &GCEnvBeam::GetRestrike, &GCEnvBeam::SetRestrike)
        .addProperty("SpriteName", &GCEnvBeam::GetSpriteName, &GCEnvBeam::SetSpriteName)
        .addProperty("FrameStart", &GCEnvBeam::GetFrameStart, &GCEnvBeam::SetFrameStart)
        .addProperty("EndPointWorld", &GCEnvBeam::GetEndPointWorld, &GCEnvBeam::SetEndPointWorld)
        .addProperty("EndPointRelative", &GCEnvBeam::GetEndPointRelative, &GCEnvBeam::SetEndPointRelative)
        .addProperty("Radius", &GCEnvBeam::GetRadius, &GCEnvBeam::SetRadius)
        .addProperty("TouchType", &GCEnvBeam::GetTouchType, &GCEnvBeam::SetTouchType)
        .addProperty("FilterName", &GCEnvBeam::GetFilterName, &GCEnvBeam::SetFilterName)
        .addProperty("Filter", &GCEnvBeam::GetFilter, &GCEnvBeam::SetFilter)
        .addProperty("Decal", &GCEnvBeam::GetDecal, &GCEnvBeam::SetDecal)
        .addProperty("OnTouchedByEntity", &GCEnvBeam::GetOnTouchedByEntity, &GCEnvBeam::SetOnTouchedByEntity)
        .endClass();
}