#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosSoundEventGroupSchema::GCSosSoundEventGroupSchema(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosSoundEventGroupSchema::GCSosSoundEventGroupSchema(void *ptr) {
    m_ptr = ptr;
}
std::string GCSosSoundEventGroupSchema::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosSoundEventGroupSchema", "m_name").Get();
}
void GCSosSoundEventGroupSchema::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_name", false, CUtlString(value.c_str()));
}
uint64_t GCSosSoundEventGroupSchema::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSosSoundEventGroupSchema", "m_nType");
}
void GCSosSoundEventGroupSchema::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_nType", false, value);
}
bool GCSosSoundEventGroupSchema::GetIsBlocking() const {
    return GetSchemaValue<bool>(m_ptr, "CSosSoundEventGroupSchema", "m_bIsBlocking");
}
void GCSosSoundEventGroupSchema::SetIsBlocking(bool value) {
    SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_bIsBlocking", false, value);
}
int32_t GCSosSoundEventGroupSchema::GetBlockMaxCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSosSoundEventGroupSchema", "m_nBlockMaxCount");
}
void GCSosSoundEventGroupSchema::SetBlockMaxCount(int32_t value) {
    SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_nBlockMaxCount", false, value);
}
bool GCSosSoundEventGroupSchema::GetInvertMatch() const {
    return GetSchemaValue<bool>(m_ptr, "CSosSoundEventGroupSchema", "m_bInvertMatch");
}
void GCSosSoundEventGroupSchema::SetInvertMatch(bool value) {
    SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_bInvertMatch", false, value);
}
GCSosGroupMatchPattern GCSosSoundEventGroupSchema::GetMatchPattern() const {
    GCSosGroupMatchPattern value(GetSchemaPtr(m_ptr, "CSosSoundEventGroupSchema", "m_matchPattern"));
    return value;
}
void GCSosSoundEventGroupSchema::SetMatchPattern(GCSosGroupMatchPattern value) {
    SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_matchPattern", false, value);
}
GCSosGroupBranchPattern GCSosSoundEventGroupSchema::GetBranchPattern() const {
    GCSosGroupBranchPattern value(GetSchemaPtr(m_ptr, "CSosSoundEventGroupSchema", "m_branchPattern"));
    return value;
}
void GCSosSoundEventGroupSchema::SetBranchPattern(GCSosGroupBranchPattern value) {
    SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_branchPattern", false, value);
}
float GCSosSoundEventGroupSchema::GetLifeSpanTime() const {
    return GetSchemaValue<float>(m_ptr, "CSosSoundEventGroupSchema", "m_flLifeSpanTime");
}
void GCSosSoundEventGroupSchema::SetLifeSpanTime(float value) {
    SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_flLifeSpanTime", false, value);
}
std::vector<GCSosGroupActionSchema*> GCSosSoundEventGroupSchema::GetActions() const {
    GCSosGroupActionSchema** outValue = GetSchemaValue<GCSosGroupActionSchema**>(m_ptr, "CSosSoundEventGroupSchema", "m_vActions"); std::vector<GCSosGroupActionSchema*> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCSosSoundEventGroupSchema::SetActions(std::vector<GCSosGroupActionSchema*> value) {
    GCSosGroupActionSchema** outValue = GetSchemaValue<GCSosGroupActionSchema**>(m_ptr, "CSosSoundEventGroupSchema", "m_vActions"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_vActions", false, outValue);
}
std::string GCSosSoundEventGroupSchema::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosSoundEventGroupSchema::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSosSoundEventGroupSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosSoundEventGroupSchema>("CSosSoundEventGroupSchema")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCSosSoundEventGroupSchema::GetName, &GCSosSoundEventGroupSchema::SetName)
        .addProperty("Type", &GCSosSoundEventGroupSchema::GetType, &GCSosSoundEventGroupSchema::SetType)
        .addProperty("IsBlocking", &GCSosSoundEventGroupSchema::GetIsBlocking, &GCSosSoundEventGroupSchema::SetIsBlocking)
        .addProperty("BlockMaxCount", &GCSosSoundEventGroupSchema::GetBlockMaxCount, &GCSosSoundEventGroupSchema::SetBlockMaxCount)
        .addProperty("InvertMatch", &GCSosSoundEventGroupSchema::GetInvertMatch, &GCSosSoundEventGroupSchema::SetInvertMatch)
        .addProperty("MatchPattern", &GCSosSoundEventGroupSchema::GetMatchPattern, &GCSosSoundEventGroupSchema::SetMatchPattern)
        .addProperty("BranchPattern", &GCSosSoundEventGroupSchema::GetBranchPattern, &GCSosSoundEventGroupSchema::SetBranchPattern)
        .addProperty("LifeSpanTime", &GCSosSoundEventGroupSchema::GetLifeSpanTime, &GCSosSoundEventGroupSchema::SetLifeSpanTime)
        .addProperty("Actions", &GCSosSoundEventGroupSchema::GetActions, &GCSosSoundEventGroupSchema::SetActions)
        .addFunction("ToPtr", &GCSosSoundEventGroupSchema::ToPtr)
        .addFunction("IsValid", &GCSosSoundEventGroupSchema::IsValid)
        .endClass();
}