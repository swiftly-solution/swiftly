#include "../../../core/scripting/generated/classes/GMoodAnimation_t.h"
#include "../core.h"

void SetupLuaClassGMoodAnimation_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMoodAnimation_t>("MoodAnimation_t")
        .addProperty("Name", &GMoodAnimation_t::GetName, &GMoodAnimation_t::SetName)
        .addProperty("Weight", &GMoodAnimation_t::GetWeight, &GMoodAnimation_t::SetWeight)
        .endClass();
}