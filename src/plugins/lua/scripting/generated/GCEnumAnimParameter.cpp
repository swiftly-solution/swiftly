#include "../../../core/scripting/generated/classes/GCEnumAnimParameter.h"
#include "../core.h"

void SetupLuaClassGCEnumAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnumAnimParameter>("CEnumAnimParameter")
        .addProperty("DefaultValue", &GCEnumAnimParameter::GetDefaultValue, &GCEnumAnimParameter::SetDefaultValue)
        .addProperty("EnumOptions", &GCEnumAnimParameter::GetEnumOptions, &GCEnumAnimParameter::SetEnumOptions)
        .addProperty("EnumReferenced", &GCEnumAnimParameter::GetEnumReferenced, &GCEnumAnimParameter::SetEnumReferenced)
        .endClass();
}