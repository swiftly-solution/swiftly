#include "../../../core/scripting/generated/classes/GCConstraintTarget.h"
#include "../core.h"

void SetupLuaClassGCConstraintTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCConstraintTarget>("CConstraintTarget")
        .addProperty("Offset", &GCConstraintTarget::GetOffset, &GCConstraintTarget::SetOffset)
        .addProperty("Offset1", &GCConstraintTarget::GetOffset1, &GCConstraintTarget::SetOffset1)
        .addProperty("BoneHash", &GCConstraintTarget::GetBoneHash, &GCConstraintTarget::SetBoneHash)
        .addProperty("Name", &GCConstraintTarget::GetName, &GCConstraintTarget::SetName)
        .addProperty("Weight", &GCConstraintTarget::GetWeight, &GCConstraintTarget::SetWeight)
        .addProperty("IsAttachment", &GCConstraintTarget::GetIsAttachment, &GCConstraintTarget::SetIsAttachment)
        .endClass();
}