#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GWorldNodeOnDiskBufferData_t::GWorldNodeOnDiskBufferData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GWorldNodeOnDiskBufferData_t::GWorldNodeOnDiskBufferData_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GWorldNodeOnDiskBufferData_t::GetElementCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_nElementCount");
}
void GWorldNodeOnDiskBufferData_t::SetElementCount(int32_t value) {
    SetSchemaValue(m_ptr, "WorldNodeOnDiskBufferData_t", "m_nElementCount", true, value);
}
int32_t GWorldNodeOnDiskBufferData_t::GetElementSizeInBytes() const {
    return GetSchemaValue<int32_t>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_nElementSizeInBytes");
}
void GWorldNodeOnDiskBufferData_t::SetElementSizeInBytes(int32_t value) {
    SetSchemaValue(m_ptr, "WorldNodeOnDiskBufferData_t", "m_nElementSizeInBytes", true, value);
}
std::vector<GRenderInputLayoutField_t> GWorldNodeOnDiskBufferData_t::GetInputLayoutFields() const {
    CUtlVector<GRenderInputLayoutField_t>* vec = GetSchemaValue<CUtlVector<GRenderInputLayoutField_t>*>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_inputLayoutFields"); std::vector<GRenderInputLayoutField_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNodeOnDiskBufferData_t::SetInputLayoutFields(std::vector<GRenderInputLayoutField_t> value) {
    SetSchemaValueCUtlVector<GRenderInputLayoutField_t>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_inputLayoutFields", true, value);
}
std::vector<uint8> GWorldNodeOnDiskBufferData_t::GetData() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_pData"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNodeOnDiskBufferData_t::SetData(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_pData", true, value);
}
std::string GWorldNodeOnDiskBufferData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GWorldNodeOnDiskBufferData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassWorldNodeOnDiskBufferData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWorldNodeOnDiskBufferData_t>("WorldNodeOnDiskBufferData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ElementCount", &GWorldNodeOnDiskBufferData_t::GetElementCount, &GWorldNodeOnDiskBufferData_t::SetElementCount)
        .addProperty("ElementSizeInBytes", &GWorldNodeOnDiskBufferData_t::GetElementSizeInBytes, &GWorldNodeOnDiskBufferData_t::SetElementSizeInBytes)
        .addProperty("InputLayoutFields", &GWorldNodeOnDiskBufferData_t::GetInputLayoutFields, &GWorldNodeOnDiskBufferData_t::SetInputLayoutFields)
        .addProperty("Data", &GWorldNodeOnDiskBufferData_t::GetData, &GWorldNodeOnDiskBufferData_t::SetData)
        .addFunction("ToPtr", &GWorldNodeOnDiskBufferData_t::ToPtr)
        .addFunction("IsValid", &GWorldNodeOnDiskBufferData_t::IsValid)
        .endClass();
}