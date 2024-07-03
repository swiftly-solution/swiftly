#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSlopeComponentUpdater::GCSlopeComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSlopeComponentUpdater::GCSlopeComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
float GCSlopeComponentUpdater::GetTraceDistance() const {
    return GetSchemaValue<float>(m_ptr, "CSlopeComponentUpdater", "m_flTraceDistance");
}
void GCSlopeComponentUpdater::SetTraceDistance(float value) {
    SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_flTraceDistance", false, value);
}
GCAnimParamHandle GCSlopeComponentUpdater::GetSlopeAngle() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngle"));
    return value;
}
void GCSlopeComponentUpdater::SetSlopeAngle(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngle", false, value);
}
GCAnimParamHandle GCSlopeComponentUpdater::GetSlopeAngleFront() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngleFront"));
    return value;
}
void GCSlopeComponentUpdater::SetSlopeAngleFront(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngleFront", false, value);
}
GCAnimParamHandle GCSlopeComponentUpdater::GetSlopeAngleSide() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngleSide"));
    return value;
}
void GCSlopeComponentUpdater::SetSlopeAngleSide(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngleSide", false, value);
}
GCAnimParamHandle GCSlopeComponentUpdater::GetSlopeHeading() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSlopeComponentUpdater", "m_hSlopeHeading"));
    return value;
}
void GCSlopeComponentUpdater::SetSlopeHeading(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeHeading", false, value);
}
GCAnimParamHandle GCSlopeComponentUpdater::GetSlopeNormal() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSlopeComponentUpdater", "m_hSlopeNormal"));
    return value;
}
void GCSlopeComponentUpdater::SetSlopeNormal(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeNormal", false, value);
}
GCAnimParamHandle GCSlopeComponentUpdater::GetSlopeNormal_WorldSpace() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSlopeComponentUpdater", "m_hSlopeNormal_WorldSpace"));
    return value;
}
void GCSlopeComponentUpdater::SetSlopeNormal_WorldSpace(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeNormal_WorldSpace", false, value);
}
std::string GCSlopeComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSlopeComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCSlopeComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCSlopeComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSlopeComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSlopeComponentUpdater>("CSlopeComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TraceDistance", &GCSlopeComponentUpdater::GetTraceDistance, &GCSlopeComponentUpdater::SetTraceDistance)
        .addProperty("SlopeAngle", &GCSlopeComponentUpdater::GetSlopeAngle, &GCSlopeComponentUpdater::SetSlopeAngle)
        .addProperty("SlopeAngleFront", &GCSlopeComponentUpdater::GetSlopeAngleFront, &GCSlopeComponentUpdater::SetSlopeAngleFront)
        .addProperty("SlopeAngleSide", &GCSlopeComponentUpdater::GetSlopeAngleSide, &GCSlopeComponentUpdater::SetSlopeAngleSide)
        .addProperty("SlopeHeading", &GCSlopeComponentUpdater::GetSlopeHeading, &GCSlopeComponentUpdater::SetSlopeHeading)
        .addProperty("SlopeNormal", &GCSlopeComponentUpdater::GetSlopeNormal, &GCSlopeComponentUpdater::SetSlopeNormal)
        .addProperty("SlopeNormal_WorldSpace", &GCSlopeComponentUpdater::GetSlopeNormal_WorldSpace, &GCSlopeComponentUpdater::SetSlopeNormal_WorldSpace)
        .addProperty("Parent", &GCSlopeComponentUpdater::GetParent, &GCSlopeComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCSlopeComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCSlopeComponentUpdater::IsValid)
        .endClass();
}