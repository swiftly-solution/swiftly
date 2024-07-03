#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVoxelVisBlockOffset_t::GVoxelVisBlockOffset_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVoxelVisBlockOffset_t::GVoxelVisBlockOffset_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GVoxelVisBlockOffset_t::GetOffset() const {
    return GetSchemaValue<uint32_t>(m_ptr, "VoxelVisBlockOffset_t", "m_nOffset");
}
void GVoxelVisBlockOffset_t::SetOffset(uint32_t value) {
    SetSchemaValue(m_ptr, "VoxelVisBlockOffset_t", "m_nOffset", true, value);
}
uint32_t GVoxelVisBlockOffset_t::GetElementCount() const {
    return GetSchemaValue<uint32_t>(m_ptr, "VoxelVisBlockOffset_t", "m_nElementCount");
}
void GVoxelVisBlockOffset_t::SetElementCount(uint32_t value) {
    SetSchemaValue(m_ptr, "VoxelVisBlockOffset_t", "m_nElementCount", true, value);
}
std::string GVoxelVisBlockOffset_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVoxelVisBlockOffset_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVoxelVisBlockOffset_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVoxelVisBlockOffset_t>("VoxelVisBlockOffset_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Offset", &GVoxelVisBlockOffset_t::GetOffset, &GVoxelVisBlockOffset_t::SetOffset)
        .addProperty("ElementCount", &GVoxelVisBlockOffset_t::GetElementCount, &GVoxelVisBlockOffset_t::SetElementCount)
        .addFunction("ToPtr", &GVoxelVisBlockOffset_t::ToPtr)
        .addFunction("IsValid", &GVoxelVisBlockOffset_t::IsValid)
        .endClass();
}