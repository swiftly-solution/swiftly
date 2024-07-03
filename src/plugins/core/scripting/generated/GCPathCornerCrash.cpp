#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathCornerCrash::GCPathCornerCrash(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathCornerCrash::GCPathCornerCrash(void *ptr) {
    m_ptr = ptr;
}
std::string GCPathCornerCrash::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathCornerCrash::IsValid() {
    return (m_ptr != nullptr);
}
GCPathCorner GCPathCornerCrash::GetParent() const {
    GCPathCorner value(m_ptr);
    return value;
}
void GCPathCornerCrash::SetParent(GCPathCorner value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathCornerCrash(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathCornerCrash>("CPathCornerCrash")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPathCornerCrash::GetParent, &GCPathCornerCrash::SetParent)
        .addFunction("ToPtr", &GCPathCornerCrash::ToPtr)
        .addFunction("IsValid", &GCPathCornerCrash::IsValid)
        .endClass();
}