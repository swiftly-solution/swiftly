#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncTrackAuto::GCFuncTrackAuto(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncTrackAuto::GCFuncTrackAuto(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncTrackAuto::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncTrackAuto::IsValid() {
    return (m_ptr != nullptr);
}
GCFuncTrackChange GCFuncTrackAuto::GetParent() const {
    GCFuncTrackChange value(m_ptr);
    return value;
}
void GCFuncTrackAuto::SetParent(GCFuncTrackChange value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncTrackAuto(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTrackAuto>("CFuncTrackAuto")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFuncTrackAuto::GetParent, &GCFuncTrackAuto::SetParent)
        .addFunction("ToPtr", &GCFuncTrackAuto::ToPtr)
        .addFunction("IsValid", &GCFuncTrackAuto::IsValid)
        .endClass();
}