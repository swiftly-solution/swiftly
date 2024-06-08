#include "../../../core/scripting/generated/classes/GFourVectors2D.h"
#include "../core.h"

void SetupLuaClassGFourVectors2D(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFourVectors2D>("FourVectors2D")
        .addProperty("X", &GFourVectors2D::GetX, &GFourVectors2D::SetX)
        .addProperty("Y", &GFourVectors2D::GetY, &GFourVectors2D::SetY)
        .endClass();
}