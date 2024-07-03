#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBodyComponentSkeletonInstance::GCBodyComponentSkeletonInstance(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBodyComponentSkeletonInstance::GCBodyComponentSkeletonInstance(void *ptr) {
    m_ptr = ptr;
}
GCSkeletonInstance GCBodyComponentSkeletonInstance::GetSkeletonInstance() const {
    GCSkeletonInstance value(GetSchemaPtr(m_ptr, "CBodyComponentSkeletonInstance", "m_skeletonInstance"));
    return value;
}
void GCBodyComponentSkeletonInstance::SetSkeletonInstance(GCSkeletonInstance value) {
    SetSchemaValue(m_ptr, "CBodyComponentSkeletonInstance", "m_skeletonInstance", false, value);
}
std::string GCBodyComponentSkeletonInstance::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBodyComponentSkeletonInstance::IsValid() {
    return (m_ptr != nullptr);
}
GCBodyComponent GCBodyComponentSkeletonInstance::GetParent() const {
    GCBodyComponent value(m_ptr);
    return value;
}
void GCBodyComponentSkeletonInstance::SetParent(GCBodyComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBodyComponentSkeletonInstance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyComponentSkeletonInstance>("CBodyComponentSkeletonInstance")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SkeletonInstance", &GCBodyComponentSkeletonInstance::GetSkeletonInstance, &GCBodyComponentSkeletonInstance::SetSkeletonInstance)
        .addProperty("Parent", &GCBodyComponentSkeletonInstance::GetParent, &GCBodyComponentSkeletonInstance::SetParent)
        .addFunction("ToPtr", &GCBodyComponentSkeletonInstance::ToPtr)
        .addFunction("IsValid", &GCBodyComponentSkeletonInstance::IsValid)
        .endClass();
}