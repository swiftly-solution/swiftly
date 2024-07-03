#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathTrack::GCPathTrack(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathTrack::GCPathTrack(void *ptr) {
    m_ptr = ptr;
}
GCPathTrack GCPathTrack::GetPnext() const {
    GCPathTrack value(*GetSchemaValuePtr<void*>(m_ptr, "CPathTrack", "m_pnext"));
    return value;
}
void GCPathTrack::SetPnext(GCPathTrack* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Pnext' is not possible.\n");
}
GCPathTrack GCPathTrack::GetPprevious() const {
    GCPathTrack value(*GetSchemaValuePtr<void*>(m_ptr, "CPathTrack", "m_pprevious"));
    return value;
}
void GCPathTrack::SetPprevious(GCPathTrack* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Pprevious' is not possible.\n");
}
GCPathTrack GCPathTrack::GetPaltpath() const {
    GCPathTrack value(*GetSchemaValuePtr<void*>(m_ptr, "CPathTrack", "m_paltpath"));
    return value;
}
void GCPathTrack::SetPaltpath(GCPathTrack* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Paltpath' is not possible.\n");
}
float GCPathTrack::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CPathTrack", "m_flRadius");
}
void GCPathTrack::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CPathTrack", "m_flRadius", false, value);
}
float GCPathTrack::GetLength() const {
    return GetSchemaValue<float>(m_ptr, "CPathTrack", "m_length");
}
void GCPathTrack::SetLength(float value) {
    SetSchemaValue(m_ptr, "CPathTrack", "m_length", false, value);
}
std::string GCPathTrack::GetAltName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPathTrack", "m_altName").String();
}
void GCPathTrack::SetAltName(std::string value) {
    SetSchemaValue(m_ptr, "CPathTrack", "m_altName", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCPathTrack::GetIterVal() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPathTrack", "m_nIterVal");
}
void GCPathTrack::SetIterVal(int32_t value) {
    SetSchemaValue(m_ptr, "CPathTrack", "m_nIterVal", false, value);
}
uint64_t GCPathTrack::GetOrientationType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPathTrack", "m_eOrientationType");
}
void GCPathTrack::SetOrientationType(uint64_t value) {
    SetSchemaValue(m_ptr, "CPathTrack", "m_eOrientationType", false, value);
}
GCEntityIOOutput GCPathTrack::GetOnPass() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPathTrack", "m_OnPass"));
    return value;
}
void GCPathTrack::SetOnPass(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPathTrack", "m_OnPass", false, value);
}
std::string GCPathTrack::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathTrack::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPathTrack::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPathTrack::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathTrack(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathTrack>("CPathTrack")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Pnext", &GCPathTrack::GetPnext, &GCPathTrack::SetPnext)
        .addProperty("Pprevious", &GCPathTrack::GetPprevious, &GCPathTrack::SetPprevious)
        .addProperty("Paltpath", &GCPathTrack::GetPaltpath, &GCPathTrack::SetPaltpath)
        .addProperty("Radius", &GCPathTrack::GetRadius, &GCPathTrack::SetRadius)
        .addProperty("Length", &GCPathTrack::GetLength, &GCPathTrack::SetLength)
        .addProperty("AltName", &GCPathTrack::GetAltName, &GCPathTrack::SetAltName)
        .addProperty("IterVal", &GCPathTrack::GetIterVal, &GCPathTrack::SetIterVal)
        .addProperty("OrientationType", &GCPathTrack::GetOrientationType, &GCPathTrack::SetOrientationType)
        .addProperty("OnPass", &GCPathTrack::GetOnPass, &GCPathTrack::SetOnPass)
        .addProperty("Parent", &GCPathTrack::GetParent, &GCPathTrack::SetParent)
        .addFunction("ToPtr", &GCPathTrack::ToPtr)
        .addFunction("IsValid", &GCPathTrack::IsValid)
        .endClass();
}