#include "../../../core/scripting/generated/classes/GCRuleEntity.h"
#include "../core.h"

void SetupLuaClassGCRuleEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRuleEntity>("CRuleEntity")
        .addProperty("Master", &GCRuleEntity::GetMaster, &GCRuleEntity::SetMaster)
        .endClass();
}