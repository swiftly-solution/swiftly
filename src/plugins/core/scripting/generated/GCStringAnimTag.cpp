#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStringAnimTag::GCStringAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStringAnimTag::GCStringAnimTag(void *ptr) {
    m_ptr = ptr;
}
std::string GCStringAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStringAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCStringAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCStringAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCStringAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStringAnimTag>("CStringAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCStringAnimTag::GetParent, &GCStringAnimTag::SetParent)
        .addFunction("ToPtr", &GCStringAnimTag::ToPtr)
        .addFunction("IsValid", &GCStringAnimTag::IsValid)
        .endClass();
}