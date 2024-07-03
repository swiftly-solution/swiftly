#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCItem_Healthshot::GCItem_Healthshot(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCItem_Healthshot::GCItem_Healthshot(void *ptr) {
    m_ptr = ptr;
}
std::string GCItem_Healthshot::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCItem_Healthshot::IsValid() {
    return (m_ptr != nullptr);
}
GCWeaponBaseItem GCItem_Healthshot::GetParent() const {
    GCWeaponBaseItem value(m_ptr);
    return value;
}
void GCItem_Healthshot::SetParent(GCWeaponBaseItem value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCItem_Healthshot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItem_Healthshot>("CItem_Healthshot")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCItem_Healthshot::GetParent, &GCItem_Healthshot::SetParent)
        .addFunction("ToPtr", &GCItem_Healthshot::ToPtr)
        .addFunction("IsValid", &GCItem_Healthshot::IsValid)
        .endClass();
}