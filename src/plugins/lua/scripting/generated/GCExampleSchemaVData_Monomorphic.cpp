#include "../../../core/scripting/generated/classes/GCExampleSchemaVData_Monomorphic.h"
#include "../core.h"

void SetupLuaClassGCExampleSchemaVData_Monomorphic(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCExampleSchemaVData_Monomorphic>("CExampleSchemaVData_Monomorphic")
        .addProperty("Example1", &GCExampleSchemaVData_Monomorphic::GetExample1, &GCExampleSchemaVData_Monomorphic::SetExample1)
        .addProperty("Example2", &GCExampleSchemaVData_Monomorphic::GetExample2, &GCExampleSchemaVData_Monomorphic::SetExample2)
        .endClass();
}