#include "../../../core/scripting/generated/classes/GCFuncVPhysicsClip.h"
#include "../core.h"

void SetupLuaClassGCFuncVPhysicsClip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncVPhysicsClip>("CFuncVPhysicsClip")
        .addProperty("Disabled", &GCFuncVPhysicsClip::GetDisabled, &GCFuncVPhysicsClip::SetDisabled)
        .endClass();
}