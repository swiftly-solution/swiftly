#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqCmdLayer::GCSeqCmdLayer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqCmdLayer::GCSeqCmdLayer(void *ptr) {
    m_ptr = ptr;
}
int16_t GCSeqCmdLayer::GetCmd() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_cmd");
}
void GCSeqCmdLayer::SetCmd(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_cmd", false, value);
}
int16_t GCSeqCmdLayer::GetLocalReference() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_nLocalReference");
}
void GCSeqCmdLayer::SetLocalReference(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_nLocalReference", false, value);
}
int16_t GCSeqCmdLayer::GetLocalBonemask() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_nLocalBonemask");
}
void GCSeqCmdLayer::SetLocalBonemask(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_nLocalBonemask", false, value);
}
int16_t GCSeqCmdLayer::GetDstResult() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_nDstResult");
}
void GCSeqCmdLayer::SetDstResult(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_nDstResult", false, value);
}
int16_t GCSeqCmdLayer::GetSrcResult() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_nSrcResult");
}
void GCSeqCmdLayer::SetSrcResult(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_nSrcResult", false, value);
}
bool GCSeqCmdLayer::GetSpline() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqCmdLayer", "m_bSpline");
}
void GCSeqCmdLayer::SetSpline(bool value) {
    SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_bSpline", false, value);
}
float GCSeqCmdLayer::GetVar1() const {
    return GetSchemaValue<float>(m_ptr, "CSeqCmdLayer", "m_flVar1");
}
void GCSeqCmdLayer::SetVar1(float value) {
    SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_flVar1", false, value);
}
float GCSeqCmdLayer::GetVar2() const {
    return GetSchemaValue<float>(m_ptr, "CSeqCmdLayer", "m_flVar2");
}
void GCSeqCmdLayer::SetVar2(float value) {
    SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_flVar2", false, value);
}
int16_t GCSeqCmdLayer::GetLineNumber() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_nLineNumber");
}
void GCSeqCmdLayer::SetLineNumber(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_nLineNumber", false, value);
}
std::string GCSeqCmdLayer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqCmdLayer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqCmdLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqCmdLayer>("CSeqCmdLayer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Cmd", &GCSeqCmdLayer::GetCmd, &GCSeqCmdLayer::SetCmd)
        .addProperty("LocalReference", &GCSeqCmdLayer::GetLocalReference, &GCSeqCmdLayer::SetLocalReference)
        .addProperty("LocalBonemask", &GCSeqCmdLayer::GetLocalBonemask, &GCSeqCmdLayer::SetLocalBonemask)
        .addProperty("DstResult", &GCSeqCmdLayer::GetDstResult, &GCSeqCmdLayer::SetDstResult)
        .addProperty("SrcResult", &GCSeqCmdLayer::GetSrcResult, &GCSeqCmdLayer::SetSrcResult)
        .addProperty("Spline", &GCSeqCmdLayer::GetSpline, &GCSeqCmdLayer::SetSpline)
        .addProperty("Var1", &GCSeqCmdLayer::GetVar1, &GCSeqCmdLayer::SetVar1)
        .addProperty("Var2", &GCSeqCmdLayer::GetVar2, &GCSeqCmdLayer::SetVar2)
        .addProperty("LineNumber", &GCSeqCmdLayer::GetLineNumber, &GCSeqCmdLayer::SetLineNumber)
        .addFunction("ToPtr", &GCSeqCmdLayer::ToPtr)
        .addFunction("IsValid", &GCSeqCmdLayer::IsValid)
        .endClass();
}