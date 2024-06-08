#include "../../../core/scripting/generated/classes/GConstantInfo_t.h"
#include "../core.h"

void SetupLuaClassGConstantInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GConstantInfo_t>("ConstantInfo_t")
        .addProperty("Name", &GConstantInfo_t::GetName, &GConstantInfo_t::SetName)
        .addProperty("NameToken", &GConstantInfo_t::GetNameToken, &GConstantInfo_t::SetNameToken)
        .addProperty("Value", &GConstantInfo_t::GetValue, &GConstantInfo_t::SetValue)
        .endClass();
}