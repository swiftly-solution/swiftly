#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRopeKeyframe::GCRopeKeyframe(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRopeKeyframe::GCRopeKeyframe(void *ptr) {
    m_ptr = ptr;
}
uint16_t GCRopeKeyframe::GetRopeFlags() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CRopeKeyframe", "m_RopeFlags");
}
void GCRopeKeyframe::SetRopeFlags(uint16_t value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_RopeFlags", false, value);
}
std::string GCRopeKeyframe::GetNextLinkName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CRopeKeyframe", "m_iNextLinkName").String();
}
void GCRopeKeyframe::SetNextLinkName(std::string value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_iNextLinkName", false, CUtlSymbolLarge(value.c_str()));
}
int16_t GCRopeKeyframe::GetSlack() const {
    return GetSchemaValue<int16_t>(m_ptr, "CRopeKeyframe", "m_Slack");
}
void GCRopeKeyframe::SetSlack(int16_t value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_Slack", false, value);
}
float GCRopeKeyframe::GetWidth() const {
    return GetSchemaValue<float>(m_ptr, "CRopeKeyframe", "m_Width");
}
void GCRopeKeyframe::SetWidth(float value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_Width", false, value);
}
float GCRopeKeyframe::GetTextureScale() const {
    return GetSchemaValue<float>(m_ptr, "CRopeKeyframe", "m_TextureScale");
}
void GCRopeKeyframe::SetTextureScale(float value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_TextureScale", false, value);
}
uint8_t GCRopeKeyframe::GetSegments() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CRopeKeyframe", "m_nSegments");
}
void GCRopeKeyframe::SetSegments(uint8_t value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_nSegments", false, value);
}
bool GCRopeKeyframe::GetConstrainBetweenEndpoints() const {
    return GetSchemaValue<bool>(m_ptr, "CRopeKeyframe", "m_bConstrainBetweenEndpoints");
}
void GCRopeKeyframe::SetConstrainBetweenEndpoints(bool value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_bConstrainBetweenEndpoints", false, value);
}
std::string GCRopeKeyframe::GetStrRopeMaterialModel() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CRopeKeyframe", "m_strRopeMaterialModel").String();
}
void GCRopeKeyframe::SetStrRopeMaterialModel(std::string value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_strRopeMaterialModel", false, CUtlSymbolLarge(value.c_str()));
}
uint8_t GCRopeKeyframe::GetSubdiv() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CRopeKeyframe", "m_Subdiv");
}
void GCRopeKeyframe::SetSubdiv(uint8_t value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_Subdiv", false, value);
}
uint8_t GCRopeKeyframe::GetChangeCount() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CRopeKeyframe", "m_nChangeCount");
}
void GCRopeKeyframe::SetChangeCount(uint8_t value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_nChangeCount", false, value);
}
int16_t GCRopeKeyframe::GetRopeLength() const {
    return GetSchemaValue<int16_t>(m_ptr, "CRopeKeyframe", "m_RopeLength");
}
void GCRopeKeyframe::SetRopeLength(int16_t value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_RopeLength", false, value);
}
uint8_t GCRopeKeyframe::GetLockedPoints() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CRopeKeyframe", "m_fLockedPoints");
}
void GCRopeKeyframe::SetLockedPoints(uint8_t value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_fLockedPoints", false, value);
}
bool GCRopeKeyframe::GetCreatedFromMapFile() const {
    return GetSchemaValue<bool>(m_ptr, "CRopeKeyframe", "m_bCreatedFromMapFile");
}
void GCRopeKeyframe::SetCreatedFromMapFile(bool value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_bCreatedFromMapFile", false, value);
}
float GCRopeKeyframe::GetScrollSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CRopeKeyframe", "m_flScrollSpeed");
}
void GCRopeKeyframe::SetScrollSpeed(float value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_flScrollSpeed", false, value);
}
bool GCRopeKeyframe::GetStartPointValid() const {
    return GetSchemaValue<bool>(m_ptr, "CRopeKeyframe", "m_bStartPointValid");
}
void GCRopeKeyframe::SetStartPointValid(bool value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_bStartPointValid", false, value);
}
bool GCRopeKeyframe::GetEndPointValid() const {
    return GetSchemaValue<bool>(m_ptr, "CRopeKeyframe", "m_bEndPointValid");
}
void GCRopeKeyframe::SetEndPointValid(bool value) {
    SetSchemaValue(m_ptr, "CRopeKeyframe", "m_bEndPointValid", false, value);
}
GCBaseEntity GCRopeKeyframe::GetStartPoint() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CRopeKeyframe", "m_hStartPoint"));
    return value;
}
void GCRopeKeyframe::SetStartPoint(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'StartPoint' is not possible.\n");
}
GCBaseEntity GCRopeKeyframe::GetEndPoint() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CRopeKeyframe", "m_hEndPoint"));
    return value;
}
void GCRopeKeyframe::SetEndPoint(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'EndPoint' is not possible.\n");
}
std::string GCRopeKeyframe::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRopeKeyframe::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCRopeKeyframe::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCRopeKeyframe::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRopeKeyframe(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRopeKeyframe>("CRopeKeyframe")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RopeFlags", &GCRopeKeyframe::GetRopeFlags, &GCRopeKeyframe::SetRopeFlags)
        .addProperty("NextLinkName", &GCRopeKeyframe::GetNextLinkName, &GCRopeKeyframe::SetNextLinkName)
        .addProperty("Slack", &GCRopeKeyframe::GetSlack, &GCRopeKeyframe::SetSlack)
        .addProperty("Width", &GCRopeKeyframe::GetWidth, &GCRopeKeyframe::SetWidth)
        .addProperty("TextureScale", &GCRopeKeyframe::GetTextureScale, &GCRopeKeyframe::SetTextureScale)
        .addProperty("Segments", &GCRopeKeyframe::GetSegments, &GCRopeKeyframe::SetSegments)
        .addProperty("ConstrainBetweenEndpoints", &GCRopeKeyframe::GetConstrainBetweenEndpoints, &GCRopeKeyframe::SetConstrainBetweenEndpoints)
        .addProperty("StrRopeMaterialModel", &GCRopeKeyframe::GetStrRopeMaterialModel, &GCRopeKeyframe::SetStrRopeMaterialModel)
        .addProperty("Subdiv", &GCRopeKeyframe::GetSubdiv, &GCRopeKeyframe::SetSubdiv)
        .addProperty("ChangeCount", &GCRopeKeyframe::GetChangeCount, &GCRopeKeyframe::SetChangeCount)
        .addProperty("RopeLength", &GCRopeKeyframe::GetRopeLength, &GCRopeKeyframe::SetRopeLength)
        .addProperty("LockedPoints", &GCRopeKeyframe::GetLockedPoints, &GCRopeKeyframe::SetLockedPoints)
        .addProperty("CreatedFromMapFile", &GCRopeKeyframe::GetCreatedFromMapFile, &GCRopeKeyframe::SetCreatedFromMapFile)
        .addProperty("ScrollSpeed", &GCRopeKeyframe::GetScrollSpeed, &GCRopeKeyframe::SetScrollSpeed)
        .addProperty("StartPointValid", &GCRopeKeyframe::GetStartPointValid, &GCRopeKeyframe::SetStartPointValid)
        .addProperty("EndPointValid", &GCRopeKeyframe::GetEndPointValid, &GCRopeKeyframe::SetEndPointValid)
        .addProperty("StartPoint", &GCRopeKeyframe::GetStartPoint, &GCRopeKeyframe::SetStartPoint)
        .addProperty("EndPoint", &GCRopeKeyframe::GetEndPoint, &GCRopeKeyframe::SetEndPoint)
        .addProperty("Parent", &GCRopeKeyframe::GetParent, &GCRopeKeyframe::SetParent)
        .addFunction("ToPtr", &GCRopeKeyframe::ToPtr)
        .addFunction("IsValid", &GCRopeKeyframe::IsValid)
        .endClass();
}