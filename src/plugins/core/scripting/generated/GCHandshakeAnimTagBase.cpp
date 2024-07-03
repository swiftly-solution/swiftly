#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHandshakeAnimTagBase::GCHandshakeAnimTagBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHandshakeAnimTagBase::GCHandshakeAnimTagBase(void *ptr) {
    m_ptr = ptr;
}
bool GCHandshakeAnimTagBase::GetIsDisableTag() const {
    return GetSchemaValue<bool>(m_ptr, "CHandshakeAnimTagBase", "m_bIsDisableTag");
}
void GCHandshakeAnimTagBase::SetIsDisableTag(bool value) {
    SetSchemaValue(m_ptr, "CHandshakeAnimTagBase", "m_bIsDisableTag", false, value);
}
std::string GCHandshakeAnimTagBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHandshakeAnimTagBase::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCHandshakeAnimTagBase::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCHandshakeAnimTagBase::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHandshakeAnimTagBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHandshakeAnimTagBase>("CHandshakeAnimTagBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IsDisableTag", &GCHandshakeAnimTagBase::GetIsDisableTag, &GCHandshakeAnimTagBase::SetIsDisableTag)
        .addProperty("Parent", &GCHandshakeAnimTagBase::GetParent, &GCHandshakeAnimTagBase::SetParent)
        .addFunction("ToPtr", &GCHandshakeAnimTagBase::ToPtr)
        .addFunction("IsValid", &GCHandshakeAnimTagBase::IsValid)
        .endClass();
}