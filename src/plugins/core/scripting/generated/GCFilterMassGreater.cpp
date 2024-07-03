#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFilterMassGreater::GCFilterMassGreater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFilterMassGreater::GCFilterMassGreater(void *ptr) {
    m_ptr = ptr;
}
float GCFilterMassGreater::GetFilterMass() const {
    return GetSchemaValue<float>(m_ptr, "CFilterMassGreater", "m_fFilterMass");
}
void GCFilterMassGreater::SetFilterMass(float value) {
    SetSchemaValue(m_ptr, "CFilterMassGreater", "m_fFilterMass", false, value);
}
std::string GCFilterMassGreater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFilterMassGreater::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GCFilterMassGreater::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GCFilterMassGreater::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFilterMassGreater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterMassGreater>("CFilterMassGreater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FilterMass", &GCFilterMassGreater::GetFilterMass, &GCFilterMassGreater::SetFilterMass)
        .addProperty("Parent", &GCFilterMassGreater::GetParent, &GCFilterMassGreater::SetParent)
        .addFunction("ToPtr", &GCFilterMassGreater::ToPtr)
        .addFunction("IsValid", &GCFilterMassGreater::IsValid)
        .endClass();
}