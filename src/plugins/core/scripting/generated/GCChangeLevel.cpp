#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCChangeLevel::GCChangeLevel(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCChangeLevel::GCChangeLevel(void *ptr) {
    m_ptr = ptr;
}
std::string GCChangeLevel::GetMapName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CChangeLevel", "m_sMapName").Get();
}
void GCChangeLevel::SetMapName(std::string value) {
    SetSchemaValue(m_ptr, "CChangeLevel", "m_sMapName", false, CUtlString(value.c_str()));
}
std::string GCChangeLevel::GetLandmarkName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CChangeLevel", "m_sLandmarkName").Get();
}
void GCChangeLevel::SetLandmarkName(std::string value) {
    SetSchemaValue(m_ptr, "CChangeLevel", "m_sLandmarkName", false, CUtlString(value.c_str()));
}
GCEntityIOOutput GCChangeLevel::GetOnChangeLevel() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CChangeLevel", "m_OnChangeLevel"));
    return value;
}
void GCChangeLevel::SetOnChangeLevel(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CChangeLevel", "m_OnChangeLevel", false, value);
}
bool GCChangeLevel::GetTouched() const {
    return GetSchemaValue<bool>(m_ptr, "CChangeLevel", "m_bTouched");
}
void GCChangeLevel::SetTouched(bool value) {
    SetSchemaValue(m_ptr, "CChangeLevel", "m_bTouched", false, value);
}
bool GCChangeLevel::GetNoTouch() const {
    return GetSchemaValue<bool>(m_ptr, "CChangeLevel", "m_bNoTouch");
}
void GCChangeLevel::SetNoTouch(bool value) {
    SetSchemaValue(m_ptr, "CChangeLevel", "m_bNoTouch", false, value);
}
bool GCChangeLevel::GetNewChapter() const {
    return GetSchemaValue<bool>(m_ptr, "CChangeLevel", "m_bNewChapter");
}
void GCChangeLevel::SetNewChapter(bool value) {
    SetSchemaValue(m_ptr, "CChangeLevel", "m_bNewChapter", false, value);
}
bool GCChangeLevel::GetOnChangeLevelFired() const {
    return GetSchemaValue<bool>(m_ptr, "CChangeLevel", "m_bOnChangeLevelFired");
}
void GCChangeLevel::SetOnChangeLevelFired(bool value) {
    SetSchemaValue(m_ptr, "CChangeLevel", "m_bOnChangeLevelFired", false, value);
}
std::string GCChangeLevel::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCChangeLevel::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCChangeLevel::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCChangeLevel::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCChangeLevel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCChangeLevel>("CChangeLevel")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MapName", &GCChangeLevel::GetMapName, &GCChangeLevel::SetMapName)
        .addProperty("LandmarkName", &GCChangeLevel::GetLandmarkName, &GCChangeLevel::SetLandmarkName)
        .addProperty("OnChangeLevel", &GCChangeLevel::GetOnChangeLevel, &GCChangeLevel::SetOnChangeLevel)
        .addProperty("Touched", &GCChangeLevel::GetTouched, &GCChangeLevel::SetTouched)
        .addProperty("NoTouch", &GCChangeLevel::GetNoTouch, &GCChangeLevel::SetNoTouch)
        .addProperty("NewChapter", &GCChangeLevel::GetNewChapter, &GCChangeLevel::SetNewChapter)
        .addProperty("OnChangeLevelFired", &GCChangeLevel::GetOnChangeLevelFired, &GCChangeLevel::SetOnChangeLevelFired)
        .addProperty("Parent", &GCChangeLevel::GetParent, &GCChangeLevel::SetParent)
        .addFunction("ToPtr", &GCChangeLevel::ToPtr)
        .addFunction("IsValid", &GCChangeLevel::IsValid)
        .endClass();
}