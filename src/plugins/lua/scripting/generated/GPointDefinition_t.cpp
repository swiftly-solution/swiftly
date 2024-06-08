#include "../../../core/scripting/generated/classes/GPointDefinition_t.h"
#include "../core.h"

void SetupLuaClassGPointDefinition_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPointDefinition_t>("PointDefinition_t")
        .addProperty("ControlPoint", &GPointDefinition_t::GetControlPoint, &GPointDefinition_t::SetControlPoint)
        .addProperty("LocalCoords", &GPointDefinition_t::GetLocalCoords, &GPointDefinition_t::SetLocalCoords)
        .addProperty("Offset", &GPointDefinition_t::GetOffset, &GPointDefinition_t::SetOffset)
        .endClass();
}