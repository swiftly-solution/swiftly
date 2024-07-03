#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMarkupVolumeWithRef::GCMarkupVolumeWithRef(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMarkupVolumeWithRef::GCMarkupVolumeWithRef(void *ptr) {
    m_ptr = ptr;
}
bool GCMarkupVolumeWithRef::GetUseRef() const {
    return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeWithRef", "m_bUseRef");
}
void GCMarkupVolumeWithRef::SetUseRef(bool value) {
    SetSchemaValue(m_ptr, "CMarkupVolumeWithRef", "m_bUseRef", false, value);
}
Vector GCMarkupVolumeWithRef::GetRefPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CMarkupVolumeWithRef", "m_vRefPos");
}
void GCMarkupVolumeWithRef::SetRefPos(Vector value) {
    SetSchemaValue(m_ptr, "CMarkupVolumeWithRef", "m_vRefPos", false, value);
}
float GCMarkupVolumeWithRef::GetRefDot() const {
    return GetSchemaValue<float>(m_ptr, "CMarkupVolumeWithRef", "m_flRefDot");
}
void GCMarkupVolumeWithRef::SetRefDot(float value) {
    SetSchemaValue(m_ptr, "CMarkupVolumeWithRef", "m_flRefDot", false, value);
}
std::string GCMarkupVolumeWithRef::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMarkupVolumeWithRef::IsValid() {
    return (m_ptr != nullptr);
}
GCMarkupVolumeTagged GCMarkupVolumeWithRef::GetParent() const {
    GCMarkupVolumeTagged value(m_ptr);
    return value;
}
void GCMarkupVolumeWithRef::SetParent(GCMarkupVolumeTagged value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMarkupVolumeWithRef(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMarkupVolumeWithRef>("CMarkupVolumeWithRef")
        .addConstructor<void (*)(std::string)>()
        .addProperty("UseRef", &GCMarkupVolumeWithRef::GetUseRef, &GCMarkupVolumeWithRef::SetUseRef)
        .addProperty("RefPos", &GCMarkupVolumeWithRef::GetRefPos, &GCMarkupVolumeWithRef::SetRefPos)
        .addProperty("RefDot", &GCMarkupVolumeWithRef::GetRefDot, &GCMarkupVolumeWithRef::SetRefDot)
        .addProperty("Parent", &GCMarkupVolumeWithRef::GetParent, &GCMarkupVolumeWithRef::SetParent)
        .addFunction("ToPtr", &GCMarkupVolumeWithRef::ToPtr)
        .addFunction("IsValid", &GCMarkupVolumeWithRef::IsValid)
        .endClass();
}