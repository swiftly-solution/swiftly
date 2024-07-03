#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimDesc_Flag::GCAnimDesc_Flag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimDesc_Flag::GCAnimDesc_Flag(void *ptr) {
    m_ptr = ptr;
}
bool GCAnimDesc_Flag::GetLooping() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bLooping");
}
void GCAnimDesc_Flag::SetLooping(bool value) {
    SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bLooping", false, value);
}
bool GCAnimDesc_Flag::GetAllZeros() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bAllZeros");
}
void GCAnimDesc_Flag::SetAllZeros(bool value) {
    SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bAllZeros", false, value);
}
bool GCAnimDesc_Flag::GetHidden() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bHidden");
}
void GCAnimDesc_Flag::SetHidden(bool value) {
    SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bHidden", false, value);
}
bool GCAnimDesc_Flag::GetDelta() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bDelta");
}
void GCAnimDesc_Flag::SetDelta(bool value) {
    SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bDelta", false, value);
}
bool GCAnimDesc_Flag::GetLegacyWorldspace() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bLegacyWorldspace");
}
void GCAnimDesc_Flag::SetLegacyWorldspace(bool value) {
    SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bLegacyWorldspace", false, value);
}
bool GCAnimDesc_Flag::GetModelDoc() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bModelDoc");
}
void GCAnimDesc_Flag::SetModelDoc(bool value) {
    SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bModelDoc", false, value);
}
bool GCAnimDesc_Flag::GetImplicitSeqIgnoreDelta() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bImplicitSeqIgnoreDelta");
}
void GCAnimDesc_Flag::SetImplicitSeqIgnoreDelta(bool value) {
    SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bImplicitSeqIgnoreDelta", false, value);
}
bool GCAnimDesc_Flag::GetAnimGraphAdditive() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bAnimGraphAdditive");
}
void GCAnimDesc_Flag::SetAnimGraphAdditive(bool value) {
    SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bAnimGraphAdditive", false, value);
}
std::string GCAnimDesc_Flag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimDesc_Flag::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimDesc_Flag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimDesc_Flag>("CAnimDesc_Flag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Looping", &GCAnimDesc_Flag::GetLooping, &GCAnimDesc_Flag::SetLooping)
        .addProperty("AllZeros", &GCAnimDesc_Flag::GetAllZeros, &GCAnimDesc_Flag::SetAllZeros)
        .addProperty("Hidden", &GCAnimDesc_Flag::GetHidden, &GCAnimDesc_Flag::SetHidden)
        .addProperty("Delta", &GCAnimDesc_Flag::GetDelta, &GCAnimDesc_Flag::SetDelta)
        .addProperty("LegacyWorldspace", &GCAnimDesc_Flag::GetLegacyWorldspace, &GCAnimDesc_Flag::SetLegacyWorldspace)
        .addProperty("ModelDoc", &GCAnimDesc_Flag::GetModelDoc, &GCAnimDesc_Flag::SetModelDoc)
        .addProperty("ImplicitSeqIgnoreDelta", &GCAnimDesc_Flag::GetImplicitSeqIgnoreDelta, &GCAnimDesc_Flag::SetImplicitSeqIgnoreDelta)
        .addProperty("AnimGraphAdditive", &GCAnimDesc_Flag::GetAnimGraphAdditive, &GCAnimDesc_Flag::SetAnimGraphAdditive)
        .addFunction("ToPtr", &GCAnimDesc_Flag::ToPtr)
        .addFunction("IsValid", &GCAnimDesc_Flag::IsValid)
        .endClass();
}