#include "../../../core/scripting/generated/classes/Glerpdata_t.h"
#include "../core.h"

void SetupLuaClassGlerpdata_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Glerpdata_t>("lerpdata_t")
        .addProperty("Ent", &Glerpdata_t::GetEnt, &Glerpdata_t::SetEnt)
        .addProperty("MoveType", &Glerpdata_t::GetMoveType, &Glerpdata_t::SetMoveType)
        .addProperty("StartOrigin", &Glerpdata_t::GetStartOrigin, &Glerpdata_t::SetStartOrigin)
        .addProperty("StartRot", &Glerpdata_t::GetStartRot, &Glerpdata_t::SetStartRot)
        .addProperty("FXIndex", &Glerpdata_t::GetFXIndex, &Glerpdata_t::SetFXIndex)
        .endClass();
}