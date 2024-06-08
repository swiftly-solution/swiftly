#include "../../../core/scripting/generated/classes/GC_OP_RenderSimpleModelCollection.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderSimpleModelCollection(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderSimpleModelCollection>("C_OP_RenderSimpleModelCollection")
        .addProperty("CenterOffset", &GC_OP_RenderSimpleModelCollection::GetCenterOffset, &GC_OP_RenderSimpleModelCollection::SetCenterOffset)
        .addProperty("ModelInput", &GC_OP_RenderSimpleModelCollection::GetModelInput, &GC_OP_RenderSimpleModelCollection::SetModelInput)
        .addProperty("LOD", &GC_OP_RenderSimpleModelCollection::GetLOD, &GC_OP_RenderSimpleModelCollection::SetLOD)
        .addProperty("DisableShadows", &GC_OP_RenderSimpleModelCollection::GetDisableShadows, &GC_OP_RenderSimpleModelCollection::SetDisableShadows)
        .addProperty("DisableMotionBlur", &GC_OP_RenderSimpleModelCollection::GetDisableMotionBlur, &GC_OP_RenderSimpleModelCollection::SetDisableMotionBlur)
        .addProperty("AcceptsDecals", &GC_OP_RenderSimpleModelCollection::GetAcceptsDecals, &GC_OP_RenderSimpleModelCollection::SetAcceptsDecals)
        .addProperty("AngularVelocityField", &GC_OP_RenderSimpleModelCollection::GetAngularVelocityField, &GC_OP_RenderSimpleModelCollection::SetAngularVelocityField)
        .endClass();
}