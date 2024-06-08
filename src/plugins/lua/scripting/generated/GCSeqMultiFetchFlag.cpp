#include "../../../core/scripting/generated/classes/GCSeqMultiFetchFlag.h"
#include "../core.h"

void SetupLuaClassGCSeqMultiFetchFlag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqMultiFetchFlag>("CSeqMultiFetchFlag")
        .addProperty("Realtime", &GCSeqMultiFetchFlag::GetRealtime, &GCSeqMultiFetchFlag::SetRealtime)
        .addProperty("Cylepose", &GCSeqMultiFetchFlag::GetCylepose, &GCSeqMultiFetchFlag::SetCylepose)
        .addProperty("0D", &GCSeqMultiFetchFlag::Get0D, &GCSeqMultiFetchFlag::Set0D)
        .addProperty("1D", &GCSeqMultiFetchFlag::Get1D, &GCSeqMultiFetchFlag::Set1D)
        .addProperty("2D", &GCSeqMultiFetchFlag::Get2D, &GCSeqMultiFetchFlag::Set2D)
        .addProperty("2D_TRI", &GCSeqMultiFetchFlag::Get2D_TRI, &GCSeqMultiFetchFlag::Set2D_TRI)
        .endClass();
}