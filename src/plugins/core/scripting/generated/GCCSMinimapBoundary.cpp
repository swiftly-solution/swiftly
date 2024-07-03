#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSMinimapBoundary::GCCSMinimapBoundary(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSMinimapBoundary::GCCSMinimapBoundary(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSMinimapBoundary::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSMinimapBoundary::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCCSMinimapBoundary::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCCSMinimapBoundary::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSMinimapBoundary(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSMinimapBoundary>("CCSMinimapBoundary")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSMinimapBoundary::GetParent, &GCCSMinimapBoundary::SetParent)
        .addFunction("ToPtr", &GCCSMinimapBoundary::ToPtr)
        .addFunction("IsValid", &GCCSMinimapBoundary::IsValid)
        .endClass();
}