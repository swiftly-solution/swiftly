#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFlashbang::GCFlashbang(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFlashbang::GCFlashbang(void *ptr) {
    m_ptr = ptr;
}
std::string GCFlashbang::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFlashbang::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenade GCFlashbang::GetParent() const {
    GCBaseCSGrenade value(m_ptr);
    return value;
}
void GCFlashbang::SetParent(GCBaseCSGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFlashbang(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlashbang>("CFlashbang")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFlashbang::GetParent, &GCFlashbang::SetParent)
        .addFunction("ToPtr", &GCFlashbang::ToPtr)
        .addFunction("IsValid", &GCFlashbang::IsValid)
        .endClass();
}