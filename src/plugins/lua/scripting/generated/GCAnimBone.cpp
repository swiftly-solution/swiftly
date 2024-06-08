#include "../../../core/scripting/generated/classes/GCAnimBone.h"
#include "../core.h"

void SetupLuaClassGCAnimBone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimBone>("CAnimBone")
        .addProperty("Name", &GCAnimBone::GetName, &GCAnimBone::SetName)
        .addProperty("Parent", &GCAnimBone::GetParent, &GCAnimBone::SetParent)
        .addProperty("Pos", &GCAnimBone::GetPos, &GCAnimBone::SetPos)
        .addProperty("Scale", &GCAnimBone::GetScale, &GCAnimBone::SetScale)
        .addProperty("Flags", &GCAnimBone::GetFlags, &GCAnimBone::SetFlags)
        .endClass();
}