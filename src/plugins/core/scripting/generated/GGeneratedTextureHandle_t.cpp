#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GGeneratedTextureHandle_t::GGeneratedTextureHandle_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GGeneratedTextureHandle_t::GGeneratedTextureHandle_t(void *ptr) {
    m_ptr = ptr;
}
std::string GGeneratedTextureHandle_t::GetStrBitmapName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "GeneratedTextureHandle_t", "m_strBitmapName").Get();
}
void GGeneratedTextureHandle_t::SetStrBitmapName(std::string value) {
    SetSchemaValue(m_ptr, "GeneratedTextureHandle_t", "m_strBitmapName", true, CUtlString(value.c_str()));
}
std::string GGeneratedTextureHandle_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GGeneratedTextureHandle_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassGeneratedTextureHandle_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GGeneratedTextureHandle_t>("GeneratedTextureHandle_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StrBitmapName", &GGeneratedTextureHandle_t::GetStrBitmapName, &GGeneratedTextureHandle_t::SetStrBitmapName)
        .addFunction("ToPtr", &GGeneratedTextureHandle_t::ToPtr)
        .addFunction("IsValid", &GGeneratedTextureHandle_t::IsValid)
        .endClass();
}