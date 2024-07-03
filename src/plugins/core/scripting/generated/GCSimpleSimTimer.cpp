#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSimpleSimTimer::GCSimpleSimTimer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSimpleSimTimer::GCSimpleSimTimer(void *ptr) {
    m_ptr = ptr;
}
float GCSimpleSimTimer::GetNext() const {
    return GetSchemaValue<float>(m_ptr, "CSimpleSimTimer", "m_next");
}
void GCSimpleSimTimer::SetNext(float value) {
    SetSchemaValue(m_ptr, "CSimpleSimTimer", "m_next", false, value);
}
WorldGroupId_t GCSimpleSimTimer::GetWorldGroupId() const {
    return GetSchemaValue<WorldGroupId_t>(m_ptr, "CSimpleSimTimer", "m_nWorldGroupId");
}
void GCSimpleSimTimer::SetWorldGroupId(WorldGroupId_t value) {
    SetSchemaValue(m_ptr, "CSimpleSimTimer", "m_nWorldGroupId", false, value);
}
std::string GCSimpleSimTimer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSimpleSimTimer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSimpleSimTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSimpleSimTimer>("CSimpleSimTimer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Next", &GCSimpleSimTimer::GetNext, &GCSimpleSimTimer::SetNext)
        .addProperty("WorldGroupId", &GCSimpleSimTimer::GetWorldGroupId, &GCSimpleSimTimer::SetWorldGroupId)
        .addFunction("ToPtr", &GCSimpleSimTimer::ToPtr)
        .addFunction("IsValid", &GCSimpleSimTimer::IsValid)
        .endClass();
}