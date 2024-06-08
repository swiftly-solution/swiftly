#include "../../../core/scripting/generated/classes/GRelationship_t.h"
#include "../core.h"

void SetupLuaClassGRelationship_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRelationship_t>("Relationship_t")
        .addProperty("Disposition", &GRelationship_t::GetDisposition, &GRelationship_t::SetDisposition)
        .addProperty("Priority", &GRelationship_t::GetPriority, &GRelationship_t::SetPriority)
        .endClass();
}