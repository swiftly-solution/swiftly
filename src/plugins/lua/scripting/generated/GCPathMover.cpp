#include "../../../core/scripting/generated/classes/GCPathMover.h"
#include "../core.h"

void SetupLuaClassGCPathMover(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathMover>("CPathMover")
        .addProperty("PathLength", &GCPathMover::GetPathLength, &GCPathMover::SetPathLength)
        .addProperty("ClosedLoop", &GCPathMover::GetClosedLoop, &GCPathMover::SetClosedLoop)
        .endClass();
}