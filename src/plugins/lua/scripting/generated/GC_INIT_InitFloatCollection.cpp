#include "../../../core/scripting/generated/classes/GC_INIT_InitFloatCollection.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitFloatCollection(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitFloatCollection>("C_INIT_InitFloatCollection")
        .addProperty("InputValue", &GC_INIT_InitFloatCollection::GetInputValue, &GC_INIT_InitFloatCollection::SetInputValue)
        .addProperty("OutputField", &GC_INIT_InitFloatCollection::GetOutputField, &GC_INIT_InitFloatCollection::SetOutputField)
        .endClass();
}