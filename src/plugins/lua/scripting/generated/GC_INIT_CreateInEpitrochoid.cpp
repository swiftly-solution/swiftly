#include "../../../core/scripting/generated/classes/GC_INIT_CreateInEpitrochoid.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateInEpitrochoid(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateInEpitrochoid>("C_INIT_CreateInEpitrochoid")
        .addProperty("Component1", &GC_INIT_CreateInEpitrochoid::GetComponent1, &GC_INIT_CreateInEpitrochoid::SetComponent1)
        .addProperty("Component2", &GC_INIT_CreateInEpitrochoid::GetComponent2, &GC_INIT_CreateInEpitrochoid::SetComponent2)
        .addProperty("TransformInput", &GC_INIT_CreateInEpitrochoid::GetTransformInput, &GC_INIT_CreateInEpitrochoid::SetTransformInput)
        .addProperty("ParticleDensity", &GC_INIT_CreateInEpitrochoid::GetParticleDensity, &GC_INIT_CreateInEpitrochoid::SetParticleDensity)
        .addProperty("Offset", &GC_INIT_CreateInEpitrochoid::GetOffset, &GC_INIT_CreateInEpitrochoid::SetOffset)
        .addProperty("Radius1", &GC_INIT_CreateInEpitrochoid::GetRadius1, &GC_INIT_CreateInEpitrochoid::SetRadius1)
        .addProperty("Radius2", &GC_INIT_CreateInEpitrochoid::GetRadius2, &GC_INIT_CreateInEpitrochoid::SetRadius2)
        .addProperty("UseCount", &GC_INIT_CreateInEpitrochoid::GetUseCount, &GC_INIT_CreateInEpitrochoid::SetUseCount)
        .addProperty("UseLocalCoords", &GC_INIT_CreateInEpitrochoid::GetUseLocalCoords, &GC_INIT_CreateInEpitrochoid::SetUseLocalCoords)
        .addProperty("OffsetExistingPos", &GC_INIT_CreateInEpitrochoid::GetOffsetExistingPos, &GC_INIT_CreateInEpitrochoid::SetOffsetExistingPos)
        .endClass();
}