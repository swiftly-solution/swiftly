#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSSDSMsg_PreLayer::GCSSDSMsg_PreLayer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSSDSMsg_PreLayer::GCSSDSMsg_PreLayer(void *ptr) {
    m_ptr = ptr;
}
std::string GCSSDSMsg_PreLayer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSSDSMsg_PreLayer::IsValid() {
    return (m_ptr != nullptr);
}
GCSSDSMsg_LayerBase GCSSDSMsg_PreLayer::GetParent() const {
    GCSSDSMsg_LayerBase value(m_ptr);
    return value;
}
void GCSSDSMsg_PreLayer::SetParent(GCSSDSMsg_LayerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSSDSMsg_PreLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_PreLayer>("CSSDSMsg_PreLayer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSSDSMsg_PreLayer::GetParent, &GCSSDSMsg_PreLayer::SetParent)
        .addFunction("ToPtr", &GCSSDSMsg_PreLayer::ToPtr)
        .addFunction("IsValid", &GCSSDSMsg_PreLayer::IsValid)
        .endClass();
}