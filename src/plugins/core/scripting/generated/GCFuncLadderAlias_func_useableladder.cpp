#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncLadderAlias_func_useableladder::GCFuncLadderAlias_func_useableladder(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncLadderAlias_func_useableladder::GCFuncLadderAlias_func_useableladder(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncLadderAlias_func_useableladder::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncLadderAlias_func_useableladder::IsValid() {
    return (m_ptr != nullptr);
}
GCFuncLadder GCFuncLadderAlias_func_useableladder::GetParent() const {
    GCFuncLadder value(m_ptr);
    return value;
}
void GCFuncLadderAlias_func_useableladder::SetParent(GCFuncLadder value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncLadderAlias_func_useableladder(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncLadderAlias_func_useableladder>("CFuncLadderAlias_func_useableladder")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFuncLadderAlias_func_useableladder::GetParent, &GCFuncLadderAlias_func_useableladder::SetParent)
        .addFunction("ToPtr", &GCFuncLadderAlias_func_useableladder::ToPtr)
        .addFunction("IsValid", &GCFuncLadderAlias_func_useableladder::IsValid)
        .endClass();
}