#include "../../../core/scripting/generated/classes/GCTestEffect.h"
#include "../core.h"

void SetupLuaClassGCTestEffect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTestEffect>("CTestEffect")
        .addProperty("Loop", &GCTestEffect::GetLoop, &GCTestEffect::SetLoop)
        .addProperty("Beam", &GCTestEffect::GetBeam, &GCTestEffect::SetBeam)
        .addProperty("Beam1", &GCTestEffect::GetBeam1, &GCTestEffect::SetBeam1)
        .endClass();
}