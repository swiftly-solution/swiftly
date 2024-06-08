#include "../../../core/scripting/generated/classes/GCPoseHandle.h"
#include "../core.h"

void SetupLuaClassGCPoseHandle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPoseHandle>("CPoseHandle")
        .addProperty("Index", &GCPoseHandle::GetIndex, &GCPoseHandle::SetIndex)
        .addProperty("Type", &GCPoseHandle::GetType, &GCPoseHandle::SetType)
        .endClass();
}