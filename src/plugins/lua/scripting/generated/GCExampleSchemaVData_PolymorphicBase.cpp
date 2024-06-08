#include "../../../core/scripting/generated/classes/GCExampleSchemaVData_PolymorphicBase.h"
#include "../core.h"

void SetupLuaClassGCExampleSchemaVData_PolymorphicBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCExampleSchemaVData_PolymorphicBase>("CExampleSchemaVData_PolymorphicBase")
        .addProperty("Base", &GCExampleSchemaVData_PolymorphicBase::GetBase, &GCExampleSchemaVData_PolymorphicBase::SetBase)
        .endClass();
}