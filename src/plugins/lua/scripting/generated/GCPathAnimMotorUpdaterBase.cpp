#include "../../../core/scripting/generated/classes/GCPathAnimMotorUpdaterBase.h"
#include "../core.h"

void SetupLuaClassGCPathAnimMotorUpdaterBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathAnimMotorUpdaterBase>("CPathAnimMotorUpdaterBase")
        .addProperty("LockToPath", &GCPathAnimMotorUpdaterBase::GetLockToPath, &GCPathAnimMotorUpdaterBase::SetLockToPath)
        .endClass();
}