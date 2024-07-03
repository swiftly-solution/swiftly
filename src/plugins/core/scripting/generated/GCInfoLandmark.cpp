#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoLandmark::GCInfoLandmark(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoLandmark::GCInfoLandmark(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoLandmark::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoLandmark::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoLandmark::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoLandmark::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoLandmark(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoLandmark>("CInfoLandmark")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoLandmark::GetParent, &GCInfoLandmark::SetParent)
        .addFunction("ToPtr", &GCInfoLandmark::ToPtr)
        .addFunction("IsValid", &GCInfoLandmark::IsValid)
        .endClass();
}