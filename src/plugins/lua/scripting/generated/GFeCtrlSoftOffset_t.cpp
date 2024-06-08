#include "../../../core/scripting/generated/classes/GFeCtrlSoftOffset_t.h"
#include "../core.h"

void SetupLuaClassGFeCtrlSoftOffset_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeCtrlSoftOffset_t>("FeCtrlSoftOffset_t")
        .addProperty("CtrlParent", &GFeCtrlSoftOffset_t::GetCtrlParent, &GFeCtrlSoftOffset_t::SetCtrlParent)
        .addProperty("CtrlChild", &GFeCtrlSoftOffset_t::GetCtrlChild, &GFeCtrlSoftOffset_t::SetCtrlChild)
        .addProperty("Offset", &GFeCtrlSoftOffset_t::GetOffset, &GFeCtrlSoftOffset_t::SetOffset)
        .addProperty("Alpha", &GFeCtrlSoftOffset_t::GetAlpha, &GFeCtrlSoftOffset_t::SetAlpha)
        .endClass();
}