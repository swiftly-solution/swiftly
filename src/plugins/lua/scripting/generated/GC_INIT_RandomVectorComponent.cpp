#include "../../../core/scripting/generated/classes/GC_INIT_RandomVectorComponent.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomVectorComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomVectorComponent>("C_INIT_RandomVectorComponent")
        .addProperty("Min", &GC_INIT_RandomVectorComponent::GetMin, &GC_INIT_RandomVectorComponent::SetMin)
        .addProperty("Max", &GC_INIT_RandomVectorComponent::GetMax, &GC_INIT_RandomVectorComponent::SetMax)
        .addProperty("FieldOutput", &GC_INIT_RandomVectorComponent::GetFieldOutput, &GC_INIT_RandomVectorComponent::SetFieldOutput)
        .addProperty("Component", &GC_INIT_RandomVectorComponent::GetComponent, &GC_INIT_RandomVectorComponent::SetComponent)
        .endClass();
}