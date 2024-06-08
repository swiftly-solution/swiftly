#include "../../../core/scripting/generated/classes/GCAnimParamHandle.h"
#include "../core.h"

void SetupLuaClassGCAnimParamHandle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimParamHandle>("CAnimParamHandle")
        .addProperty("Type", &GCAnimParamHandle::GetType, &GCAnimParamHandle::SetType)
        .addProperty("Index", &GCAnimParamHandle::GetIndex, &GCAnimParamHandle::SetIndex)
        .endClass();
}