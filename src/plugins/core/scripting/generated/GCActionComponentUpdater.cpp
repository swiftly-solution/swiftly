#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCActionComponentUpdater::GCActionComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCActionComponentUpdater::GCActionComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
std::string GCActionComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCActionComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCActionComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCActionComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCActionComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCActionComponentUpdater>("CActionComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCActionComponentUpdater::GetParent, &GCActionComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCActionComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCActionComponentUpdater::IsValid)
        .endClass();
}