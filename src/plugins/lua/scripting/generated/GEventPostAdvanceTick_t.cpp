#include "../../../core/scripting/generated/classes/GEventPostAdvanceTick_t.h"
#include "../core.h"

void SetupLuaClassGEventPostAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventPostAdvanceTick_t>("EventPostAdvanceTick_t")
        .addProperty("CurrentTick", &GEventPostAdvanceTick_t::GetCurrentTick, &GEventPostAdvanceTick_t::SetCurrentTick)
        .addProperty("CurrentTickThisFrame", &GEventPostAdvanceTick_t::GetCurrentTickThisFrame, &GEventPostAdvanceTick_t::SetCurrentTickThisFrame)
        .addProperty("TotalTicksThisFrame", &GEventPostAdvanceTick_t::GetTotalTicksThisFrame, &GEventPostAdvanceTick_t::SetTotalTicksThisFrame)
        .addProperty("TotalTicks", &GEventPostAdvanceTick_t::GetTotalTicks, &GEventPostAdvanceTick_t::SetTotalTicks)
        .endClass();
}