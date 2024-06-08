#include "../../../core/scripting/generated/classes/GCSingleplayRules.h"
#include "../core.h"

void SetupLuaClassGCSingleplayRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSingleplayRules>("CSingleplayRules")
        .addProperty("SinglePlayerGameEnding", &GCSingleplayRules::GetSinglePlayerGameEnding, &GCSingleplayRules::SetSinglePlayerGameEnding)
        .endClass();
}