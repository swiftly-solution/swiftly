#include "../../../core/scripting/generated/classes/GControlPointReference_t.h"
#include "../core.h"

void SetupLuaClassGControlPointReference_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GControlPointReference_t>("ControlPointReference_t")
        .addProperty("ControlPointNameString", &GControlPointReference_t::GetControlPointNameString, &GControlPointReference_t::SetControlPointNameString)
        .addProperty("OffsetFromControlPoint", &GControlPointReference_t::GetOffsetFromControlPoint, &GControlPointReference_t::SetOffsetFromControlPoint)
        .addProperty("OffsetInLocalSpace", &GControlPointReference_t::GetOffsetInLocalSpace, &GControlPointReference_t::SetOffsetInLocalSpace)
        .endClass();
}