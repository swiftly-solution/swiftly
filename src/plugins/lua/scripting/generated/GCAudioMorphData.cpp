#include "../../../core/scripting/generated/classes/GCAudioMorphData.h"
#include "../core.h"

void SetupLuaClassGCAudioMorphData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAudioMorphData>("CAudioMorphData")
        .addProperty("Times", &GCAudioMorphData::GetTimes, &GCAudioMorphData::SetTimes)
        .addProperty("NameHashCodes", &GCAudioMorphData::GetNameHashCodes, &GCAudioMorphData::SetNameHashCodes)
        .addProperty("NameStrings", &GCAudioMorphData::GetNameStrings, &GCAudioMorphData::SetNameStrings)
        .addProperty("EaseIn", &GCAudioMorphData::GetEaseIn, &GCAudioMorphData::SetEaseIn)
        .addProperty("EaseOut", &GCAudioMorphData::GetEaseOut, &GCAudioMorphData::SetEaseOut)
        .endClass();
}