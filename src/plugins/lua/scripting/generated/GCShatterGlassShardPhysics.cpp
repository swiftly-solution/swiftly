#include "../../../core/scripting/generated/classes/GCShatterGlassShardPhysics.h"
#include "../core.h"

void SetupLuaClassGCShatterGlassShardPhysics(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCShatterGlassShardPhysics>("CShatterGlassShardPhysics")
        .addProperty("Debris", &GCShatterGlassShardPhysics::GetDebris, &GCShatterGlassShardPhysics::SetDebris)
        .addProperty("ParentShard", &GCShatterGlassShardPhysics::GetParentShard, &GCShatterGlassShardPhysics::SetParentShard)
        .addProperty("ShardDesc", &GCShatterGlassShardPhysics::GetShardDesc, &GCShatterGlassShardPhysics::SetShardDesc)
        .endClass();
}