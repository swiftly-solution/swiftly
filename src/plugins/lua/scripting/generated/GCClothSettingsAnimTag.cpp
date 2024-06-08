#include "../../../core/scripting/generated/classes/GCClothSettingsAnimTag.h"
#include "../core.h"

void SetupLuaClassGCClothSettingsAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCClothSettingsAnimTag>("CClothSettingsAnimTag")
        .addProperty("Stiffness", &GCClothSettingsAnimTag::GetStiffness, &GCClothSettingsAnimTag::SetStiffness)
        .addProperty("EaseIn", &GCClothSettingsAnimTag::GetEaseIn, &GCClothSettingsAnimTag::SetEaseIn)
        .addProperty("EaseOut", &GCClothSettingsAnimTag::GetEaseOut, &GCClothSettingsAnimTag::SetEaseOut)
        .addProperty("VertexSet", &GCClothSettingsAnimTag::GetVertexSet, &GCClothSettingsAnimTag::SetVertexSet)
        .endClass();
}