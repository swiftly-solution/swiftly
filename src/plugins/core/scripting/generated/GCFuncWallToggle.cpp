#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncWallToggle::GCFuncWallToggle(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncWallToggle::GCFuncWallToggle(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncWallToggle::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncWallToggle::IsValid() {
    return (m_ptr != nullptr);
}
GCFuncWall GCFuncWallToggle::GetParent() const {
    GCFuncWall value(m_ptr);
    return value;
}
void GCFuncWallToggle::SetParent(GCFuncWall value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncWallToggle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncWallToggle>("CFuncWallToggle")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFuncWallToggle::GetParent, &GCFuncWallToggle::SetParent)
        .addFunction("ToPtr", &GCFuncWallToggle::ToPtr)
        .addFunction("IsValid", &GCFuncWallToggle::IsValid)
        .endClass();
}