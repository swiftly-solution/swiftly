#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncMoveLinear::GCFuncMoveLinear(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncMoveLinear::GCFuncMoveLinear(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCFuncMoveLinear::GetAuthoredPosition() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFuncMoveLinear", "m_authoredPosition");
}
void GCFuncMoveLinear::SetAuthoredPosition(uint64_t value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_authoredPosition", false, value);
}
QAngle GCFuncMoveLinear::GetMoveEntitySpace() const {
    return GetSchemaValue<QAngle>(m_ptr, "CFuncMoveLinear", "m_angMoveEntitySpace");
}
void GCFuncMoveLinear::SetMoveEntitySpace(QAngle value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_angMoveEntitySpace", false, value);
}
Vector GCFuncMoveLinear::GetMoveDirParentSpace() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncMoveLinear", "m_vecMoveDirParentSpace");
}
void GCFuncMoveLinear::SetMoveDirParentSpace(Vector value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_vecMoveDirParentSpace", false, value);
}
std::string GCFuncMoveLinear::GetSoundStart() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncMoveLinear", "m_soundStart").String();
}
void GCFuncMoveLinear::SetSoundStart(std::string value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_soundStart", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncMoveLinear::GetSoundStop() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncMoveLinear", "m_soundStop").String();
}
void GCFuncMoveLinear::SetSoundStop(std::string value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_soundStop", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncMoveLinear::GetCurrentSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncMoveLinear", "m_currentSound").String();
}
void GCFuncMoveLinear::SetCurrentSound(std::string value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_currentSound", false, CUtlSymbolLarge(value.c_str()));
}
float GCFuncMoveLinear::GetBlockDamage() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMoveLinear", "m_flBlockDamage");
}
void GCFuncMoveLinear::SetBlockDamage(float value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_flBlockDamage", false, value);
}
float GCFuncMoveLinear::GetStartPosition() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMoveLinear", "m_flStartPosition");
}
void GCFuncMoveLinear::SetStartPosition(float value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_flStartPosition", false, value);
}
GCEntityIOOutput GCFuncMoveLinear::GetOnFullyOpen() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncMoveLinear", "m_OnFullyOpen"));
    return value;
}
void GCFuncMoveLinear::SetOnFullyOpen(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_OnFullyOpen", false, value);
}
GCEntityIOOutput GCFuncMoveLinear::GetOnFullyClosed() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncMoveLinear", "m_OnFullyClosed"));
    return value;
}
void GCFuncMoveLinear::SetOnFullyClosed(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_OnFullyClosed", false, value);
}
bool GCFuncMoveLinear::GetCreateMovableNavMesh() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMoveLinear", "m_bCreateMovableNavMesh");
}
void GCFuncMoveLinear::SetCreateMovableNavMesh(bool value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_bCreateMovableNavMesh", false, value);
}
bool GCFuncMoveLinear::GetCreateNavObstacle() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMoveLinear", "m_bCreateNavObstacle");
}
void GCFuncMoveLinear::SetCreateNavObstacle(bool value) {
    SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_bCreateNavObstacle", false, value);
}
std::string GCFuncMoveLinear::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncMoveLinear::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseToggle GCFuncMoveLinear::GetParent() const {
    GCBaseToggle value(m_ptr);
    return value;
}
void GCFuncMoveLinear::SetParent(GCBaseToggle value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncMoveLinear(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncMoveLinear>("CFuncMoveLinear")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AuthoredPosition", &GCFuncMoveLinear::GetAuthoredPosition, &GCFuncMoveLinear::SetAuthoredPosition)
        .addProperty("MoveEntitySpace", &GCFuncMoveLinear::GetMoveEntitySpace, &GCFuncMoveLinear::SetMoveEntitySpace)
        .addProperty("MoveDirParentSpace", &GCFuncMoveLinear::GetMoveDirParentSpace, &GCFuncMoveLinear::SetMoveDirParentSpace)
        .addProperty("SoundStart", &GCFuncMoveLinear::GetSoundStart, &GCFuncMoveLinear::SetSoundStart)
        .addProperty("SoundStop", &GCFuncMoveLinear::GetSoundStop, &GCFuncMoveLinear::SetSoundStop)
        .addProperty("CurrentSound", &GCFuncMoveLinear::GetCurrentSound, &GCFuncMoveLinear::SetCurrentSound)
        .addProperty("BlockDamage", &GCFuncMoveLinear::GetBlockDamage, &GCFuncMoveLinear::SetBlockDamage)
        .addProperty("StartPosition", &GCFuncMoveLinear::GetStartPosition, &GCFuncMoveLinear::SetStartPosition)
        .addProperty("OnFullyOpen", &GCFuncMoveLinear::GetOnFullyOpen, &GCFuncMoveLinear::SetOnFullyOpen)
        .addProperty("OnFullyClosed", &GCFuncMoveLinear::GetOnFullyClosed, &GCFuncMoveLinear::SetOnFullyClosed)
        .addProperty("CreateMovableNavMesh", &GCFuncMoveLinear::GetCreateMovableNavMesh, &GCFuncMoveLinear::SetCreateMovableNavMesh)
        .addProperty("CreateNavObstacle", &GCFuncMoveLinear::GetCreateNavObstacle, &GCFuncMoveLinear::SetCreateNavObstacle)
        .addProperty("Parent", &GCFuncMoveLinear::GetParent, &GCFuncMoveLinear::SetParent)
        .addFunction("ToPtr", &GCFuncMoveLinear::ToPtr)
        .addFunction("IsValid", &GCFuncMoveLinear::IsValid)
        .endClass();
}