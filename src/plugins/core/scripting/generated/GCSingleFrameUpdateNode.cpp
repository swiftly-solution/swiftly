#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSingleFrameUpdateNode::GCSingleFrameUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSingleFrameUpdateNode::GCSingleFrameUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCPoseHandle GCSingleFrameUpdateNode::GetPoseCacheHandle() const {
    GCPoseHandle value(GetSchemaPtr(m_ptr, "CSingleFrameUpdateNode", "m_hPoseCacheHandle"));
    return value;
}
void GCSingleFrameUpdateNode::SetPoseCacheHandle(GCPoseHandle value) {
    SetSchemaValue(m_ptr, "CSingleFrameUpdateNode", "m_hPoseCacheHandle", false, value);
}
float GCSingleFrameUpdateNode::GetCycle() const {
    return GetSchemaValue<float>(m_ptr, "CSingleFrameUpdateNode", "m_flCycle");
}
void GCSingleFrameUpdateNode::SetCycle(float value) {
    SetSchemaValue(m_ptr, "CSingleFrameUpdateNode", "m_flCycle", false, value);
}
std::string GCSingleFrameUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSingleFrameUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCLeafUpdateNode GCSingleFrameUpdateNode::GetParent() const {
    GCLeafUpdateNode value(m_ptr);
    return value;
}
void GCSingleFrameUpdateNode::SetParent(GCLeafUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSingleFrameUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSingleFrameUpdateNode>("CSingleFrameUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PoseCacheHandle", &GCSingleFrameUpdateNode::GetPoseCacheHandle, &GCSingleFrameUpdateNode::SetPoseCacheHandle)
        .addProperty("Cycle", &GCSingleFrameUpdateNode::GetCycle, &GCSingleFrameUpdateNode::SetCycle)
        .addProperty("Parent", &GCSingleFrameUpdateNode::GetParent, &GCSingleFrameUpdateNode::SetParent)
        .addFunction("ToPtr", &GCSingleFrameUpdateNode::ToPtr)
        .addFunction("IsValid", &GCSingleFrameUpdateNode::IsValid)
        .endClass();
}