#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavLinkAnimgraphVar::GCNavLinkAnimgraphVar(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavLinkAnimgraphVar::GCNavLinkAnimgraphVar(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCNavLinkAnimgraphVar::GetAlignmentDegrees() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CNavLinkAnimgraphVar", "m_unAlignmentDegrees");
}
void GCNavLinkAnimgraphVar::SetAlignmentDegrees(uint32_t value) {
    SetSchemaValue(m_ptr, "CNavLinkAnimgraphVar", "m_unAlignmentDegrees", false, value);
}
std::string GCNavLinkAnimgraphVar::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavLinkAnimgraphVar::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNavLinkAnimgraphVar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavLinkAnimgraphVar>("CNavLinkAnimgraphVar")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AlignmentDegrees", &GCNavLinkAnimgraphVar::GetAlignmentDegrees, &GCNavLinkAnimgraphVar::SetAlignmentDegrees)
        .addFunction("ToPtr", &GCNavLinkAnimgraphVar::ToPtr)
        .addFunction("IsValid", &GCNavLinkAnimgraphVar::IsValid)
        .endClass();
}