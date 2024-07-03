#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRuleBrushEntity::GCRuleBrushEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRuleBrushEntity::GCRuleBrushEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCRuleBrushEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRuleBrushEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCRuleEntity GCRuleBrushEntity::GetParent() const {
    GCRuleEntity value(m_ptr);
    return value;
}
void GCRuleBrushEntity::SetParent(GCRuleEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRuleBrushEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRuleBrushEntity>("CRuleBrushEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCRuleBrushEntity::GetParent, &GCRuleBrushEntity::SetParent)
        .addFunction("ToPtr", &GCRuleBrushEntity::ToPtr)
        .addFunction("IsValid", &GCRuleBrushEntity::IsValid)
        .endClass();
}