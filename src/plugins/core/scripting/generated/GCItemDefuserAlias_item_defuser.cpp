#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCItemDefuserAlias_item_defuser::GCItemDefuserAlias_item_defuser(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCItemDefuserAlias_item_defuser::GCItemDefuserAlias_item_defuser(void *ptr) {
    m_ptr = ptr;
}
std::string GCItemDefuserAlias_item_defuser::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCItemDefuserAlias_item_defuser::IsValid() {
    return (m_ptr != nullptr);
}
GCItemDefuser GCItemDefuserAlias_item_defuser::GetParent() const {
    GCItemDefuser value(m_ptr);
    return value;
}
void GCItemDefuserAlias_item_defuser::SetParent(GCItemDefuser value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCItemDefuserAlias_item_defuser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemDefuserAlias_item_defuser>("CItemDefuserAlias_item_defuser")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCItemDefuserAlias_item_defuser::GetParent, &GCItemDefuserAlias_item_defuser::SetParent)
        .addFunction("ToPtr", &GCItemDefuserAlias_item_defuser::ToPtr)
        .addFunction("IsValid", &GCItemDefuserAlias_item_defuser::IsValid)
        .endClass();
}