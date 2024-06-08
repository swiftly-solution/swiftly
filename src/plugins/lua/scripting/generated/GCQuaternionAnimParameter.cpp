#include "../../../core/scripting/generated/classes/GCQuaternionAnimParameter.h"
#include "../core.h"

void SetupLuaClassGCQuaternionAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCQuaternionAnimParameter>("CQuaternionAnimParameter")
        .addProperty("DefaultValue", &GCQuaternionAnimParameter::GetDefaultValue, &GCQuaternionAnimParameter::SetDefaultValue)
        .addProperty("Interpolate", &GCQuaternionAnimParameter::GetInterpolate, &GCQuaternionAnimParameter::SetInterpolate)
        .endClass();
}