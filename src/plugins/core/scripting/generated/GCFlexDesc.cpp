#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFlexDesc::GCFlexDesc(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFlexDesc::GCFlexDesc(void *ptr) {
    m_ptr = ptr;
}
std::string GCFlexDesc::GetFacs() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFlexDesc", "m_szFacs").Get();
}
void GCFlexDesc::SetFacs(std::string value) {
    SetSchemaValue(m_ptr, "CFlexDesc", "m_szFacs", false, CUtlString(value.c_str()));
}
std::string GCFlexDesc::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFlexDesc::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFlexDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlexDesc>("CFlexDesc")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Facs", &GCFlexDesc::GetFacs, &GCFlexDesc::SetFacs)
        .addFunction("ToPtr", &GCFlexDesc::ToPtr)
        .addFunction("IsValid", &GCFlexDesc::IsValid)
        .endClass();
}