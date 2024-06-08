#include "../../../core/scripting/generated/classes/GCRandomNumberGeneratorParameters.h"
#include "../core.h"

void SetupLuaClassGCRandomNumberGeneratorParameters(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRandomNumberGeneratorParameters>("CRandomNumberGeneratorParameters")
        .addProperty("DistributeEvenly", &GCRandomNumberGeneratorParameters::GetDistributeEvenly, &GCRandomNumberGeneratorParameters::SetDistributeEvenly)
        .addProperty("Seed", &GCRandomNumberGeneratorParameters::GetSeed, &GCRandomNumberGeneratorParameters::SetSeed)
        .endClass();
}