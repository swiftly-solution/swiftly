#include "../../../core/scripting/generated/classes/GC_OP_SetPerChildControlPointFromAttribute.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetPerChildControlPointFromAttribute(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetPerChildControlPointFromAttribute>("C_OP_SetPerChildControlPointFromAttribute")
        .addProperty("ChildGroupID", &GC_OP_SetPerChildControlPointFromAttribute::GetChildGroupID, &GC_OP_SetPerChildControlPointFromAttribute::SetChildGroupID)
        .addProperty("FirstControlPoint", &GC_OP_SetPerChildControlPointFromAttribute::GetFirstControlPoint, &GC_OP_SetPerChildControlPointFromAttribute::SetFirstControlPoint)
        .addProperty("NumControlPoints", &GC_OP_SetPerChildControlPointFromAttribute::GetNumControlPoints, &GC_OP_SetPerChildControlPointFromAttribute::SetNumControlPoints)
        .addProperty("ParticleIncrement", &GC_OP_SetPerChildControlPointFromAttribute::GetParticleIncrement, &GC_OP_SetPerChildControlPointFromAttribute::SetParticleIncrement)
        .addProperty("FirstSourcePoint", &GC_OP_SetPerChildControlPointFromAttribute::GetFirstSourcePoint, &GC_OP_SetPerChildControlPointFromAttribute::SetFirstSourcePoint)
        .addProperty("NumBasedOnParticleCount", &GC_OP_SetPerChildControlPointFromAttribute::GetNumBasedOnParticleCount, &GC_OP_SetPerChildControlPointFromAttribute::SetNumBasedOnParticleCount)
        .addProperty("AttributeToRead", &GC_OP_SetPerChildControlPointFromAttribute::GetAttributeToRead, &GC_OP_SetPerChildControlPointFromAttribute::SetAttributeToRead)
        .addProperty("CPField", &GC_OP_SetPerChildControlPointFromAttribute::GetCPField, &GC_OP_SetPerChildControlPointFromAttribute::SetCPField)
        .endClass();
}