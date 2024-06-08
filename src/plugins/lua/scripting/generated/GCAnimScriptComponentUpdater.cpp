#include "../../../core/scripting/generated/classes/GCAnimScriptComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCAnimScriptComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimScriptComponentUpdater>("CAnimScriptComponentUpdater")
        .addProperty("Script", &GCAnimScriptComponentUpdater::GetScript, &GCAnimScriptComponentUpdater::SetScript)
        .endClass();
}