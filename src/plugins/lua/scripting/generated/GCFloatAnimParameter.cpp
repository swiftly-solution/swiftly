#include "../../../core/scripting/generated/classes/GCFloatAnimParameter.h"
#include "../core.h"

void SetupLuaClassGCFloatAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFloatAnimParameter>("CFloatAnimParameter")
        .addProperty("DefaultValue", &GCFloatAnimParameter::GetDefaultValue, &GCFloatAnimParameter::SetDefaultValue)
        .addProperty("MinValue", &GCFloatAnimParameter::GetMinValue, &GCFloatAnimParameter::SetMinValue)
        .addProperty("MaxValue", &GCFloatAnimParameter::GetMaxValue, &GCFloatAnimParameter::SetMaxValue)
        .addProperty("Interpolate", &GCFloatAnimParameter::GetInterpolate, &GCFloatAnimParameter::SetInterpolate)
        .endClass();
}