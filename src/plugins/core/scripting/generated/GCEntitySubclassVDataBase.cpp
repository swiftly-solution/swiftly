#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEntitySubclassVDataBase::GCEntitySubclassVDataBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEntitySubclassVDataBase::GCEntitySubclassVDataBase(void *ptr) {
    m_ptr = ptr;
}
std::string GCEntitySubclassVDataBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEntitySubclassVDataBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEntitySubclassVDataBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntitySubclassVDataBase>("CEntitySubclassVDataBase")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCEntitySubclassVDataBase::ToPtr)
        .addFunction("IsValid", &GCEntitySubclassVDataBase::IsValid)
        .endClass();
}