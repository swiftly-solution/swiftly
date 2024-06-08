#include "../../../core/scripting/generated/classes/GCParticleFunctionInitializer.h"
#include "../core.h"

void SetupLuaClassGCParticleFunctionInitializer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionInitializer>("CParticleFunctionInitializer")
        .addProperty("AssociatedEmitterIndex", &GCParticleFunctionInitializer::GetAssociatedEmitterIndex, &GCParticleFunctionInitializer::SetAssociatedEmitterIndex)
        .endClass();
}