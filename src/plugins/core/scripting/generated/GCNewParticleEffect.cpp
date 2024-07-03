#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNewParticleEffect::GCNewParticleEffect(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNewParticleEffect::GCNewParticleEffect(void *ptr) {
    m_ptr = ptr;
}
GCNewParticleEffect GCNewParticleEffect::GetNext() const {
    GCNewParticleEffect value(*GetSchemaValuePtr<void*>(m_ptr, "CNewParticleEffect", "m_pNext"));
    return value;
}
void GCNewParticleEffect::SetNext(GCNewParticleEffect* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n");
}
GCNewParticleEffect GCNewParticleEffect::GetPrev() const {
    GCNewParticleEffect value(*GetSchemaValuePtr<void*>(m_ptr, "CNewParticleEffect", "m_pPrev"));
    return value;
}
void GCNewParticleEffect::SetPrev(GCNewParticleEffect* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Prev' is not possible.\n");
}
GIParticleCollection GCNewParticleEffect::GetParticles() const {
    GIParticleCollection value(*GetSchemaValuePtr<void*>(m_ptr, "CNewParticleEffect", "m_pParticles"));
    return value;
}
void GCNewParticleEffect::SetParticles(GIParticleCollection* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Particles' is not possible.\n");
}
std::string GCNewParticleEffect::GetDebugName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CNewParticleEffect", "m_pDebugName");
}
void GCNewParticleEffect::SetDebugName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CNewParticleEffect", "m_pDebugName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
Vector GCNewParticleEffect::GetSortOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CNewParticleEffect", "m_vSortOrigin");
}
void GCNewParticleEffect::SetSortOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_vSortOrigin", false, value);
}
float GCNewParticleEffect::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CNewParticleEffect", "m_flScale");
}
void GCNewParticleEffect::SetScale(float value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_flScale", false, value);
}
GPARTICLE_EHANDLE__ GCNewParticleEffect::GetOwner() const {
    GPARTICLE_EHANDLE__ value(*GetSchemaValuePtr<void*>(m_ptr, "CNewParticleEffect", "m_hOwner"));
    return value;
}
void GCNewParticleEffect::SetOwner(GPARTICLE_EHANDLE__* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n");
}
GCParticleProperty GCNewParticleEffect::GetOwningParticleProperty() const {
    GCParticleProperty value(*GetSchemaValuePtr<void*>(m_ptr, "CNewParticleEffect", "m_pOwningParticleProperty"));
    return value;
}
void GCNewParticleEffect::SetOwningParticleProperty(GCParticleProperty* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'OwningParticleProperty' is not possible.\n");
}
float GCNewParticleEffect::GetFreezeTransitionStart() const {
    return GetSchemaValue<float>(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionStart");
}
void GCNewParticleEffect::SetFreezeTransitionStart(float value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionStart", false, value);
}
float GCNewParticleEffect::GetFreezeTransitionDuration() const {
    return GetSchemaValue<float>(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionDuration");
}
void GCNewParticleEffect::SetFreezeTransitionDuration(float value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionDuration", false, value);
}
float GCNewParticleEffect::GetFreezeTransitionOverride() const {
    return GetSchemaValue<float>(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionOverride");
}
void GCNewParticleEffect::SetFreezeTransitionOverride(float value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionOverride", false, value);
}
bool GCNewParticleEffect::GetFreezeTransitionActive() const {
    return GetSchemaValue<bool>(m_ptr, "CNewParticleEffect", "m_bFreezeTransitionActive");
}
void GCNewParticleEffect::SetFreezeTransitionActive(bool value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_bFreezeTransitionActive", false, value);
}
bool GCNewParticleEffect::GetFreezeTargetState() const {
    return GetSchemaValue<bool>(m_ptr, "CNewParticleEffect", "m_bFreezeTargetState");
}
void GCNewParticleEffect::SetFreezeTargetState(bool value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_bFreezeTargetState", false, value);
}
bool GCNewParticleEffect::GetCanFreeze() const {
    return GetSchemaValue<bool>(m_ptr, "CNewParticleEffect", "m_bCanFreeze");
}
void GCNewParticleEffect::SetCanFreeze(bool value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_bCanFreeze", false, value);
}
Vector GCNewParticleEffect::GetLastMin() const {
    return GetSchemaValue<Vector>(m_ptr, "CNewParticleEffect", "m_LastMin");
}
void GCNewParticleEffect::SetLastMin(Vector value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_LastMin", false, value);
}
Vector GCNewParticleEffect::GetLastMax() const {
    return GetSchemaValue<Vector>(m_ptr, "CNewParticleEffect", "m_LastMax");
}
void GCNewParticleEffect::SetLastMax(Vector value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_LastMax", false, value);
}
int32_t GCNewParticleEffect::GetSplitScreenUser() const {
    return GetSchemaValue<int32_t>(m_ptr, "CNewParticleEffect", "m_nSplitScreenUser");
}
void GCNewParticleEffect::SetSplitScreenUser(int32_t value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_nSplitScreenUser", false, value);
}
Vector GCNewParticleEffect::GetAggregationCenter() const {
    return GetSchemaValue<Vector>(m_ptr, "CNewParticleEffect", "m_vecAggregationCenter");
}
void GCNewParticleEffect::SetAggregationCenter(Vector value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_vecAggregationCenter", false, value);
}
int32_t GCNewParticleEffect::GetRefCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CNewParticleEffect", "m_RefCount");
}
void GCNewParticleEffect::SetRefCount(int32_t value) {
    SetSchemaValue(m_ptr, "CNewParticleEffect", "m_RefCount", false, value);
}
std::string GCNewParticleEffect::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNewParticleEffect::IsValid() {
    return (m_ptr != nullptr);
}
GIParticleEffect GCNewParticleEffect::GetParent() const {
    GIParticleEffect value(m_ptr);
    return value;
}
void GCNewParticleEffect::SetParent(GIParticleEffect value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNewParticleEffect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNewParticleEffect>("CNewParticleEffect")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Next", &GCNewParticleEffect::GetNext, &GCNewParticleEffect::SetNext)
        .addProperty("Prev", &GCNewParticleEffect::GetPrev, &GCNewParticleEffect::SetPrev)
        .addProperty("Particles", &GCNewParticleEffect::GetParticles, &GCNewParticleEffect::SetParticles)
        .addProperty("DebugName", &GCNewParticleEffect::GetDebugName, &GCNewParticleEffect::SetDebugName)
        .addProperty("SortOrigin", &GCNewParticleEffect::GetSortOrigin, &GCNewParticleEffect::SetSortOrigin)
        .addProperty("Scale", &GCNewParticleEffect::GetScale, &GCNewParticleEffect::SetScale)
        .addProperty("Owner", &GCNewParticleEffect::GetOwner, &GCNewParticleEffect::SetOwner)
        .addProperty("OwningParticleProperty", &GCNewParticleEffect::GetOwningParticleProperty, &GCNewParticleEffect::SetOwningParticleProperty)
        .addProperty("FreezeTransitionStart", &GCNewParticleEffect::GetFreezeTransitionStart, &GCNewParticleEffect::SetFreezeTransitionStart)
        .addProperty("FreezeTransitionDuration", &GCNewParticleEffect::GetFreezeTransitionDuration, &GCNewParticleEffect::SetFreezeTransitionDuration)
        .addProperty("FreezeTransitionOverride", &GCNewParticleEffect::GetFreezeTransitionOverride, &GCNewParticleEffect::SetFreezeTransitionOverride)
        .addProperty("FreezeTransitionActive", &GCNewParticleEffect::GetFreezeTransitionActive, &GCNewParticleEffect::SetFreezeTransitionActive)
        .addProperty("FreezeTargetState", &GCNewParticleEffect::GetFreezeTargetState, &GCNewParticleEffect::SetFreezeTargetState)
        .addProperty("CanFreeze", &GCNewParticleEffect::GetCanFreeze, &GCNewParticleEffect::SetCanFreeze)
        .addProperty("LastMin", &GCNewParticleEffect::GetLastMin, &GCNewParticleEffect::SetLastMin)
        .addProperty("LastMax", &GCNewParticleEffect::GetLastMax, &GCNewParticleEffect::SetLastMax)
        .addProperty("SplitScreenUser", &GCNewParticleEffect::GetSplitScreenUser, &GCNewParticleEffect::SetSplitScreenUser)
        .addProperty("AggregationCenter", &GCNewParticleEffect::GetAggregationCenter, &GCNewParticleEffect::SetAggregationCenter)
        .addProperty("RefCount", &GCNewParticleEffect::GetRefCount, &GCNewParticleEffect::SetRefCount)
        .addProperty("Parent", &GCNewParticleEffect::GetParent, &GCNewParticleEffect::SetParent)
        .addFunction("ToPtr", &GCNewParticleEffect::ToPtr)
        .addFunction("IsValid", &GCNewParticleEffect::IsValid)
        .endClass();
}