#include "../../../core/scripting/generated/classes/GFourQuaternions.h"
#include "../core.h"

void SetupLuaClassGFourQuaternions(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFourQuaternions>("FourQuaternions")
        .addProperty("X", &GFourQuaternions::GetX, &GFourQuaternions::SetX)
        .addProperty("Y", &GFourQuaternions::GetY, &GFourQuaternions::SetY)
        .addProperty("Z", &GFourQuaternions::GetZ, &GFourQuaternions::SetZ)
        .addProperty("W", &GFourQuaternions::GetW, &GFourQuaternions::SetW)
        .endClass();
}