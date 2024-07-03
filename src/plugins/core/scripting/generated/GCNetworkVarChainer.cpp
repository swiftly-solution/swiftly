#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNetworkVarChainer::GCNetworkVarChainer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNetworkVarChainer::GCNetworkVarChainer(void *ptr) {
    m_ptr = ptr;
}
GChangeAccessorFieldPathIndex_t GCNetworkVarChainer::GetPathIndex() const {
    GChangeAccessorFieldPathIndex_t value(GetSchemaPtr(m_ptr, "CNetworkVarChainer", "m_PathIndex"));
    return value;
}
void GCNetworkVarChainer::SetPathIndex(GChangeAccessorFieldPathIndex_t value) {
    SetSchemaValue(m_ptr, "CNetworkVarChainer", "m_PathIndex", false, value);
}
std::string GCNetworkVarChainer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNetworkVarChainer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNetworkVarChainer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkVarChainer>("CNetworkVarChainer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PathIndex", &GCNetworkVarChainer::GetPathIndex, &GCNetworkVarChainer::SetPathIndex)
        .addFunction("ToPtr", &GCNetworkVarChainer::ToPtr)
        .addFunction("IsValid", &GCNetworkVarChainer::IsValid)
        .endClass();
}