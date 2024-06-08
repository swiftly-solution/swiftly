#include "../../../core/scripting/generated/classes/GCAnimScriptBase.h"
#include "../core.h"

void SetupLuaClassGCAnimScriptBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimScriptBase>("CAnimScriptBase")
        .addProperty("IsValid", &GCAnimScriptBase::GetIsValid, &GCAnimScriptBase::SetIsValid)
        .endClass();
}