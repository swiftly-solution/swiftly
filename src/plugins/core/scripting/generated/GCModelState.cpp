#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelState::GCModelState(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelState::GCModelState(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelState::GetModelName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CModelState", "m_ModelName").String();
}
void GCModelState::SetModelName(std::string value) {
    SetSchemaValue(m_ptr, "CModelState", "m_ModelName", false, CUtlSymbolLarge(value.c_str()));
}
bool GCModelState::GetClientClothCreationSuppressed() const {
    return GetSchemaValue<bool>(m_ptr, "CModelState", "m_bClientClothCreationSuppressed");
}
void GCModelState::SetClientClothCreationSuppressed(bool value) {
    SetSchemaValue(m_ptr, "CModelState", "m_bClientClothCreationSuppressed", false, value);
}
uint64_t GCModelState::GetMeshGroupMask() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CModelState", "m_MeshGroupMask");
}
void GCModelState::SetMeshGroupMask(uint64_t value) {
    SetSchemaValue(m_ptr, "CModelState", "m_MeshGroupMask", false, value);
}
int8_t GCModelState::GetIdealMotionType() const {
    return GetSchemaValue<int8_t>(m_ptr, "CModelState", "m_nIdealMotionType");
}
void GCModelState::SetIdealMotionType(int8_t value) {
    SetSchemaValue(m_ptr, "CModelState", "m_nIdealMotionType", false, value);
}
int8_t GCModelState::GetForceLOD() const {
    return GetSchemaValue<int8_t>(m_ptr, "CModelState", "m_nForceLOD");
}
void GCModelState::SetForceLOD(int8_t value) {
    SetSchemaValue(m_ptr, "CModelState", "m_nForceLOD", false, value);
}
int8_t GCModelState::GetClothUpdateFlags() const {
    return GetSchemaValue<int8_t>(m_ptr, "CModelState", "m_nClothUpdateFlags");
}
void GCModelState::SetClothUpdateFlags(int8_t value) {
    SetSchemaValue(m_ptr, "CModelState", "m_nClothUpdateFlags", false, value);
}
std::string GCModelState::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelState::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCModelState(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelState>("CModelState")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ModelName", &GCModelState::GetModelName, &GCModelState::SetModelName)
        .addProperty("ClientClothCreationSuppressed", &GCModelState::GetClientClothCreationSuppressed, &GCModelState::SetClientClothCreationSuppressed)
        .addProperty("MeshGroupMask", &GCModelState::GetMeshGroupMask, &GCModelState::SetMeshGroupMask)
        .addProperty("IdealMotionType", &GCModelState::GetIdealMotionType, &GCModelState::SetIdealMotionType)
        .addProperty("ForceLOD", &GCModelState::GetForceLOD, &GCModelState::SetForceLOD)
        .addProperty("ClothUpdateFlags", &GCModelState::GetClothUpdateFlags, &GCModelState::SetClothUpdateFlags)
        .addFunction("ToPtr", &GCModelState::ToPtr)
        .addFunction("IsValid", &GCModelState::IsValid)
        .endClass();
}