#include "../../../core/scripting/generated/classes/GCEntityInstance.h"
#include "../core.h"

void SetupLuaClassGCEntityInstance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityInstance>("CEntityInstance")
        .addProperty("PrivateVScripts", &GCEntityInstance::GetPrivateVScripts, &GCEntityInstance::SetPrivateVScripts)
        .addProperty("Entity", &GCEntityInstance::GetEntity, &GCEntityInstance::SetEntity)
        .addProperty("CScriptComponent", &GCEntityInstance::GetCScriptComponent, &GCEntityInstance::SetCScriptComponent)
        .addProperty("VisibleinPVS", &GCEntityInstance::GetVisibleinPVS, &GCEntityInstance::SetVisibleinPVS)
        .endClass();
}