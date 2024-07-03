#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimDataChannelDesc::GCAnimDataChannelDesc(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimDataChannelDesc::GCAnimDataChannelDesc(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimDataChannelDesc::GetChannelClass() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimDataChannelDesc", "m_szChannelClass");
}
void GCAnimDataChannelDesc::SetChannelClass(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_szChannelClass", false, value);
}
CBufferString GCAnimDataChannelDesc::GetVariableName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimDataChannelDesc", "m_szVariableName");
}
void GCAnimDataChannelDesc::SetVariableName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_szVariableName", false, value);
}
int32_t GCAnimDataChannelDesc::GetFlags() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimDataChannelDesc", "m_nFlags");
}
void GCAnimDataChannelDesc::SetFlags(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_nFlags", false, value);
}
int32_t GCAnimDataChannelDesc::GetType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimDataChannelDesc", "m_nType");
}
void GCAnimDataChannelDesc::SetType(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_nType", false, value);
}
CBufferString GCAnimDataChannelDesc::GetGrouping() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimDataChannelDesc", "m_szGrouping");
}
void GCAnimDataChannelDesc::SetGrouping(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_szGrouping", false, value);
}
CBufferString GCAnimDataChannelDesc::GetDescription() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimDataChannelDesc", "m_szDescription");
}
void GCAnimDataChannelDesc::SetDescription(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_szDescription", false, value);
}
std::vector<CBufferString> GCAnimDataChannelDesc::GetElementNameArray() const {
    CUtlVector<CBufferString>* vec = GetSchemaValue<CUtlVector<CBufferString>*>(m_ptr, "CAnimDataChannelDesc", "m_szElementNameArray"); std::vector<CBufferString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDataChannelDesc::SetElementNameArray(std::vector<CBufferString> value) {
    SetSchemaValueCUtlVector<CBufferString>(m_ptr, "CAnimDataChannelDesc", "m_szElementNameArray", false, value);
}
std::vector<int32> GCAnimDataChannelDesc::GetElementIndexArray() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimDataChannelDesc", "m_nElementIndexArray"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDataChannelDesc::SetElementIndexArray(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimDataChannelDesc", "m_nElementIndexArray", false, value);
}
std::vector<uint32> GCAnimDataChannelDesc::GetElementMaskArray() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAnimDataChannelDesc", "m_nElementMaskArray"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDataChannelDesc::SetElementMaskArray(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CAnimDataChannelDesc", "m_nElementMaskArray", false, value);
}
std::string GCAnimDataChannelDesc::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimDataChannelDesc::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimDataChannelDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimDataChannelDesc>("CAnimDataChannelDesc")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChannelClass", &GCAnimDataChannelDesc::GetChannelClass, &GCAnimDataChannelDesc::SetChannelClass)
        .addProperty("VariableName", &GCAnimDataChannelDesc::GetVariableName, &GCAnimDataChannelDesc::SetVariableName)
        .addProperty("Flags", &GCAnimDataChannelDesc::GetFlags, &GCAnimDataChannelDesc::SetFlags)
        .addProperty("Type", &GCAnimDataChannelDesc::GetType, &GCAnimDataChannelDesc::SetType)
        .addProperty("Grouping", &GCAnimDataChannelDesc::GetGrouping, &GCAnimDataChannelDesc::SetGrouping)
        .addProperty("Description", &GCAnimDataChannelDesc::GetDescription, &GCAnimDataChannelDesc::SetDescription)
        .addProperty("ElementNameArray", &GCAnimDataChannelDesc::GetElementNameArray, &GCAnimDataChannelDesc::SetElementNameArray)
        .addProperty("ElementIndexArray", &GCAnimDataChannelDesc::GetElementIndexArray, &GCAnimDataChannelDesc::SetElementIndexArray)
        .addProperty("ElementMaskArray", &GCAnimDataChannelDesc::GetElementMaskArray, &GCAnimDataChannelDesc::SetElementMaskArray)
        .addFunction("ToPtr", &GCAnimDataChannelDesc::ToPtr)
        .addFunction("IsValid", &GCAnimDataChannelDesc::IsValid)
        .endClass();
}