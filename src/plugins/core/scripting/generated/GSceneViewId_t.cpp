#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSceneViewId_t::GSceneViewId_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSceneViewId_t::GSceneViewId_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GSceneViewId_t::GetViewId() const {
    return GetSchemaValue<uint64_t>(m_ptr, "SceneViewId_t", "m_nViewId");
}
void GSceneViewId_t::SetViewId(uint64_t value) {
    SetSchemaValue(m_ptr, "SceneViewId_t", "m_nViewId", true, value);
}
uint64_t GSceneViewId_t::GetFrameCount() const {
    return GetSchemaValue<uint64_t>(m_ptr, "SceneViewId_t", "m_nFrameCount");
}
void GSceneViewId_t::SetFrameCount(uint64_t value) {
    SetSchemaValue(m_ptr, "SceneViewId_t", "m_nFrameCount", true, value);
}
std::string GSceneViewId_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSceneViewId_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSceneViewId_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSceneViewId_t>("SceneViewId_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ViewId", &GSceneViewId_t::GetViewId, &GSceneViewId_t::SetViewId)
        .addProperty("FrameCount", &GSceneViewId_t::GetFrameCount, &GSceneViewId_t::SetFrameCount)
        .addFunction("ToPtr", &GSceneViewId_t::ToPtr)
        .addFunction("IsValid", &GSceneViewId_t::IsValid)
        .endClass();
}