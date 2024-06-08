#include "../../../core/scripting/generated/classes/GVPhysXAggregateData_t.h"
#include "../core.h"

void SetupLuaClassGVPhysXAggregateData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXAggregateData_t>("VPhysXAggregateData_t")
        .addProperty("Flags", &GVPhysXAggregateData_t::GetFlags, &GVPhysXAggregateData_t::SetFlags)
        .addProperty("RefCounter", &GVPhysXAggregateData_t::GetRefCounter, &GVPhysXAggregateData_t::SetRefCounter)
        .addProperty("BonesHash", &GVPhysXAggregateData_t::GetBonesHash, &GVPhysXAggregateData_t::SetBonesHash)
        .addProperty("BoneNames", &GVPhysXAggregateData_t::GetBoneNames, &GVPhysXAggregateData_t::SetBoneNames)
        .addProperty("IndexNames", &GVPhysXAggregateData_t::GetIndexNames, &GVPhysXAggregateData_t::SetIndexNames)
        .addProperty("IndexHash", &GVPhysXAggregateData_t::GetIndexHash, &GVPhysXAggregateData_t::SetIndexHash)
        .addProperty("BindPose", &GVPhysXAggregateData_t::GetBindPose, &GVPhysXAggregateData_t::SetBindPose)
        .addProperty("Parts", &GVPhysXAggregateData_t::GetParts, &GVPhysXAggregateData_t::SetParts)
        .addProperty("Constraints2", &GVPhysXAggregateData_t::GetConstraints2, &GVPhysXAggregateData_t::SetConstraints2)
        .addProperty("Joints", &GVPhysXAggregateData_t::GetJoints, &GVPhysXAggregateData_t::SetJoints)
        .addProperty("FeModel", &GVPhysXAggregateData_t::GetFeModel, &GVPhysXAggregateData_t::SetFeModel)
        .addProperty("BoneParents", &GVPhysXAggregateData_t::GetBoneParents, &GVPhysXAggregateData_t::SetBoneParents)
        .addProperty("SurfacePropertyHashes", &GVPhysXAggregateData_t::GetSurfacePropertyHashes, &GVPhysXAggregateData_t::SetSurfacePropertyHashes)
        .addProperty("CollisionAttributes", &GVPhysXAggregateData_t::GetCollisionAttributes, &GVPhysXAggregateData_t::SetCollisionAttributes)
        .addProperty("DebugPartNames", &GVPhysXAggregateData_t::GetDebugPartNames, &GVPhysXAggregateData_t::SetDebugPartNames)
        .addProperty("EmbeddedKeyvalues", &GVPhysXAggregateData_t::GetEmbeddedKeyvalues, &GVPhysXAggregateData_t::SetEmbeddedKeyvalues)
        .endClass();
}