#include "../../../core/scripting/generated/classes/GC_OP_MovementRigidAttachToCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_MovementRigidAttachToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MovementRigidAttachToCP>("C_OP_MovementRigidAttachToCP")
        .addProperty("ControlPointNumber", &GC_OP_MovementRigidAttachToCP::GetControlPointNumber, &GC_OP_MovementRigidAttachToCP::SetControlPointNumber)
        .addProperty("ScaleControlPoint", &GC_OP_MovementRigidAttachToCP::GetScaleControlPoint, &GC_OP_MovementRigidAttachToCP::SetScaleControlPoint)
        .addProperty("ScaleCPField", &GC_OP_MovementRigidAttachToCP::GetScaleCPField, &GC_OP_MovementRigidAttachToCP::SetScaleCPField)
        .addProperty("FieldInput", &GC_OP_MovementRigidAttachToCP::GetFieldInput, &GC_OP_MovementRigidAttachToCP::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_MovementRigidAttachToCP::GetFieldOutput, &GC_OP_MovementRigidAttachToCP::SetFieldOutput)
        .addProperty("OffsetLocal", &GC_OP_MovementRigidAttachToCP::GetOffsetLocal, &GC_OP_MovementRigidAttachToCP::SetOffsetLocal)
        .endClass();
}