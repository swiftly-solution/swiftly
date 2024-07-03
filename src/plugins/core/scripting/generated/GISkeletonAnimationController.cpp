#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GISkeletonAnimationController::GISkeletonAnimationController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GISkeletonAnimationController::GISkeletonAnimationController(void *ptr) {
    m_ptr = ptr;
}
std::string GISkeletonAnimationController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GISkeletonAnimationController::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassISkeletonAnimationController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GISkeletonAnimationController>("ISkeletonAnimationController")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GISkeletonAnimationController::ToPtr)
        .addFunction("IsValid", &GISkeletonAnimationController::IsValid)
        .endClass();
}