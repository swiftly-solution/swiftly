#include "../../../core/scripting/generated/classes/GCIntAnimParameter.h"
#include "../core.h"

void SetupLuaClassGCIntAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCIntAnimParameter>("CIntAnimParameter")
        .addProperty("DefaultValue", &GCIntAnimParameter::GetDefaultValue, &GCIntAnimParameter::SetDefaultValue)
        .addProperty("MinValue", &GCIntAnimParameter::GetMinValue, &GCIntAnimParameter::SetMinValue)
        .addProperty("MaxValue", &GCIntAnimParameter::GetMaxValue, &GCIntAnimParameter::SetMaxValue)
        .endClass();
}