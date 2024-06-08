#include "../../../core/scripting/generated/classes/GCPhysSurfacePropertiesPhysics.h"
#include "../core.h"

void SetupLuaClassGCPhysSurfacePropertiesPhysics(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysSurfacePropertiesPhysics>("CPhysSurfacePropertiesPhysics")
        .addProperty("Friction", &GCPhysSurfacePropertiesPhysics::GetFriction, &GCPhysSurfacePropertiesPhysics::SetFriction)
        .addProperty("Elasticity", &GCPhysSurfacePropertiesPhysics::GetElasticity, &GCPhysSurfacePropertiesPhysics::SetElasticity)
        .addProperty("Density", &GCPhysSurfacePropertiesPhysics::GetDensity, &GCPhysSurfacePropertiesPhysics::SetDensity)
        .addProperty("Thickness", &GCPhysSurfacePropertiesPhysics::GetThickness, &GCPhysSurfacePropertiesPhysics::SetThickness)
        .addProperty("SoftContactFrequency", &GCPhysSurfacePropertiesPhysics::GetSoftContactFrequency, &GCPhysSurfacePropertiesPhysics::SetSoftContactFrequency)
        .addProperty("SoftContactDampingRatio", &GCPhysSurfacePropertiesPhysics::GetSoftContactDampingRatio, &GCPhysSurfacePropertiesPhysics::SetSoftContactDampingRatio)
        .addProperty("WheelDrag", &GCPhysSurfacePropertiesPhysics::GetWheelDrag, &GCPhysSurfacePropertiesPhysics::SetWheelDrag)
        .endClass();
}