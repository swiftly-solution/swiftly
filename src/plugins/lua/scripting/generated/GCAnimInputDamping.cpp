#include "../../../core/scripting/generated/classes/GCAnimInputDamping.h"
#include "../core.h"

void SetupLuaClassGCAnimInputDamping(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimInputDamping>("CAnimInputDamping")
        .addProperty("SpeedFunction", &GCAnimInputDamping::GetSpeedFunction, &GCAnimInputDamping::SetSpeedFunction)
        .addProperty("SpeedScale", &GCAnimInputDamping::GetSpeedScale, &GCAnimInputDamping::SetSpeedScale)
        .endClass();
}