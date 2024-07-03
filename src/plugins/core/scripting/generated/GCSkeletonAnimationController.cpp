#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSkeletonAnimationController::GCSkeletonAnimationController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSkeletonAnimationController::GCSkeletonAnimationController(void *ptr) {
    m_ptr = ptr;
}
GCSkeletonInstance GCSkeletonAnimationController::GetSkeletonInstance() const {
    GCSkeletonInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CSkeletonAnimationController", "m_pSkeletonInstance"));
    return value;
}
void GCSkeletonAnimationController::SetSkeletonInstance(GCSkeletonInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'SkeletonInstance' is not possible.\n");
}
std::string GCSkeletonAnimationController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSkeletonAnimationController::IsValid() {
    return (m_ptr != nullptr);
}
GISkeletonAnimationController GCSkeletonAnimationController::GetParent() const {
    GISkeletonAnimationController value(m_ptr);
    return value;
}
void GCSkeletonAnimationController::SetParent(GISkeletonAnimationController value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSkeletonAnimationController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkeletonAnimationController>("CSkeletonAnimationController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SkeletonInstance", &GCSkeletonAnimationController::GetSkeletonInstance, &GCSkeletonAnimationController::SetSkeletonInstance)
        .addProperty("Parent", &GCSkeletonAnimationController::GetParent, &GCSkeletonAnimationController::SetParent)
        .addFunction("ToPtr", &GCSkeletonAnimationController::ToPtr)
        .addFunction("IsValid", &GCSkeletonAnimationController::IsValid)
        .endClass();
}