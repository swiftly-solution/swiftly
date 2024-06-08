#include "../../../core/scripting/generated/classes/GCVectorAnimParameter.h"
#include "../core.h"

void SetupLuaClassGCVectorAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVectorAnimParameter>("CVectorAnimParameter")
        .addProperty("DefaultValue", &GCVectorAnimParameter::GetDefaultValue, &GCVectorAnimParameter::SetDefaultValue)
        .addProperty("Interpolate", &GCVectorAnimParameter::GetInterpolate, &GCVectorAnimParameter::SetInterpolate)
        .endClass();
}