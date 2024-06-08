#include "../../../core/scripting/generated/classes/GCExampleSchemaVData_PolymorphicDerivedB.h"
#include "../core.h"

void SetupLuaClassGCExampleSchemaVData_PolymorphicDerivedB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCExampleSchemaVData_PolymorphicDerivedB>("CExampleSchemaVData_PolymorphicDerivedB")
        .addProperty("DerivedB", &GCExampleSchemaVData_PolymorphicDerivedB::GetDerivedB, &GCExampleSchemaVData_PolymorphicDerivedB::SetDerivedB)
        .endClass();
}