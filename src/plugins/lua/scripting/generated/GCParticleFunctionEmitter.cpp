#include "../../../core/scripting/generated/classes/GCParticleFunctionEmitter.h"
#include "../core.h"

void SetupLuaClassGCParticleFunctionEmitter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionEmitter>("CParticleFunctionEmitter")
        .addProperty("EmitterIndex", &GCParticleFunctionEmitter::GetEmitterIndex, &GCParticleFunctionEmitter::SetEmitterIndex)
        .endClass();
}