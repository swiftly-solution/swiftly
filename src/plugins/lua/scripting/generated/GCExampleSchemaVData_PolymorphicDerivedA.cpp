#include "../../../core/scripting/generated/classes/GCExampleSchemaVData_PolymorphicDerivedA.h"
#include "../core.h"

void SetupLuaClassGCExampleSchemaVData_PolymorphicDerivedA(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCExampleSchemaVData_PolymorphicDerivedA>("CExampleSchemaVData_PolymorphicDerivedA")
        .addProperty("DerivedA", &GCExampleSchemaVData_PolymorphicDerivedA::GetDerivedA, &GCExampleSchemaVData_PolymorphicDerivedA::SetDerivedA)
        .endClass();
}