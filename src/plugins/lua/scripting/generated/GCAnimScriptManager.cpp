#include "../../../core/scripting/generated/classes/GCAnimScriptManager.h"
#include "../core.h"

void SetupLuaClassGCAnimScriptManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimScriptManager>("CAnimScriptManager")
        .addProperty("ScriptInfo", &GCAnimScriptManager::GetScriptInfo, &GCAnimScriptManager::SetScriptInfo)
        .endClass();
}