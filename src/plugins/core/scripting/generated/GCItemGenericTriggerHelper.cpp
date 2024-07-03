#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCItemGenericTriggerHelper::GCItemGenericTriggerHelper(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCItemGenericTriggerHelper::GCItemGenericTriggerHelper(void *ptr) {
    m_ptr = ptr;
}
std::string GCItemGenericTriggerHelper::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCItemGenericTriggerHelper::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCItemGenericTriggerHelper::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCItemGenericTriggerHelper::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCItemGenericTriggerHelper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemGenericTriggerHelper>("CItemGenericTriggerHelper")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCItemGenericTriggerHelper::GetParent, &GCItemGenericTriggerHelper::SetParent)
        .addFunction("ToPtr", &GCItemGenericTriggerHelper::ToPtr)
        .addFunction("IsValid", &GCItemGenericTriggerHelper::IsValid)
        .endClass();
}