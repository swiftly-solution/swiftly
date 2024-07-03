#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCItemDefuser::GCItemDefuser(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCItemDefuser::GCItemDefuser(void *ptr) {
    m_ptr = ptr;
}
GEntitySpottedState_t GCItemDefuser::GetEntitySpottedState() const {
    GEntitySpottedState_t value(GetSchemaPtr(m_ptr, "CItemDefuser", "m_entitySpottedState"));
    return value;
}
void GCItemDefuser::SetEntitySpottedState(GEntitySpottedState_t value) {
    SetSchemaValue(m_ptr, "CItemDefuser", "m_entitySpottedState", false, value);
}
int32_t GCItemDefuser::GetSpotRules() const {
    return GetSchemaValue<int32_t>(m_ptr, "CItemDefuser", "m_nSpotRules");
}
void GCItemDefuser::SetSpotRules(int32_t value) {
    SetSchemaValue(m_ptr, "CItemDefuser", "m_nSpotRules", false, value);
}
std::string GCItemDefuser::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCItemDefuser::IsValid() {
    return (m_ptr != nullptr);
}
GCItem GCItemDefuser::GetParent() const {
    GCItem value(m_ptr);
    return value;
}
void GCItemDefuser::SetParent(GCItem value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCItemDefuser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemDefuser>("CItemDefuser")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EntitySpottedState", &GCItemDefuser::GetEntitySpottedState, &GCItemDefuser::SetEntitySpottedState)
        .addProperty("SpotRules", &GCItemDefuser::GetSpotRules, &GCItemDefuser::SetSpotRules)
        .addProperty("Parent", &GCItemDefuser::GetParent, &GCItemDefuser::SetParent)
        .addFunction("ToPtr", &GCItemDefuser::ToPtr)
        .addFunction("IsValid", &GCItemDefuser::IsValid)
        .endClass();
}