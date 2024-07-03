#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimGraphModelBinding::GCAnimGraphModelBinding(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimGraphModelBinding::GCAnimGraphModelBinding(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimGraphModelBinding::GetModelName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimGraphModelBinding", "m_modelName").Get();
}
void GCAnimGraphModelBinding::SetModelName(std::string value) {
    SetSchemaValue(m_ptr, "CAnimGraphModelBinding", "m_modelName", false, CUtlString(value.c_str()));
}
std::string GCAnimGraphModelBinding::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimGraphModelBinding::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimGraphModelBinding(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphModelBinding>("CAnimGraphModelBinding")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ModelName", &GCAnimGraphModelBinding::GetModelName, &GCAnimGraphModelBinding::SetModelName)
        .addFunction("ToPtr", &GCAnimGraphModelBinding::ToPtr)
        .addFunction("IsValid", &GCAnimGraphModelBinding::IsValid)
        .endClass();
}