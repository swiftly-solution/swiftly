#include "../../../core/scripting/generated/classes/GC_SunGlowOverlay.h"
#include "../core.h"

void SetupLuaClassGC_SunGlowOverlay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_SunGlowOverlay>("C_SunGlowOverlay")
        .addProperty("ModulateByDot", &GC_SunGlowOverlay::GetModulateByDot, &GC_SunGlowOverlay::SetModulateByDot)
        .endClass();
}