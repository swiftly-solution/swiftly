#include "../../../core/scripting/generated/classes/GCSoundEventParameter.h"
#include "../core.h"

void SetupLuaClassGCSoundEventParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventParameter>("CSoundEventParameter")
        .addProperty("ParamName", &GCSoundEventParameter::GetParamName, &GCSoundEventParameter::SetParamName)
        .addProperty("FloatValue", &GCSoundEventParameter::GetFloatValue, &GCSoundEventParameter::SetFloatValue)
        .endClass();
}