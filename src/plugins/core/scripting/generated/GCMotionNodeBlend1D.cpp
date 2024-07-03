#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionNodeBlend1D::GCMotionNodeBlend1D(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionNodeBlend1D::GCMotionNodeBlend1D(void *ptr) {
    m_ptr = ptr;
}
std::vector<GMotionBlendItem> GCMotionNodeBlend1D::GetBlendItems() const {
    CUtlVector<GMotionBlendItem>* vec = GetSchemaValue<CUtlVector<GMotionBlendItem>*>(m_ptr, "CMotionNodeBlend1D", "m_blendItems"); std::vector<GMotionBlendItem> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionNodeBlend1D::SetBlendItems(std::vector<GMotionBlendItem> value) {
    SetSchemaValueCUtlVector<GMotionBlendItem>(m_ptr, "CMotionNodeBlend1D", "m_blendItems", false, value);
}
int32_t GCMotionNodeBlend1D::GetParamIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMotionNodeBlend1D", "m_nParamIndex");
}
void GCMotionNodeBlend1D::SetParamIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CMotionNodeBlend1D", "m_nParamIndex", false, value);
}
std::string GCMotionNodeBlend1D::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionNodeBlend1D::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionNode GCMotionNodeBlend1D::GetParent() const {
    GCMotionNode value(m_ptr);
    return value;
}
void GCMotionNodeBlend1D::SetParent(GCMotionNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMotionNodeBlend1D(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionNodeBlend1D>("CMotionNodeBlend1D")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BlendItems", &GCMotionNodeBlend1D::GetBlendItems, &GCMotionNodeBlend1D::SetBlendItems)
        .addProperty("ParamIndex", &GCMotionNodeBlend1D::GetParamIndex, &GCMotionNodeBlend1D::SetParamIndex)
        .addProperty("Parent", &GCMotionNodeBlend1D::GetParent, &GCMotionNodeBlend1D::SetParent)
        .addFunction("ToPtr", &GCMotionNodeBlend1D::ToPtr)
        .addFunction("IsValid", &GCMotionNodeBlend1D::IsValid)
        .endClass();
}