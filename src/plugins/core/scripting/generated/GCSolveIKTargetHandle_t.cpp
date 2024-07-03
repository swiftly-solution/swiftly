#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSolveIKTargetHandle_t::GCSolveIKTargetHandle_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSolveIKTargetHandle_t::GCSolveIKTargetHandle_t(void *ptr) {
    m_ptr = ptr;
}
GCAnimParamHandle GCSolveIKTargetHandle_t::GetPositionHandle() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSolveIKTargetHandle_t", "m_positionHandle"));
    return value;
}
void GCSolveIKTargetHandle_t::SetPositionHandle(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSolveIKTargetHandle_t", "m_positionHandle", true, value);
}
GCAnimParamHandle GCSolveIKTargetHandle_t::GetOrientationHandle() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSolveIKTargetHandle_t", "m_orientationHandle"));
    return value;
}
void GCSolveIKTargetHandle_t::SetOrientationHandle(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSolveIKTargetHandle_t", "m_orientationHandle", true, value);
}
std::string GCSolveIKTargetHandle_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSolveIKTargetHandle_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSolveIKTargetHandle_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSolveIKTargetHandle_t>("CSolveIKTargetHandle_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PositionHandle", &GCSolveIKTargetHandle_t::GetPositionHandle, &GCSolveIKTargetHandle_t::SetPositionHandle)
        .addProperty("OrientationHandle", &GCSolveIKTargetHandle_t::GetOrientationHandle, &GCSolveIKTargetHandle_t::SetOrientationHandle)
        .addFunction("ToPtr", &GCSolveIKTargetHandle_t::ToPtr)
        .addFunction("IsValid", &GCSolveIKTargetHandle_t::IsValid)
        .endClass();
}