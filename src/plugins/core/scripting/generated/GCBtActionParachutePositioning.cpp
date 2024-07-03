#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBtActionParachutePositioning::GCBtActionParachutePositioning(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBtActionParachutePositioning::GCBtActionParachutePositioning(void *ptr) {
    m_ptr = ptr;
}
GCountdownTimer GCBtActionParachutePositioning::GetActionTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CBtActionParachutePositioning", "m_ActionTimer"));
    return value;
}
void GCBtActionParachutePositioning::SetActionTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CBtActionParachutePositioning", "m_ActionTimer", false, value);
}
std::string GCBtActionParachutePositioning::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBtActionParachutePositioning::IsValid() {
    return (m_ptr != nullptr);
}
GCBtNode GCBtActionParachutePositioning::GetParent() const {
    GCBtNode value(m_ptr);
    return value;
}
void GCBtActionParachutePositioning::SetParent(GCBtNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBtActionParachutePositioning(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtActionParachutePositioning>("CBtActionParachutePositioning")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ActionTimer", &GCBtActionParachutePositioning::GetActionTimer, &GCBtActionParachutePositioning::SetActionTimer)
        .addProperty("Parent", &GCBtActionParachutePositioning::GetParent, &GCBtActionParachutePositioning::SetParent)
        .addFunction("ToPtr", &GCBtActionParachutePositioning::ToPtr)
        .addFunction("IsValid", &GCBtActionParachutePositioning::IsValid)
        .endClass();
}