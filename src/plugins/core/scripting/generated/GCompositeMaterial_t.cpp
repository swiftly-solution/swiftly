#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCompositeMaterial_t::GCompositeMaterial_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCompositeMaterial_t::GCompositeMaterial_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GGeneratedTextureHandle_t> GCompositeMaterial_t::GetGeneratedTextures() const {
    CUtlVector<GGeneratedTextureHandle_t>* vec = GetSchemaValue<CUtlVector<GGeneratedTextureHandle_t>*>(m_ptr, "CompositeMaterial_t", "m_vecGeneratedTextures"); std::vector<GGeneratedTextureHandle_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompositeMaterial_t::SetGeneratedTextures(std::vector<GGeneratedTextureHandle_t> value) {
    SetSchemaValueCUtlVector<GGeneratedTextureHandle_t>(m_ptr, "CompositeMaterial_t", "m_vecGeneratedTextures", true, value);
}
std::string GCompositeMaterial_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCompositeMaterial_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCompositeMaterial_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterial_t>("CompositeMaterial_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GeneratedTextures", &GCompositeMaterial_t::GetGeneratedTextures, &GCompositeMaterial_t::SetGeneratedTextures)
        .addFunction("ToPtr", &GCompositeMaterial_t::ToPtr)
        .addFunction("IsValid", &GCompositeMaterial_t::IsValid)
        .endClass();
}