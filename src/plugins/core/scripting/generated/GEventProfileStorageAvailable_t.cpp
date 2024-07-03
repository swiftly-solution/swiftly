#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventProfileStorageAvailable_t::GEventProfileStorageAvailable_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventProfileStorageAvailable_t::GEventProfileStorageAvailable_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GEventProfileStorageAvailable_t::GetSplitScreenSlot() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventProfileStorageAvailable_t", "m_nSplitScreenSlot");
}
void GEventProfileStorageAvailable_t::SetSplitScreenSlot(int32_t value) {
    SetSchemaValue(m_ptr, "EventProfileStorageAvailable_t", "m_nSplitScreenSlot", true, value);
}
std::string GEventProfileStorageAvailable_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventProfileStorageAvailable_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventProfileStorageAvailable_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventProfileStorageAvailable_t>("EventProfileStorageAvailable_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SplitScreenSlot", &GEventProfileStorageAvailable_t::GetSplitScreenSlot, &GEventProfileStorageAvailable_t::SetSplitScreenSlot)
        .addFunction("ToPtr", &GEventProfileStorageAvailable_t::ToPtr)
        .addFunction("IsValid", &GEventProfileStorageAvailable_t::IsValid)
        .endClass();
}