#include "../../../core/scripting/generated/classes/GCConstraintSlave.h"
#include "../core.h"

void SetupLuaClassGCConstraintSlave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCConstraintSlave>("CConstraintSlave")
        .addProperty("BaseOrientation", &GCConstraintSlave::GetBaseOrientation, &GCConstraintSlave::SetBaseOrientation)
        .addProperty("BasePosition", &GCConstraintSlave::GetBasePosition, &GCConstraintSlave::SetBasePosition)
        .addProperty("BoneHash", &GCConstraintSlave::GetBoneHash, &GCConstraintSlave::SetBoneHash)
        .addProperty("Weight", &GCConstraintSlave::GetWeight, &GCConstraintSlave::SetWeight)
        .addProperty("Name", &GCConstraintSlave::GetName, &GCConstraintSlave::SetName)
        .endClass();
}