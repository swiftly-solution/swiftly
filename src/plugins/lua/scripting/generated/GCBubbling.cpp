#include "../../../core/scripting/generated/classes/GCBubbling.h"
#include "../core.h"

void SetupLuaClassGCBubbling(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBubbling>("CBubbling")
        .addProperty("Density", &GCBubbling::GetDensity, &GCBubbling::SetDensity)
        .addProperty("Frequency", &GCBubbling::GetFrequency, &GCBubbling::SetFrequency)
        .addProperty("State", &GCBubbling::GetState, &GCBubbling::SetState)
        .endClass();
}