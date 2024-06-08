#include "../../../core/scripting/generated/classes/GVertexPositionNormal_t.h"
#include "../core.h"

void SetupLuaClassGVertexPositionNormal_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVertexPositionNormal_t>("VertexPositionNormal_t")
        .addProperty("Position", &GVertexPositionNormal_t::GetPosition, &GVertexPositionNormal_t::SetPosition)
        .addProperty("Normal", &GVertexPositionNormal_t::GetNormal, &GVertexPositionNormal_t::SetNormal)
        .endClass();
}