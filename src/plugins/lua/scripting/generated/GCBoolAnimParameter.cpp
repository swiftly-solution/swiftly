#include "../../../core/scripting/generated/classes/GCBoolAnimParameter.h"
#include "../core.h"

void SetupLuaClassGCBoolAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoolAnimParameter>("CBoolAnimParameter")
        .addProperty("DefaultValue", &GCBoolAnimParameter::GetDefaultValue, &GCBoolAnimParameter::SetDefaultValue)
        .endClass();
}