#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GQuestProgress::GQuestProgress(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GQuestProgress::GQuestProgress(void *ptr) {
    m_ptr = ptr;
}
std::string GQuestProgress::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GQuestProgress::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassQuestProgress(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GQuestProgress>("QuestProgress")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GQuestProgress::ToPtr)
        .addFunction("IsValid", &GQuestProgress::IsValid)
        .endClass();
}