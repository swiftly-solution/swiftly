#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBoneConstraintBase::GCBoneConstraintBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBoneConstraintBase::GCBoneConstraintBase(void *ptr) {
    m_ptr = ptr;
}
std::string GCBoneConstraintBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBoneConstraintBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBoneConstraintBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintBase>("CBoneConstraintBase")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCBoneConstraintBase::ToPtr)
        .addFunction("IsValid", &GCBoneConstraintBase::IsValid)
        .endClass();
}