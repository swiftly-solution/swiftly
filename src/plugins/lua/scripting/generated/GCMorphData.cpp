#include "../../../core/scripting/generated/classes/GCMorphData.h"
#include "../core.h"

void SetupLuaClassGCMorphData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMorphData>("CMorphData")
        .addProperty("Name", &GCMorphData::GetName, &GCMorphData::SetName)
        .addProperty("MorphRectDatas", &GCMorphData::GetMorphRectDatas, &GCMorphData::SetMorphRectDatas)
        .endClass();
}