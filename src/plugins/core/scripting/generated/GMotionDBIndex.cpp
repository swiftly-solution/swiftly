#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMotionDBIndex::GMotionDBIndex(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMotionDBIndex::GMotionDBIndex(void *ptr) {
    m_ptr = ptr;
}
uint32_t GMotionDBIndex::GetIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "MotionDBIndex", "m_nIndex");
}
void GMotionDBIndex::SetIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "MotionDBIndex", "m_nIndex", false, value);
}
std::string GMotionDBIndex::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMotionDBIndex::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassMotionDBIndex(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMotionDBIndex>("MotionDBIndex")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Index", &GMotionDBIndex::GetIndex, &GMotionDBIndex::SetIndex)
        .addFunction("ToPtr", &GMotionDBIndex::ToPtr)
        .addFunction("IsValid", &GMotionDBIndex::IsValid)
        .endClass();
}