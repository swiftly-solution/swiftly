#include "../../../core/scripting/generated/classes/GFourCovMatrices3.h"
#include "../core.h"

void SetupLuaClassGFourCovMatrices3(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFourCovMatrices3>("FourCovMatrices3")
        .addProperty("XY", &GFourCovMatrices3::GetXY, &GFourCovMatrices3::SetXY)
        .addProperty("XZ", &GFourCovMatrices3::GetXZ, &GFourCovMatrices3::SetXZ)
        .addProperty("YZ", &GFourCovMatrices3::GetYZ, &GFourCovMatrices3::SetYZ)
        .endClass();
}