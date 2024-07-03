#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathCorner::GCPathCorner(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathCorner::GCPathCorner(void *ptr) {
    m_ptr = ptr;
}
float GCPathCorner::GetWait() const {
    return GetSchemaValue<float>(m_ptr, "CPathCorner", "m_flWait");
}
void GCPathCorner::SetWait(float value) {
    SetSchemaValue(m_ptr, "CPathCorner", "m_flWait", false, value);
}
float GCPathCorner::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CPathCorner", "m_flRadius");
}
void GCPathCorner::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CPathCorner", "m_flRadius", false, value);
}
GCEntityIOOutput GCPathCorner::GetOnPass() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPathCorner", "m_OnPass"));
    return value;
}
void GCPathCorner::SetOnPass(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPathCorner", "m_OnPass", false, value);
}
std::string GCPathCorner::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathCorner::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPathCorner::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPathCorner::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathCorner(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathCorner>("CPathCorner")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Wait", &GCPathCorner::GetWait, &GCPathCorner::SetWait)
        .addProperty("Radius", &GCPathCorner::GetRadius, &GCPathCorner::SetRadius)
        .addProperty("OnPass", &GCPathCorner::GetOnPass, &GCPathCorner::SetOnPass)
        .addProperty("Parent", &GCPathCorner::GetParent, &GCPathCorner::SetParent)
        .addFunction("ToPtr", &GCPathCorner::ToPtr)
        .addFunction("IsValid", &GCPathCorner::IsValid)
        .endClass();
}