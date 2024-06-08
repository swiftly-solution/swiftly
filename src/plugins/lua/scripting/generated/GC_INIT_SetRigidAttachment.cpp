#include "../../../core/scripting/generated/classes/GC_INIT_SetRigidAttachment.h"
#include "../core.h"

void SetupLuaClassGC_INIT_SetRigidAttachment(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_SetRigidAttachment>("C_INIT_SetRigidAttachment")
        .addProperty("ControlPointNumber", &GC_INIT_SetRigidAttachment::GetControlPointNumber, &GC_INIT_SetRigidAttachment::SetControlPointNumber)
        .addProperty("FieldInput", &GC_INIT_SetRigidAttachment::GetFieldInput, &GC_INIT_SetRigidAttachment::SetFieldInput)
        .addProperty("FieldOutput", &GC_INIT_SetRigidAttachment::GetFieldOutput, &GC_INIT_SetRigidAttachment::SetFieldOutput)
        .addProperty("LocalSpace", &GC_INIT_SetRigidAttachment::GetLocalSpace, &GC_INIT_SetRigidAttachment::SetLocalSpace)
        .endClass();
}