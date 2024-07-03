#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathMover::GCPathMover(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathMover::GCPathMover(void *ptr) {
    m_ptr = ptr;
}
float GCPathMover::GetPathLength() const {
    return GetSchemaValue<float>(m_ptr, "CPathMover", "m_flPathLength");
}
void GCPathMover::SetPathLength(float value) {
    SetSchemaValue(m_ptr, "CPathMover", "m_flPathLength", false, value);
}
bool GCPathMover::GetClosedLoop() const {
    return GetSchemaValue<bool>(m_ptr, "CPathMover", "m_bClosedLoop");
}
void GCPathMover::SetClosedLoop(bool value) {
    SetSchemaValue(m_ptr, "CPathMover", "m_bClosedLoop", false, value);
}
std::string GCPathMover::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathMover::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPathMover::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPathMover::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathMover(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathMover>("CPathMover")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PathLength", &GCPathMover::GetPathLength, &GCPathMover::SetPathLength)
        .addProperty("ClosedLoop", &GCPathMover::GetClosedLoop, &GCPathMover::SetClosedLoop)
        .addProperty("Parent", &GCPathMover::GetParent, &GCPathMover::SetParent)
        .addFunction("ToPtr", &GCPathMover::ToPtr)
        .addFunction("IsValid", &GCPathMover::IsValid)
        .endClass();
}