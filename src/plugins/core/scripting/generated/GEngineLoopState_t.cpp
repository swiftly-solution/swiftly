#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEngineLoopState_t::GEngineLoopState_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEngineLoopState_t::GEngineLoopState_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GEngineLoopState_t::GetPlatWindowWidth() const {
    return GetSchemaValue<int32_t>(m_ptr, "EngineLoopState_t", "m_nPlatWindowWidth");
}
void GEngineLoopState_t::SetPlatWindowWidth(int32_t value) {
    SetSchemaValue(m_ptr, "EngineLoopState_t", "m_nPlatWindowWidth", true, value);
}
int32_t GEngineLoopState_t::GetPlatWindowHeight() const {
    return GetSchemaValue<int32_t>(m_ptr, "EngineLoopState_t", "m_nPlatWindowHeight");
}
void GEngineLoopState_t::SetPlatWindowHeight(int32_t value) {
    SetSchemaValue(m_ptr, "EngineLoopState_t", "m_nPlatWindowHeight", true, value);
}
int32_t GEngineLoopState_t::GetRenderWidth() const {
    return GetSchemaValue<int32_t>(m_ptr, "EngineLoopState_t", "m_nRenderWidth");
}
void GEngineLoopState_t::SetRenderWidth(int32_t value) {
    SetSchemaValue(m_ptr, "EngineLoopState_t", "m_nRenderWidth", true, value);
}
int32_t GEngineLoopState_t::GetRenderHeight() const {
    return GetSchemaValue<int32_t>(m_ptr, "EngineLoopState_t", "m_nRenderHeight");
}
void GEngineLoopState_t::SetRenderHeight(int32_t value) {
    SetSchemaValue(m_ptr, "EngineLoopState_t", "m_nRenderHeight", true, value);
}
std::string GEngineLoopState_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEngineLoopState_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEngineLoopState_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEngineLoopState_t>("EngineLoopState_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PlatWindowWidth", &GEngineLoopState_t::GetPlatWindowWidth, &GEngineLoopState_t::SetPlatWindowWidth)
        .addProperty("PlatWindowHeight", &GEngineLoopState_t::GetPlatWindowHeight, &GEngineLoopState_t::SetPlatWindowHeight)
        .addProperty("RenderWidth", &GEngineLoopState_t::GetRenderWidth, &GEngineLoopState_t::SetRenderWidth)
        .addProperty("RenderHeight", &GEngineLoopState_t::GetRenderHeight, &GEngineLoopState_t::SetRenderHeight)
        .addFunction("ToPtr", &GEngineLoopState_t::ToPtr)
        .addFunction("IsValid", &GEngineLoopState_t::IsValid)
        .endClass();
}