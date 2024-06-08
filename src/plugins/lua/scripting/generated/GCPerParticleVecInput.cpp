#include "../../../core/scripting/generated/classes/GCPerParticleVecInput.h"
#include "../core.h"

void SetupLuaClassGCPerParticleVecInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPerParticleVecInput>("CPerParticleVecInput")

        .endClass();
}