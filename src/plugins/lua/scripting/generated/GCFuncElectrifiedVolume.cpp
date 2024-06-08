#include "../../../core/scripting/generated/classes/GCFuncElectrifiedVolume.h"
#include "../core.h"

void SetupLuaClassGCFuncElectrifiedVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncElectrifiedVolume>("CFuncElectrifiedVolume")
        .addProperty("EffectName", &GCFuncElectrifiedVolume::GetEffectName, &GCFuncElectrifiedVolume::SetEffectName)
        .addProperty("EffectInterpenetrateName", &GCFuncElectrifiedVolume::GetEffectInterpenetrateName, &GCFuncElectrifiedVolume::SetEffectInterpenetrateName)
        .addProperty("EffectZapName", &GCFuncElectrifiedVolume::GetEffectZapName, &GCFuncElectrifiedVolume::SetEffectZapName)
        .addProperty("EffectSource", &GCFuncElectrifiedVolume::GetEffectSource, &GCFuncElectrifiedVolume::SetEffectSource)
        .endClass();
}