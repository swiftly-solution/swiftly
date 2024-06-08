#include "../../../core/scripting/generated/classes/GCBaseProp.h"
#include "../core.h"

void SetupLuaClassGCBaseProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseProp>("CBaseProp")
        .addProperty("ModelOverrodeBlockLOS", &GCBaseProp::GetModelOverrodeBlockLOS, &GCBaseProp::SetModelOverrodeBlockLOS)
        .addProperty("ShapeType", &GCBaseProp::GetShapeType, &GCBaseProp::SetShapeType)
        .addProperty("ConformToCollisionBounds", &GCBaseProp::GetConformToCollisionBounds, &GCBaseProp::SetConformToCollisionBounds)
        .addProperty("MPreferredCatchTransform", &GCBaseProp::GetMPreferredCatchTransform, &GCBaseProp::SetMPreferredCatchTransform)
        .endClass();
}