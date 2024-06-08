#include "../../../core/scripting/generated/classes/GCRandSimTimer.h"
#include "../core.h"

void SetupLuaClassGCRandSimTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRandSimTimer>("CRandSimTimer")
        .addProperty("MinInterval", &GCRandSimTimer::GetMinInterval, &GCRandSimTimer::SetMinInterval)
        .addProperty("MaxInterval", &GCRandSimTimer::GetMaxInterval, &GCRandSimTimer::SetMaxInterval)
        .endClass();
}