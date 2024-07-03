#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLookComponentUpdater::GCLookComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLookComponentUpdater::GCLookComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
GCAnimParamHandle GCLookComponentUpdater::GetLookHeading() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CLookComponentUpdater", "m_hLookHeading"));
    return value;
}
void GCLookComponentUpdater::SetLookHeading(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookHeading", false, value);
}
GCAnimParamHandle GCLookComponentUpdater::GetLookHeadingVelocity() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CLookComponentUpdater", "m_hLookHeadingVelocity"));
    return value;
}
void GCLookComponentUpdater::SetLookHeadingVelocity(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookHeadingVelocity", false, value);
}
GCAnimParamHandle GCLookComponentUpdater::GetLookPitch() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CLookComponentUpdater", "m_hLookPitch"));
    return value;
}
void GCLookComponentUpdater::SetLookPitch(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookPitch", false, value);
}
GCAnimParamHandle GCLookComponentUpdater::GetLookDistance() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CLookComponentUpdater", "m_hLookDistance"));
    return value;
}
void GCLookComponentUpdater::SetLookDistance(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookDistance", false, value);
}
GCAnimParamHandle GCLookComponentUpdater::GetLookDirection() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CLookComponentUpdater", "m_hLookDirection"));
    return value;
}
void GCLookComponentUpdater::SetLookDirection(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookDirection", false, value);
}
GCAnimParamHandle GCLookComponentUpdater::GetLookTarget() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CLookComponentUpdater", "m_hLookTarget"));
    return value;
}
void GCLookComponentUpdater::SetLookTarget(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookTarget", false, value);
}
GCAnimParamHandle GCLookComponentUpdater::GetLookTargetWorldSpace() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CLookComponentUpdater", "m_hLookTargetWorldSpace"));
    return value;
}
void GCLookComponentUpdater::SetLookTargetWorldSpace(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookTargetWorldSpace", false, value);
}
bool GCLookComponentUpdater::GetNetworkLookTarget() const {
    return GetSchemaValue<bool>(m_ptr, "CLookComponentUpdater", "m_bNetworkLookTarget");
}
void GCLookComponentUpdater::SetNetworkLookTarget(bool value) {
    SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_bNetworkLookTarget", false, value);
}
std::string GCLookComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLookComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCLookComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCLookComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLookComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLookComponentUpdater>("CLookComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LookHeading", &GCLookComponentUpdater::GetLookHeading, &GCLookComponentUpdater::SetLookHeading)
        .addProperty("LookHeadingVelocity", &GCLookComponentUpdater::GetLookHeadingVelocity, &GCLookComponentUpdater::SetLookHeadingVelocity)
        .addProperty("LookPitch", &GCLookComponentUpdater::GetLookPitch, &GCLookComponentUpdater::SetLookPitch)
        .addProperty("LookDistance", &GCLookComponentUpdater::GetLookDistance, &GCLookComponentUpdater::SetLookDistance)
        .addProperty("LookDirection", &GCLookComponentUpdater::GetLookDirection, &GCLookComponentUpdater::SetLookDirection)
        .addProperty("LookTarget", &GCLookComponentUpdater::GetLookTarget, &GCLookComponentUpdater::SetLookTarget)
        .addProperty("LookTargetWorldSpace", &GCLookComponentUpdater::GetLookTargetWorldSpace, &GCLookComponentUpdater::SetLookTargetWorldSpace)
        .addProperty("NetworkLookTarget", &GCLookComponentUpdater::GetNetworkLookTarget, &GCLookComponentUpdater::SetNetworkLookTarget)
        .addProperty("Parent", &GCLookComponentUpdater::GetParent, &GCLookComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCLookComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCLookComponentUpdater::IsValid)
        .endClass();
}