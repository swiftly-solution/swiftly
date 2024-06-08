#include "../../../core/scripting/generated/classes/GCovMatrix3.h"
#include "../core.h"

void SetupLuaClassGCovMatrix3(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCovMatrix3>("CovMatrix3")
        .addProperty("Diag", &GCovMatrix3::GetDiag, &GCovMatrix3::SetDiag)
        .addProperty("XY", &GCovMatrix3::GetXY, &GCovMatrix3::SetXY)
        .addProperty("XZ", &GCovMatrix3::GetXZ, &GCovMatrix3::SetXZ)
        .addProperty("YZ", &GCovMatrix3::GetYZ, &GCovMatrix3::SetYZ)
        .endClass();
}