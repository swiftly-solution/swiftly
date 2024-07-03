#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixFreeverbDesc_t::GVMixFreeverbDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixFreeverbDesc_t::GVMixFreeverbDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixFreeverbDesc_t::GetRoomSize() const {
    return GetSchemaValue<float>(m_ptr, "VMixFreeverbDesc_t", "m_flRoomSize");
}
void GVMixFreeverbDesc_t::SetRoomSize(float value) {
    SetSchemaValue(m_ptr, "VMixFreeverbDesc_t", "m_flRoomSize", true, value);
}
float GVMixFreeverbDesc_t::GetDamp() const {
    return GetSchemaValue<float>(m_ptr, "VMixFreeverbDesc_t", "m_flDamp");
}
void GVMixFreeverbDesc_t::SetDamp(float value) {
    SetSchemaValue(m_ptr, "VMixFreeverbDesc_t", "m_flDamp", true, value);
}
float GVMixFreeverbDesc_t::GetWidth() const {
    return GetSchemaValue<float>(m_ptr, "VMixFreeverbDesc_t", "m_flWidth");
}
void GVMixFreeverbDesc_t::SetWidth(float value) {
    SetSchemaValue(m_ptr, "VMixFreeverbDesc_t", "m_flWidth", true, value);
}
float GVMixFreeverbDesc_t::GetLateReflections() const {
    return GetSchemaValue<float>(m_ptr, "VMixFreeverbDesc_t", "m_flLateReflections");
}
void GVMixFreeverbDesc_t::SetLateReflections(float value) {
    SetSchemaValue(m_ptr, "VMixFreeverbDesc_t", "m_flLateReflections", true, value);
}
std::string GVMixFreeverbDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixFreeverbDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixFreeverbDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixFreeverbDesc_t>("VMixFreeverbDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RoomSize", &GVMixFreeverbDesc_t::GetRoomSize, &GVMixFreeverbDesc_t::SetRoomSize)
        .addProperty("Damp", &GVMixFreeverbDesc_t::GetDamp, &GVMixFreeverbDesc_t::SetDamp)
        .addProperty("Width", &GVMixFreeverbDesc_t::GetWidth, &GVMixFreeverbDesc_t::SetWidth)
        .addProperty("LateReflections", &GVMixFreeverbDesc_t::GetLateReflections, &GVMixFreeverbDesc_t::SetLateReflections)
        .addFunction("ToPtr", &GVMixFreeverbDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixFreeverbDesc_t::IsValid)
        .endClass();
}