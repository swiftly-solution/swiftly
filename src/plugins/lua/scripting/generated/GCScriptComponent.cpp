#include "../../../core/scripting/generated/classes/GCScriptComponent.h"
#include "../core.h"

void SetupLuaClassGCScriptComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptComponent>("CScriptComponent")
        .addProperty("ScriptClassName", &GCScriptComponent::GetScriptClassName, &GCScriptComponent::SetScriptClassName)
        .endClass();
}