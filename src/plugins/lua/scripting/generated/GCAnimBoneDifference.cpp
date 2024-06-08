#include "../../../core/scripting/generated/classes/GCAnimBoneDifference.h"
#include "../core.h"

void SetupLuaClassGCAnimBoneDifference(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimBoneDifference>("CAnimBoneDifference")
        .addProperty("Name", &GCAnimBoneDifference::GetName, &GCAnimBoneDifference::SetName)
        .addProperty("Parent", &GCAnimBoneDifference::GetParent, &GCAnimBoneDifference::SetParent)
        .addProperty("PosError", &GCAnimBoneDifference::GetPosError, &GCAnimBoneDifference::SetPosError)
        .addProperty("HasRotation", &GCAnimBoneDifference::GetHasRotation, &GCAnimBoneDifference::SetHasRotation)
        .addProperty("HasMovement", &GCAnimBoneDifference::GetHasMovement, &GCAnimBoneDifference::SetHasMovement)
        .endClass();
}