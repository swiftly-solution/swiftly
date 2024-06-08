#include "../../../core/scripting/generated/classes/GC_OP_SnapshotRigidSkinToBones.h"
#include "../core.h"

void SetupLuaClassGC_OP_SnapshotRigidSkinToBones(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SnapshotRigidSkinToBones>("C_OP_SnapshotRigidSkinToBones")
        .addProperty("TransformNormals", &GC_OP_SnapshotRigidSkinToBones::GetTransformNormals, &GC_OP_SnapshotRigidSkinToBones::SetTransformNormals)
        .addProperty("TransformRadii", &GC_OP_SnapshotRigidSkinToBones::GetTransformRadii, &GC_OP_SnapshotRigidSkinToBones::SetTransformRadii)
        .addProperty("ControlPointNumber", &GC_OP_SnapshotRigidSkinToBones::GetControlPointNumber, &GC_OP_SnapshotRigidSkinToBones::SetControlPointNumber)
        .endClass();
}