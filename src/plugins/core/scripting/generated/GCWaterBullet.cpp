#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWaterBullet::GCWaterBullet(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWaterBullet::GCWaterBullet(void *ptr) {
    m_ptr = ptr;
}
std::string GCWaterBullet::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWaterBullet::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCWaterBullet::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCWaterBullet::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWaterBullet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWaterBullet>("CWaterBullet")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWaterBullet::GetParent, &GCWaterBullet::SetParent)
        .addFunction("ToPtr", &GCWaterBullet::ToPtr)
        .addFunction("IsValid", &GCWaterBullet::IsValid)
        .endClass();
}