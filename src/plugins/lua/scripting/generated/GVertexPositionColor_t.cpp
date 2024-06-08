#include "../../../core/scripting/generated/classes/GVertexPositionColor_t.h"
#include "../core.h"

void SetupLuaClassGVertexPositionColor_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVertexPositionColor_t>("VertexPositionColor_t")
        .addProperty("Position", &GVertexPositionColor_t::GetPosition, &GVertexPositionColor_t::SetPosition)
        .endClass();
}