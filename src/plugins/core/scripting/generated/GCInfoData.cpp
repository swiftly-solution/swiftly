#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoData::GCInfoData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoData::GCInfoData(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoData::IsValid() {
    return (m_ptr != nullptr);
}
GCServerOnlyEntity GCInfoData::GetParent() const {
    GCServerOnlyEntity value(m_ptr);
    return value;
}
void GCInfoData::SetParent(GCServerOnlyEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoData>("CInfoData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoData::GetParent, &GCInfoData::SetParent)
        .addFunction("ToPtr", &GCInfoData::ToPtr)
        .addFunction("IsValid", &GCInfoData::IsValid)
        .endClass();
}