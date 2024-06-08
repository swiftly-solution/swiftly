#include "../../../core/scripting/generated/classes/GEventAdvanceTick_t.h"
#include "../core.h"

void SetupLuaClassGEventAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventAdvanceTick_t>("EventAdvanceTick_t")
        .addProperty("CurrentTick", &GEventAdvanceTick_t::GetCurrentTick, &GEventAdvanceTick_t::SetCurrentTick)
        .addProperty("CurrentTickThisFrame", &GEventAdvanceTick_t::GetCurrentTickThisFrame, &GEventAdvanceTick_t::SetCurrentTickThisFrame)
        .addProperty("TotalTicksThisFrame", &GEventAdvanceTick_t::GetTotalTicksThisFrame, &GEventAdvanceTick_t::SetTotalTicksThisFrame)
        .addProperty("TotalTicks", &GEventAdvanceTick_t::GetTotalTicks, &GEventAdvanceTick_t::SetTotalTicks)
        .endClass();
}