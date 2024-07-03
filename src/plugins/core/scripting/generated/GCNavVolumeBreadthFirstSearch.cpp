#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavVolumeBreadthFirstSearch::GCNavVolumeBreadthFirstSearch(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavVolumeBreadthFirstSearch::GCNavVolumeBreadthFirstSearch(void *ptr) {
    m_ptr = ptr;
}
Vector GCNavVolumeBreadthFirstSearch::GetStartPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CNavVolumeBreadthFirstSearch", "m_vStartPos");
}
void GCNavVolumeBreadthFirstSearch::SetStartPos(Vector value) {
    SetSchemaValue(m_ptr, "CNavVolumeBreadthFirstSearch", "m_vStartPos", false, value);
}
float GCNavVolumeBreadthFirstSearch::GetSearchDist() const {
    return GetSchemaValue<float>(m_ptr, "CNavVolumeBreadthFirstSearch", "m_flSearchDist");
}
void GCNavVolumeBreadthFirstSearch::SetSearchDist(float value) {
    SetSchemaValue(m_ptr, "CNavVolumeBreadthFirstSearch", "m_flSearchDist", false, value);
}
std::string GCNavVolumeBreadthFirstSearch::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavVolumeBreadthFirstSearch::IsValid() {
    return (m_ptr != nullptr);
}
GCNavVolumeCalculatedVector GCNavVolumeBreadthFirstSearch::GetParent() const {
    GCNavVolumeCalculatedVector value(m_ptr);
    return value;
}
void GCNavVolumeBreadthFirstSearch::SetParent(GCNavVolumeCalculatedVector value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNavVolumeBreadthFirstSearch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeBreadthFirstSearch>("CNavVolumeBreadthFirstSearch")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartPos", &GCNavVolumeBreadthFirstSearch::GetStartPos, &GCNavVolumeBreadthFirstSearch::SetStartPos)
        .addProperty("SearchDist", &GCNavVolumeBreadthFirstSearch::GetSearchDist, &GCNavVolumeBreadthFirstSearch::SetSearchDist)
        .addProperty("Parent", &GCNavVolumeBreadthFirstSearch::GetParent, &GCNavVolumeBreadthFirstSearch::SetParent)
        .addFunction("ToPtr", &GCNavVolumeBreadthFirstSearch::ToPtr)
        .addFunction("IsValid", &GCNavVolumeBreadthFirstSearch::IsValid)
        .endClass();
}