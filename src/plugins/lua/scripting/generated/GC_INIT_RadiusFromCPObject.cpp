#include "../../../core/scripting/generated/classes/GC_INIT_RadiusFromCPObject.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RadiusFromCPObject(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RadiusFromCPObject>("C_INIT_RadiusFromCPObject")
        .addProperty("ControlPoint", &GC_INIT_RadiusFromCPObject::GetControlPoint, &GC_INIT_RadiusFromCPObject::SetControlPoint)
        .endClass();
}