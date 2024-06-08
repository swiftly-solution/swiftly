#include "../../../core/scripting/generated/classes/GCPhysPulley.h"
#include "../core.h"

void SetupLuaClassGCPhysPulley(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysPulley>("CPhysPulley")
        .addProperty("Position2", &GCPhysPulley::GetPosition2, &GCPhysPulley::SetPosition2)
        .addProperty("Offset", &GCPhysPulley::GetOffset, &GCPhysPulley::SetOffset)
        .addProperty("AddLength", &GCPhysPulley::GetAddLength, &GCPhysPulley::SetAddLength)
        .addProperty("GearRatio", &GCPhysPulley::GetGearRatio, &GCPhysPulley::SetGearRatio)
        .endClass();
}