#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIPhysicsPlayerController::GIPhysicsPlayerController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIPhysicsPlayerController::GIPhysicsPlayerController(void *ptr) {
    m_ptr = ptr;
}
std::string GIPhysicsPlayerController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIPhysicsPlayerController::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIPhysicsPlayerController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIPhysicsPlayerController>("IPhysicsPlayerController")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GIPhysicsPlayerController::ToPtr)
        .addFunction("IsValid", &GIPhysicsPlayerController::IsValid)
        .endClass();
}