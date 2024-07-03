#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootStride::GCFootStride(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootStride::GCFootStride(void *ptr) {
    m_ptr = ptr;
}
GCFootCycleDefinition GCFootStride::GetDefinition() const {
    GCFootCycleDefinition value(GetSchemaPtr(m_ptr, "CFootStride", "m_definition"));
    return value;
}
void GCFootStride::SetDefinition(GCFootCycleDefinition value) {
    SetSchemaValue(m_ptr, "CFootStride", "m_definition", false, value);
}
GCFootTrajectories GCFootStride::GetTrajectories() const {
    GCFootTrajectories value(GetSchemaPtr(m_ptr, "CFootStride", "m_trajectories"));
    return value;
}
void GCFootStride::SetTrajectories(GCFootTrajectories value) {
    SetSchemaValue(m_ptr, "CFootStride", "m_trajectories", false, value);
}
std::string GCFootStride::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootStride::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFootStride(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootStride>("CFootStride")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Definition", &GCFootStride::GetDefinition, &GCFootStride::SetDefinition)
        .addProperty("Trajectories", &GCFootStride::GetTrajectories, &GCFootStride::SetTrajectories)
        .addFunction("ToPtr", &GCFootStride::ToPtr)
        .addFunction("IsValid", &GCFootStride::IsValid)
        .endClass();
}