#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavWalkable::GCNavWalkable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavWalkable::GCNavWalkable(void *ptr) {
    m_ptr = ptr;
}
std::string GCNavWalkable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavWalkable::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCNavWalkable::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCNavWalkable::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNavWalkable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavWalkable>("CNavWalkable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNavWalkable::GetParent, &GCNavWalkable::SetParent)
        .addFunction("ToPtr", &GCNavWalkable::ToPtr)
        .addFunction("IsValid", &GCNavWalkable::IsValid)
        .endClass();
}