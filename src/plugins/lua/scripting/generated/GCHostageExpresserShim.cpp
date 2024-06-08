#include "../../../core/scripting/generated/classes/GCHostageExpresserShim.h"
#include "../core.h"

void SetupLuaClassGCHostageExpresserShim(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostageExpresserShim>("CHostageExpresserShim")
        .addProperty("Expresser", &GCHostageExpresserShim::GetExpresser, &GCHostageExpresserShim::SetExpresser)
        .endClass();
}