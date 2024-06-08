#include "../../../core/scripting/generated/classes/GMotionDBIndex.h"
#include "../core.h"

void SetupLuaClassGMotionDBIndex(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMotionDBIndex>("MotionDBIndex")
        .addProperty("Index", &GMotionDBIndex::GetIndex, &GMotionDBIndex::SetIndex)
        .endClass();
}