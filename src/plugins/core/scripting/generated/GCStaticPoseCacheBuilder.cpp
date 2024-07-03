#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStaticPoseCacheBuilder::GCStaticPoseCacheBuilder(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStaticPoseCacheBuilder::GCStaticPoseCacheBuilder(void *ptr) {
    m_ptr = ptr;
}
std::string GCStaticPoseCacheBuilder::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStaticPoseCacheBuilder::IsValid() {
    return (m_ptr != nullptr);
}
GCStaticPoseCache GCStaticPoseCacheBuilder::GetParent() const {
    GCStaticPoseCache value(m_ptr);
    return value;
}
void GCStaticPoseCacheBuilder::SetParent(GCStaticPoseCache value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCStaticPoseCacheBuilder(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStaticPoseCacheBuilder>("CStaticPoseCacheBuilder")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCStaticPoseCacheBuilder::GetParent, &GCStaticPoseCacheBuilder::SetParent)
        .addFunction("ToPtr", &GCStaticPoseCacheBuilder::ToPtr)
        .addFunction("IsValid", &GCStaticPoseCacheBuilder::IsValid)
        .endClass();
}