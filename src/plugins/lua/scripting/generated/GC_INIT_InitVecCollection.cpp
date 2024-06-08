#include "../../../core/scripting/generated/classes/GC_INIT_InitVecCollection.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitVecCollection(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitVecCollection>("C_INIT_InitVecCollection")
        .addProperty("OutputField", &GC_INIT_InitVecCollection::GetOutputField, &GC_INIT_InitVecCollection::SetOutputField)
        .endClass();
}