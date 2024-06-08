#include "../../../core/scripting/generated/classes/GFeCtrlOffset_t.h"
#include "../core.h"

void SetupLuaClassGFeCtrlOffset_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeCtrlOffset_t>("FeCtrlOffset_t")
        .addProperty("Offset", &GFeCtrlOffset_t::GetOffset, &GFeCtrlOffset_t::SetOffset)
        .addProperty("CtrlParent", &GFeCtrlOffset_t::GetCtrlParent, &GFeCtrlOffset_t::SetCtrlParent)
        .addProperty("CtrlChild", &GFeCtrlOffset_t::GetCtrlChild, &GFeCtrlOffset_t::SetCtrlChild)
        .endClass();
}