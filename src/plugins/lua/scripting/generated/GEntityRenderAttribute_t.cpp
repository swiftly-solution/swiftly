#include "../../../core/scripting/generated/classes/GEntityRenderAttribute_t.h"
#include "../core.h"

void SetupLuaClassGEntityRenderAttribute_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntityRenderAttribute_t>("EntityRenderAttribute_t")
        .addProperty("ID", &GEntityRenderAttribute_t::GetID, &GEntityRenderAttribute_t::SetID)
        .addProperty("Values", &GEntityRenderAttribute_t::GetValues, &GEntityRenderAttribute_t::SetValues)
        .endClass();
}