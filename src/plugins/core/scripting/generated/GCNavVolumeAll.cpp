#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavVolumeAll::GCNavVolumeAll(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavVolumeAll::GCNavVolumeAll(void *ptr) {
    m_ptr = ptr;
}
std::string GCNavVolumeAll::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavVolumeAll::IsValid() {
    return (m_ptr != nullptr);
}
GCNavVolumeVector GCNavVolumeAll::GetParent() const {
    GCNavVolumeVector value(m_ptr);
    return value;
}
void GCNavVolumeAll::SetParent(GCNavVolumeVector value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNavVolumeAll(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeAll>("CNavVolumeAll")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNavVolumeAll::GetParent, &GCNavVolumeAll::SetParent)
        .addFunction("ToPtr", &GCNavVolumeAll::ToPtr)
        .addFunction("IsValid", &GCNavVolumeAll::IsValid)
        .endClass();
}