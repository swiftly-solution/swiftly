#include "../../../core/scripting/generated/classes/GSkeletonBoneBounds_t.h"
#include "../core.h"

void SetupLuaClassGSkeletonBoneBounds_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonBoneBounds_t>("SkeletonBoneBounds_t")
        .addProperty("Center", &GSkeletonBoneBounds_t::GetCenter, &GSkeletonBoneBounds_t::SetCenter)
        .addProperty("Size", &GSkeletonBoneBounds_t::GetSize, &GSkeletonBoneBounds_t::SetSize)
        .endClass();
}