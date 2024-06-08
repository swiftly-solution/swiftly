#include "../../../core/scripting/generated/classes/GCMotionSearchDB.h"
#include "../core.h"

void SetupLuaClassGCMotionSearchDB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionSearchDB>("CMotionSearchDB")
        .addProperty("RootNode", &GCMotionSearchDB::GetRootNode, &GCMotionSearchDB::SetRootNode)
        .addProperty("ResidualQuantizer", &GCMotionSearchDB::GetResidualQuantizer, &GCMotionSearchDB::SetResidualQuantizer)
        .addProperty("CodeIndices", &GCMotionSearchDB::GetCodeIndices, &GCMotionSearchDB::SetCodeIndices)
        .endClass();
}