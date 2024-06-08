#include "../../../core/scripting/generated/classes/GCMorphSetData.h"
#include "../core.h"

void SetupLuaClassGCMorphSetData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMorphSetData>("CMorphSetData")
        .addProperty("Width", &GCMorphSetData::GetWidth, &GCMorphSetData::SetWidth)
        .addProperty("Height", &GCMorphSetData::GetHeight, &GCMorphSetData::SetHeight)
        .addProperty("BundleTypes", &GCMorphSetData::GetBundleTypes, &GCMorphSetData::SetBundleTypes)
        .addProperty("MorphDatas", &GCMorphSetData::GetMorphDatas, &GCMorphSetData::SetMorphDatas)
        .addProperty("FlexDesc", &GCMorphSetData::GetFlexDesc, &GCMorphSetData::SetFlexDesc)
        .addProperty("FlexControllers", &GCMorphSetData::GetFlexControllers, &GCMorphSetData::SetFlexControllers)
        .addProperty("FlexRules", &GCMorphSetData::GetFlexRules, &GCMorphSetData::SetFlexRules)
        .endClass();
}