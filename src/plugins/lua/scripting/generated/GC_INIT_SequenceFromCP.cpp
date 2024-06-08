#include "../../../core/scripting/generated/classes/GC_INIT_SequenceFromCP.h"
#include "../core.h"

void SetupLuaClassGC_INIT_SequenceFromCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_SequenceFromCP>("C_INIT_SequenceFromCP")
        .addProperty("KillUnused", &GC_INIT_SequenceFromCP::GetKillUnused, &GC_INIT_SequenceFromCP::SetKillUnused)
        .addProperty("RadiusScale", &GC_INIT_SequenceFromCP::GetRadiusScale, &GC_INIT_SequenceFromCP::SetRadiusScale)
        .addProperty("CP", &GC_INIT_SequenceFromCP::GetCP, &GC_INIT_SequenceFromCP::SetCP)
        .addProperty("Offset", &GC_INIT_SequenceFromCP::GetOffset, &GC_INIT_SequenceFromCP::SetOffset)
        .endClass();
}