#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerSndSosOpvar::GCTriggerSndSosOpvar(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerSndSosOpvar::GCTriggerSndSosOpvar(void *ptr) {
    m_ptr = ptr;
}
Vector GCTriggerSndSosOpvar::GetPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CTriggerSndSosOpvar", "m_flPosition");
}
void GCTriggerSndSosOpvar::SetPosition(Vector value) {
    SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_flPosition", false, value);
}
float GCTriggerSndSosOpvar::GetCenterSize() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerSndSosOpvar", "m_flCenterSize");
}
void GCTriggerSndSosOpvar::SetCenterSize(float value) {
    SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_flCenterSize", false, value);
}
float GCTriggerSndSosOpvar::GetMinVal() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerSndSosOpvar", "m_flMinVal");
}
void GCTriggerSndSosOpvar::SetMinVal(float value) {
    SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_flMinVal", false, value);
}
float GCTriggerSndSosOpvar::GetMaxVal() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerSndSosOpvar", "m_flMaxVal");
}
void GCTriggerSndSosOpvar::SetMaxVal(float value) {
    SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_flMaxVal", false, value);
}
std::string GCTriggerSndSosOpvar::GetOpvarName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerSndSosOpvar", "m_opvarName").String();
}
void GCTriggerSndSosOpvar::SetOpvarName(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_opvarName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCTriggerSndSosOpvar::GetStackName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerSndSosOpvar", "m_stackName").String();
}
void GCTriggerSndSosOpvar::SetStackName(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_stackName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCTriggerSndSosOpvar::GetOperatorName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerSndSosOpvar", "m_operatorName").String();
}
void GCTriggerSndSosOpvar::SetOperatorName(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_operatorName", false, CUtlSymbolLarge(value.c_str()));
}
bool GCTriggerSndSosOpvar::GetVolIs2D() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerSndSosOpvar", "m_bVolIs2D");
}
void GCTriggerSndSosOpvar::SetVolIs2D(bool value) {
    SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_bVolIs2D", false, value);
}
std::string GCTriggerSndSosOpvar::GetOpvarNameChar() const {
    return GetSchemaValuePtr<char>(m_ptr, "CTriggerSndSosOpvar", "m_opvarNameChar");
}
void GCTriggerSndSosOpvar::SetOpvarNameChar(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CTriggerSndSosOpvar", "m_opvarNameChar", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 256);
}
std::string GCTriggerSndSosOpvar::GetStackNameChar() const {
    return GetSchemaValuePtr<char>(m_ptr, "CTriggerSndSosOpvar", "m_stackNameChar");
}
void GCTriggerSndSosOpvar::SetStackNameChar(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CTriggerSndSosOpvar", "m_stackNameChar", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 256);
}
std::string GCTriggerSndSosOpvar::GetOperatorNameChar() const {
    return GetSchemaValuePtr<char>(m_ptr, "CTriggerSndSosOpvar", "m_operatorNameChar");
}
void GCTriggerSndSosOpvar::SetOperatorNameChar(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CTriggerSndSosOpvar", "m_operatorNameChar", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 256);
}
Vector GCTriggerSndSosOpvar::GetVecNormPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CTriggerSndSosOpvar", "m_VecNormPos");
}
void GCTriggerSndSosOpvar::SetVecNormPos(Vector value) {
    SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_VecNormPos", false, value);
}
float GCTriggerSndSosOpvar::GetNormCenterSize() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerSndSosOpvar", "m_flNormCenterSize");
}
void GCTriggerSndSosOpvar::SetNormCenterSize(float value) {
    SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_flNormCenterSize", false, value);
}
std::string GCTriggerSndSosOpvar::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerSndSosOpvar::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerSndSosOpvar::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerSndSosOpvar::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerSndSosOpvar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerSndSosOpvar>("CTriggerSndSosOpvar")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Position", &GCTriggerSndSosOpvar::GetPosition, &GCTriggerSndSosOpvar::SetPosition)
        .addProperty("CenterSize", &GCTriggerSndSosOpvar::GetCenterSize, &GCTriggerSndSosOpvar::SetCenterSize)
        .addProperty("MinVal", &GCTriggerSndSosOpvar::GetMinVal, &GCTriggerSndSosOpvar::SetMinVal)
        .addProperty("MaxVal", &GCTriggerSndSosOpvar::GetMaxVal, &GCTriggerSndSosOpvar::SetMaxVal)
        .addProperty("OpvarName", &GCTriggerSndSosOpvar::GetOpvarName, &GCTriggerSndSosOpvar::SetOpvarName)
        .addProperty("StackName", &GCTriggerSndSosOpvar::GetStackName, &GCTriggerSndSosOpvar::SetStackName)
        .addProperty("OperatorName", &GCTriggerSndSosOpvar::GetOperatorName, &GCTriggerSndSosOpvar::SetOperatorName)
        .addProperty("VolIs2D", &GCTriggerSndSosOpvar::GetVolIs2D, &GCTriggerSndSosOpvar::SetVolIs2D)
        .addProperty("OpvarNameChar", &GCTriggerSndSosOpvar::GetOpvarNameChar, &GCTriggerSndSosOpvar::SetOpvarNameChar)
        .addProperty("StackNameChar", &GCTriggerSndSosOpvar::GetStackNameChar, &GCTriggerSndSosOpvar::SetStackNameChar)
        .addProperty("OperatorNameChar", &GCTriggerSndSosOpvar::GetOperatorNameChar, &GCTriggerSndSosOpvar::SetOperatorNameChar)
        .addProperty("VecNormPos", &GCTriggerSndSosOpvar::GetVecNormPos, &GCTriggerSndSosOpvar::SetVecNormPos)
        .addProperty("NormCenterSize", &GCTriggerSndSosOpvar::GetNormCenterSize, &GCTriggerSndSosOpvar::SetNormCenterSize)
        .addProperty("Parent", &GCTriggerSndSosOpvar::GetParent, &GCTriggerSndSosOpvar::SetParent)
        .addFunction("ToPtr", &GCTriggerSndSosOpvar::ToPtr)
        .addFunction("IsValid", &GCTriggerSndSosOpvar::IsValid)
        .endClass();
}