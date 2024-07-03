#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseFlexAlias_funCBaseFlex::GCBaseFlexAlias_funCBaseFlex(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseFlexAlias_funCBaseFlex::GCBaseFlexAlias_funCBaseFlex(void *ptr) {
    m_ptr = ptr;
}
std::string GCBaseFlexAlias_funCBaseFlex::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseFlexAlias_funCBaseFlex::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFlex GCBaseFlexAlias_funCBaseFlex::GetParent() const {
    GCBaseFlex value(m_ptr);
    return value;
}
void GCBaseFlexAlias_funCBaseFlex::SetParent(GCBaseFlex value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseFlexAlias_funCBaseFlex(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseFlexAlias_funCBaseFlex>("CBaseFlexAlias_funCBaseFlex")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCBaseFlexAlias_funCBaseFlex::GetParent, &GCBaseFlexAlias_funCBaseFlex::SetParent)
        .addFunction("ToPtr", &GCBaseFlexAlias_funCBaseFlex::ToPtr)
        .addFunction("IsValid", &GCBaseFlexAlias_funCBaseFlex::IsValid)
        .endClass();
}