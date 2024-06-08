#include "../../../core/scripting/generated/classes/GEntityIOConnectionData_t.h"
#include "../core.h"

void SetupLuaClassGEntityIOConnectionData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntityIOConnectionData_t>("EntityIOConnectionData_t")
        .addProperty("OutputName", &GEntityIOConnectionData_t::GetOutputName, &GEntityIOConnectionData_t::SetOutputName)
        .addProperty("TargetType", &GEntityIOConnectionData_t::GetTargetType, &GEntityIOConnectionData_t::SetTargetType)
        .addProperty("TargetName", &GEntityIOConnectionData_t::GetTargetName, &GEntityIOConnectionData_t::SetTargetName)
        .addProperty("InputName", &GEntityIOConnectionData_t::GetInputName, &GEntityIOConnectionData_t::SetInputName)
        .addProperty("OverrideParam", &GEntityIOConnectionData_t::GetOverrideParam, &GEntityIOConnectionData_t::SetOverrideParam)
        .addProperty("Delay", &GEntityIOConnectionData_t::GetDelay, &GEntityIOConnectionData_t::SetDelay)
        .addProperty("TimesToFire", &GEntityIOConnectionData_t::GetTimesToFire, &GEntityIOConnectionData_t::SetTimesToFire)
        .endClass();
}