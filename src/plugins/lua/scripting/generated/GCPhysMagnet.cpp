#include "../../../core/scripting/generated/classes/GCPhysMagnet.h"
#include "../core.h"

void SetupLuaClassGCPhysMagnet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysMagnet>("CPhysMagnet")
        .addProperty("OnMagnetAttach", &GCPhysMagnet::GetOnMagnetAttach, &GCPhysMagnet::SetOnMagnetAttach)
        .addProperty("OnMagnetDetach", &GCPhysMagnet::GetOnMagnetDetach, &GCPhysMagnet::SetOnMagnetDetach)
        .addProperty("MassScale", &GCPhysMagnet::GetMassScale, &GCPhysMagnet::SetMassScale)
        .addProperty("ForceLimit", &GCPhysMagnet::GetForceLimit, &GCPhysMagnet::SetForceLimit)
        .addProperty("TorqueLimit", &GCPhysMagnet::GetTorqueLimit, &GCPhysMagnet::SetTorqueLimit)
        .addProperty("MagnettedEntities", &GCPhysMagnet::GetMagnettedEntities, &GCPhysMagnet::SetMagnettedEntities)
        .addProperty("Active", &GCPhysMagnet::GetActive, &GCPhysMagnet::SetActive)
        .addProperty("HasHitSomething", &GCPhysMagnet::GetHasHitSomething, &GCPhysMagnet::SetHasHitSomething)
        .addProperty("TotalMass", &GCPhysMagnet::GetTotalMass, &GCPhysMagnet::SetTotalMass)
        .addProperty("Radius", &GCPhysMagnet::GetRadius, &GCPhysMagnet::SetRadius)
        .addProperty("MaxObjectsAttached", &GCPhysMagnet::GetMaxObjectsAttached, &GCPhysMagnet::SetMaxObjectsAttached)
        .endClass();
}