#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStateActionUpdater::GCStateActionUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStateActionUpdater::GCStateActionUpdater(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCStateActionUpdater::GetBehavior() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CStateActionUpdater", "m_eBehavior");
}
void GCStateActionUpdater::SetBehavior(uint64_t value) {
    SetSchemaValue(m_ptr, "CStateActionUpdater", "m_eBehavior", false, value);
}
std::string GCStateActionUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStateActionUpdater::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCStateActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateActionUpdater>("CStateActionUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Behavior", &GCStateActionUpdater::GetBehavior, &GCStateActionUpdater::SetBehavior)
        .addFunction("ToPtr", &GCStateActionUpdater::ToPtr)
        .addFunction("IsValid", &GCStateActionUpdater::IsValid)
        .endClass();
}