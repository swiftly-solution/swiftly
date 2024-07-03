#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSObserverPawn::GCCSObserverPawn(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSObserverPawn::GCCSObserverPawn(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSObserverPawn::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSObserverPawn::IsValid() {
    return (m_ptr != nullptr);
}
GCCSPlayerPawnBase GCCSObserverPawn::GetParent() const {
    GCCSPlayerPawnBase value(m_ptr);
    return value;
}
void GCCSObserverPawn::SetParent(GCCSPlayerPawnBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSObserverPawn(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserverPawn>("CCSObserverPawn")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSObserverPawn::GetParent, &GCCSObserverPawn::SetParent)
        .addFunction("ToPtr", &GCCSObserverPawn::ToPtr)
        .addFunction("IsValid", &GCCSObserverPawn::IsValid)
        .endClass();
}