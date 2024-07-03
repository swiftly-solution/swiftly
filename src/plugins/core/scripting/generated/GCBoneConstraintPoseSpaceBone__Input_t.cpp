#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBoneConstraintPoseSpaceBone__Input_t::GCBoneConstraintPoseSpaceBone__Input_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBoneConstraintPoseSpaceBone__Input_t::GCBoneConstraintPoseSpaceBone__Input_t(void *ptr) {
    m_ptr = ptr;
}
Vector GCBoneConstraintPoseSpaceBone__Input_t::GetInputValue() const {
    return GetSchemaValue<Vector>(m_ptr, "CBoneConstraintPoseSpaceBone__Input_t", "m_inputValue");
}
void GCBoneConstraintPoseSpaceBone__Input_t::SetInputValue(Vector value) {
    SetSchemaValue(m_ptr, "CBoneConstraintPoseSpaceBone__Input_t", "m_inputValue", true, value);
}
std::string GCBoneConstraintPoseSpaceBone__Input_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBoneConstraintPoseSpaceBone__Input_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBoneConstraintPoseSpaceBone__Input_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintPoseSpaceBone__Input_t>("CBoneConstraintPoseSpaceBone__Input_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InputValue", &GCBoneConstraintPoseSpaceBone__Input_t::GetInputValue, &GCBoneConstraintPoseSpaceBone__Input_t::SetInputValue)
        .addFunction("ToPtr", &GCBoneConstraintPoseSpaceBone__Input_t::ToPtr)
        .addFunction("IsValid", &GCBoneConstraintPoseSpaceBone__Input_t::IsValid)
        .endClass();
}