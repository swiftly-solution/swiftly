#include "../../../core/scripting/generated/classes/Gmagnetted_objects_t.h"
#include "../core.h"

void SetupLuaClassGmagnetted_objects_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gmagnetted_objects_t>("magnetted_objects_t")
        .addProperty("Entity", &Gmagnetted_objects_t::GetEntity, &Gmagnetted_objects_t::SetEntity)
        .endClass();
}