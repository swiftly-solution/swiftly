#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSummaryTakeDamageInfo_t::GSummaryTakeDamageInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSummaryTakeDamageInfo_t::GSummaryTakeDamageInfo_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GSummaryTakeDamageInfo_t::GetSummarisedCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "SummaryTakeDamageInfo_t", "nSummarisedCount");
}
void GSummaryTakeDamageInfo_t::SetSummarisedCount(int32_t value) {
    SetSchemaValue(m_ptr, "SummaryTakeDamageInfo_t", "nSummarisedCount", true, value);
}
GCTakeDamageInfo GSummaryTakeDamageInfo_t::GetInfo() const {
    GCTakeDamageInfo value(GetSchemaPtr(m_ptr, "SummaryTakeDamageInfo_t", "info"));
    return value;
}
void GSummaryTakeDamageInfo_t::SetInfo(GCTakeDamageInfo value) {
    SetSchemaValue(m_ptr, "SummaryTakeDamageInfo_t", "info", true, value);
}
GCTakeDamageResult GSummaryTakeDamageInfo_t::GetResult() const {
    GCTakeDamageResult value(GetSchemaPtr(m_ptr, "SummaryTakeDamageInfo_t", "result"));
    return value;
}
void GSummaryTakeDamageInfo_t::SetResult(GCTakeDamageResult value) {
    SetSchemaValue(m_ptr, "SummaryTakeDamageInfo_t", "result", true, value);
}
GCBaseEntity GSummaryTakeDamageInfo_t::GetTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "SummaryTakeDamageInfo_t", "hTarget"));
    return value;
}
void GSummaryTakeDamageInfo_t::SetTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target' is not possible.\n");
}
std::string GSummaryTakeDamageInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSummaryTakeDamageInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSummaryTakeDamageInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSummaryTakeDamageInfo_t>("SummaryTakeDamageInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SummarisedCount", &GSummaryTakeDamageInfo_t::GetSummarisedCount, &GSummaryTakeDamageInfo_t::SetSummarisedCount)
        .addProperty("Info", &GSummaryTakeDamageInfo_t::GetInfo, &GSummaryTakeDamageInfo_t::SetInfo)
        .addProperty("Result", &GSummaryTakeDamageInfo_t::GetResult, &GSummaryTakeDamageInfo_t::SetResult)
        .addProperty("Target", &GSummaryTakeDamageInfo_t::GetTarget, &GSummaryTakeDamageInfo_t::SetTarget)
        .addFunction("ToPtr", &GSummaryTakeDamageInfo_t::ToPtr)
        .addFunction("IsValid", &GSummaryTakeDamageInfo_t::IsValid)
        .endClass();
}