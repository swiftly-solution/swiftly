#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimScriptBase::GCAnimScriptBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimScriptBase::GCAnimScriptBase(void *ptr) {
    m_ptr = ptr;
}
bool GCAnimScriptBase::GetIsValid() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimScriptBase", "m_bIsValid");
}
void GCAnimScriptBase::SetIsValid(bool value) {
    SetSchemaValue(m_ptr, "CAnimScriptBase", "m_bIsValid", false, value);
}
std::string GCAnimScriptBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimScriptBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimScriptBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimScriptBase>("CAnimScriptBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IsValid", &GCAnimScriptBase::GetIsValid, &GCAnimScriptBase::SetIsValid)
        .addFunction("ToPtr", &GCAnimScriptBase::ToPtr)
        .addFunction("IsValid", &GCAnimScriptBase::IsValid)
        .endClass();
}