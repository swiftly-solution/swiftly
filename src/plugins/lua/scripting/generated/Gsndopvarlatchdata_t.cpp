#include "../../../core/scripting/generated/classes/Gsndopvarlatchdata_t.h"
#include "../core.h"

void SetupLuaClassGsndopvarlatchdata_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gsndopvarlatchdata_t>("sndopvarlatchdata_t")
        .addProperty("Stack", &Gsndopvarlatchdata_t::GetStack, &Gsndopvarlatchdata_t::SetStack)
        .addProperty("Operator", &Gsndopvarlatchdata_t::GetOperator, &Gsndopvarlatchdata_t::SetOperator)
        .addProperty("Opvar", &Gsndopvarlatchdata_t::GetOpvar, &Gsndopvarlatchdata_t::SetOpvar)
        .addProperty("Val", &Gsndopvarlatchdata_t::GetVal, &Gsndopvarlatchdata_t::SetVal)
        .addProperty("Pos", &Gsndopvarlatchdata_t::GetPos, &Gsndopvarlatchdata_t::SetPos)
        .endClass();
}