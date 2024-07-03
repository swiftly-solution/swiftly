#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSkeletonAnimCapture_t__Camera_t::GSkeletonAnimCapture_t__Camera_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSkeletonAnimCapture_t__Camera_t::GSkeletonAnimCapture_t__Camera_t(void *ptr) {
    m_ptr = ptr;
}
float GSkeletonAnimCapture_t__Camera_t::GetTime() const {
    return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__Camera_t", "m_flTime");
}
void GSkeletonAnimCapture_t__Camera_t::SetTime(float value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Camera_t", "m_flTime", true, value);
}
std::string GSkeletonAnimCapture_t__Camera_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSkeletonAnimCapture_t__Camera_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSkeletonAnimCapture_t__Camera_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonAnimCapture_t__Camera_t>("SkeletonAnimCapture_t__Camera_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Time", &GSkeletonAnimCapture_t__Camera_t::GetTime, &GSkeletonAnimCapture_t__Camera_t::SetTime)
        .addFunction("ToPtr", &GSkeletonAnimCapture_t__Camera_t::ToPtr)
        .addFunction("IsValid", &GSkeletonAnimCapture_t__Camera_t::IsValid)
        .endClass();
}