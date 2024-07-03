#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoLadderDismount::GCInfoLadderDismount(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoLadderDismount::GCInfoLadderDismount(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoLadderDismount::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoLadderDismount::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCInfoLadderDismount::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCInfoLadderDismount::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoLadderDismount(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoLadderDismount>("CInfoLadderDismount")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoLadderDismount::GetParent, &GCInfoLadderDismount::SetParent)
        .addFunction("ToPtr", &GCInfoLadderDismount::ToPtr)
        .addFunction("IsValid", &GCInfoLadderDismount::IsValid)
        .endClass();
}