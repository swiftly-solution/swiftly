#include "../../../core/scripting/generated/classes/GC_OP_CollideWithSelf.h"
#include "../core.h"

void SetupLuaClassGC_OP_CollideWithSelf(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_CollideWithSelf>("C_OP_CollideWithSelf")
        .addProperty("RadiusScale", &GC_OP_CollideWithSelf::GetRadiusScale, &GC_OP_CollideWithSelf::SetRadiusScale)
        .addProperty("MinimumSpeed", &GC_OP_CollideWithSelf::GetMinimumSpeed, &GC_OP_CollideWithSelf::SetMinimumSpeed)
        .endClass();
}