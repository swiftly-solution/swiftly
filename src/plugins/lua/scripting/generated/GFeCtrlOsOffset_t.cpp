#include "../../../core/scripting/generated/classes/GFeCtrlOsOffset_t.h"
#include "../core.h"

void SetupLuaClassGFeCtrlOsOffset_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeCtrlOsOffset_t>("FeCtrlOsOffset_t")
        .addProperty("CtrlParent", &GFeCtrlOsOffset_t::GetCtrlParent, &GFeCtrlOsOffset_t::SetCtrlParent)
        .addProperty("CtrlChild", &GFeCtrlOsOffset_t::GetCtrlChild, &GFeCtrlOsOffset_t::SetCtrlChild)
        .endClass();
}