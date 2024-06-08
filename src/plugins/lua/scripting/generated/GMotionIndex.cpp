#include "../../../core/scripting/generated/classes/GMotionIndex.h"
#include "../core.h"

void SetupLuaClassGMotionIndex(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMotionIndex>("MotionIndex")
        .addProperty("Group", &GMotionIndex::GetGroup, &GMotionIndex::SetGroup)
        .addProperty("Motion", &GMotionIndex::GetMotion, &GMotionIndex::SetMotion)
        .endClass();
}