#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMoverPathNode::GCMoverPathNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMoverPathNode::GCMoverPathNode(void *ptr) {
    m_ptr = ptr;
}
Vector GCMoverPathNode::GetInTangentLocal() const {
    return GetSchemaValue<Vector>(m_ptr, "CMoverPathNode", "m_vInTangentLocal");
}
void GCMoverPathNode::SetInTangentLocal(Vector value) {
    SetSchemaValue(m_ptr, "CMoverPathNode", "m_vInTangentLocal", false, value);
}
Vector GCMoverPathNode::GetOutTangentLocal() const {
    return GetSchemaValue<Vector>(m_ptr, "CMoverPathNode", "m_vOutTangentLocal");
}
void GCMoverPathNode::SetOutTangentLocal(Vector value) {
    SetSchemaValue(m_ptr, "CMoverPathNode", "m_vOutTangentLocal", false, value);
}
std::string GCMoverPathNode::GetParentPathUniqueID() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMoverPathNode", "m_szParentPathUniqueID").String();
}
void GCMoverPathNode::SetParentPathUniqueID(std::string value) {
    SetSchemaValue(m_ptr, "CMoverPathNode", "m_szParentPathUniqueID", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIOOutput GCMoverPathNode::GetOnPassThrough() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMoverPathNode", "m_OnPassThrough"));
    return value;
}
void GCMoverPathNode::SetOnPassThrough(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMoverPathNode", "m_OnPassThrough", false, value);
}
GCPathMover GCMoverPathNode::GetMover() const {
    GCPathMover value(*GetSchemaValuePtr<void*>(m_ptr, "CMoverPathNode", "m_hMover"));
    return value;
}
void GCMoverPathNode::SetMover(GCPathMover* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Mover' is not possible.\n");
}
std::string GCMoverPathNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMoverPathNode::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCMoverPathNode::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCMoverPathNode::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMoverPathNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMoverPathNode>("CMoverPathNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InTangentLocal", &GCMoverPathNode::GetInTangentLocal, &GCMoverPathNode::SetInTangentLocal)
        .addProperty("OutTangentLocal", &GCMoverPathNode::GetOutTangentLocal, &GCMoverPathNode::SetOutTangentLocal)
        .addProperty("ParentPathUniqueID", &GCMoverPathNode::GetParentPathUniqueID, &GCMoverPathNode::SetParentPathUniqueID)
        .addProperty("OnPassThrough", &GCMoverPathNode::GetOnPassThrough, &GCMoverPathNode::SetOnPassThrough)
        .addProperty("Mover", &GCMoverPathNode::GetMover, &GCMoverPathNode::SetMover)
        .addProperty("Parent", &GCMoverPathNode::GetParent, &GCMoverPathNode::SetParent)
        .addFunction("ToPtr", &GCMoverPathNode::ToPtr)
        .addFunction("IsValid", &GCMoverPathNode::IsValid)
        .endClass();
}