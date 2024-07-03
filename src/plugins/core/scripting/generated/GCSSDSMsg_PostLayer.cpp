#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSSDSMsg_PostLayer::GCSSDSMsg_PostLayer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSSDSMsg_PostLayer::GCSSDSMsg_PostLayer(void *ptr) {
    m_ptr = ptr;
}
std::string GCSSDSMsg_PostLayer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSSDSMsg_PostLayer::IsValid() {
    return (m_ptr != nullptr);
}
GCSSDSMsg_LayerBase GCSSDSMsg_PostLayer::GetParent() const {
    GCSSDSMsg_LayerBase value(m_ptr);
    return value;
}
void GCSSDSMsg_PostLayer::SetParent(GCSSDSMsg_LayerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSSDSMsg_PostLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_PostLayer>("CSSDSMsg_PostLayer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSSDSMsg_PostLayer::GetParent, &GCSSDSMsg_PostLayer::SetParent)
        .addFunction("ToPtr", &GCSSDSMsg_PostLayer::ToPtr)
        .addFunction("IsValid", &GCSSDSMsg_PostLayer::IsValid)
        .endClass();
}