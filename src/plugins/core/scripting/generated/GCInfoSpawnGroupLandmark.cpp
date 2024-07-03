#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoSpawnGroupLandmark::GCInfoSpawnGroupLandmark(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoSpawnGroupLandmark::GCInfoSpawnGroupLandmark(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoSpawnGroupLandmark::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoSpawnGroupLandmark::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoSpawnGroupLandmark::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoSpawnGroupLandmark::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoSpawnGroupLandmark(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoSpawnGroupLandmark>("CInfoSpawnGroupLandmark")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoSpawnGroupLandmark::GetParent, &GCInfoSpawnGroupLandmark::SetParent)
        .addFunction("ToPtr", &GCInfoSpawnGroupLandmark::ToPtr)
        .addFunction("IsValid", &GCInfoSpawnGroupLandmark::IsValid)
        .endClass();
}