#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GResponseParams::GResponseParams(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GResponseParams::GResponseParams(void *ptr) {
    m_ptr = ptr;
}
int16_t GResponseParams::GetOdds() const {
    return GetSchemaValue<int16_t>(m_ptr, "ResponseParams", "odds");
}
void GResponseParams::SetOdds(int16_t value) {
    SetSchemaValue(m_ptr, "ResponseParams", "odds", false, value);
}
int16_t GResponseParams::GetFlags() const {
    return GetSchemaValue<int16_t>(m_ptr, "ResponseParams", "flags");
}
void GResponseParams::SetFlags(int16_t value) {
    SetSchemaValue(m_ptr, "ResponseParams", "flags", false, value);
}
GResponseFollowup GResponseParams::GetFollowup() const {
    GResponseFollowup value(*GetSchemaValuePtr<void*>(m_ptr, "ResponseParams", "m_pFollowup"));
    return value;
}
void GResponseParams::SetFollowup(GResponseFollowup* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Followup' is not possible.\n");
}
std::string GResponseParams::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GResponseParams::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassResponseParams(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GResponseParams>("ResponseParams")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Odds", &GResponseParams::GetOdds, &GResponseParams::SetOdds)
        .addProperty("Flags", &GResponseParams::GetFlags, &GResponseParams::SetFlags)
        .addProperty("Followup", &GResponseParams::GetFollowup, &GResponseParams::SetFollowup)
        .addFunction("ToPtr", &GResponseParams::ToPtr)
        .addFunction("IsValid", &GResponseParams::IsValid)
        .endClass();
}