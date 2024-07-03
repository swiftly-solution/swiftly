#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCItemSoda::GCItemSoda(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCItemSoda::GCItemSoda(void *ptr) {
    m_ptr = ptr;
}
std::string GCItemSoda::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCItemSoda::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCItemSoda::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCItemSoda::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCItemSoda(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemSoda>("CItemSoda")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCItemSoda::GetParent, &GCItemSoda::SetParent)
        .addFunction("ToPtr", &GCItemSoda::ToPtr)
        .addFunction("IsValid", &GCItemSoda::IsValid)
        .endClass();
}