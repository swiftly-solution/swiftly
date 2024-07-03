#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCScriptItem::GCScriptItem(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCScriptItem::GCScriptItem(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCScriptItem::GetMoveTypeOverride() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CScriptItem", "m_MoveTypeOverride");
}
void GCScriptItem::SetMoveTypeOverride(uint64_t value) {
    SetSchemaValue(m_ptr, "CScriptItem", "m_MoveTypeOverride", false, value);
}
std::string GCScriptItem::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCScriptItem::IsValid() {
    return (m_ptr != nullptr);
}
GCItem GCScriptItem::GetParent() const {
    GCItem value(m_ptr);
    return value;
}
void GCScriptItem::SetParent(GCItem value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCScriptItem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptItem>("CScriptItem")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MoveTypeOverride", &GCScriptItem::GetMoveTypeOverride, &GCScriptItem::SetMoveTypeOverride)
        .addProperty("Parent", &GCScriptItem::GetParent, &GCScriptItem::SetParent)
        .addFunction("ToPtr", &GCScriptItem::ToPtr)
        .addFunction("IsValid", &GCScriptItem::IsValid)
        .endClass();
}