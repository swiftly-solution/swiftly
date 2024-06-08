#include "../../../core/scripting/generated/classes/GC_OP_InheritFromPeerSystem.h"
#include "../core.h"

void SetupLuaClassGC_OP_InheritFromPeerSystem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_InheritFromPeerSystem>("C_OP_InheritFromPeerSystem")
        .addProperty("FieldOutput", &GC_OP_InheritFromPeerSystem::GetFieldOutput, &GC_OP_InheritFromPeerSystem::SetFieldOutput)
        .addProperty("FieldInput", &GC_OP_InheritFromPeerSystem::GetFieldInput, &GC_OP_InheritFromPeerSystem::SetFieldInput)
        .addProperty("Increment", &GC_OP_InheritFromPeerSystem::GetIncrement, &GC_OP_InheritFromPeerSystem::SetIncrement)
        .addProperty("GroupID", &GC_OP_InheritFromPeerSystem::GetGroupID, &GC_OP_InheritFromPeerSystem::SetGroupID)
        .endClass();
}