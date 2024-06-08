#include "../../../core/scripting/generated/classes/GRelationshipOverride_t.h"
#include "../core.h"

void SetupLuaClassGRelationshipOverride_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRelationshipOverride_t>("RelationshipOverride_t")
        .addProperty("Entity", &GRelationshipOverride_t::GetEntity, &GRelationshipOverride_t::SetEntity)
        .addProperty("ClassType", &GRelationshipOverride_t::GetClassType, &GRelationshipOverride_t::SetClassType)
        .endClass();
}