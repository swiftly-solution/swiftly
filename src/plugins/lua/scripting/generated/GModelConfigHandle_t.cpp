#include "../../../core/scripting/generated/classes/GModelConfigHandle_t.h"
#include "../core.h"

void SetupLuaClassGModelConfigHandle_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GModelConfigHandle_t>("ModelConfigHandle_t")
        .addProperty("Value", &GModelConfigHandle_t::GetValue, &GModelConfigHandle_t::SetValue)
        .endClass();
}