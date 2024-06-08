#include "../../../core/scripting/generated/classes/GCAnimationGroup.h"
#include "../core.h"

void SetupLuaClassGCAnimationGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGroup>("CAnimationGroup")
        .addProperty("Flags", &GCAnimationGroup::GetFlags, &GCAnimationGroup::SetFlags)
        .addProperty("Name", &GCAnimationGroup::GetName, &GCAnimationGroup::SetName)
        .addProperty("DecodeKey", &GCAnimationGroup::GetDecodeKey, &GCAnimationGroup::SetDecodeKey)
        .addProperty("Scripts", &GCAnimationGroup::GetScripts, &GCAnimationGroup::SetScripts)
        .endClass();
}