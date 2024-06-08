#include "../../../core/scripting/generated/classes/GCRulePointEntity.h"
#include "../core.h"

void SetupLuaClassGCRulePointEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRulePointEntity>("CRulePointEntity")
        .addProperty("Score", &GCRulePointEntity::GetScore, &GCRulePointEntity::SetScore)
        .endClass();
}