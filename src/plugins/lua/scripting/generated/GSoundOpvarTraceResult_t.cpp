#include "../../../core/scripting/generated/classes/GSoundOpvarTraceResult_t.h"
#include "../core.h"

void SetupLuaClassGSoundOpvarTraceResult_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSoundOpvarTraceResult_t>("SoundOpvarTraceResult_t")
        .addProperty("Pos", &GSoundOpvarTraceResult_t::GetPos, &GSoundOpvarTraceResult_t::SetPos)
        .addProperty("DidHit", &GSoundOpvarTraceResult_t::GetDidHit, &GSoundOpvarTraceResult_t::SetDidHit)
        .addProperty("DistSqrToCenter", &GSoundOpvarTraceResult_t::GetDistSqrToCenter, &GSoundOpvarTraceResult_t::SetDistSqrToCenter)
        .endClass();
}