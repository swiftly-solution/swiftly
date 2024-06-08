#include "../../../core/scripting/generated/classes/GC_OP_SetFloatCollection.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetFloatCollection(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetFloatCollection>("C_OP_SetFloatCollection")
        .addProperty("InputValue", &GC_OP_SetFloatCollection::GetInputValue, &GC_OP_SetFloatCollection::SetInputValue)
        .addProperty("OutputField", &GC_OP_SetFloatCollection::GetOutputField, &GC_OP_SetFloatCollection::SetOutputField)
        .addProperty("SetMethod", &GC_OP_SetFloatCollection::GetSetMethod, &GC_OP_SetFloatCollection::SetSetMethod)
        .addProperty("Lerp", &GC_OP_SetFloatCollection::GetLerp, &GC_OP_SetFloatCollection::SetLerp)
        .endClass();
}