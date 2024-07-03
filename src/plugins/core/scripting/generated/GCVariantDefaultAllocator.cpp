#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVariantDefaultAllocator::GCVariantDefaultAllocator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVariantDefaultAllocator::GCVariantDefaultAllocator(void *ptr) {
    m_ptr = ptr;
}
std::string GCVariantDefaultAllocator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVariantDefaultAllocator::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCVariantDefaultAllocator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVariantDefaultAllocator>("CVariantDefaultAllocator")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCVariantDefaultAllocator::ToPtr)
        .addFunction("IsValid", &GCVariantDefaultAllocator::IsValid)
        .endClass();
}