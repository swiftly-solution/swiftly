#include "../../../core/scripting/generated/classes/GCFootMotion.h"
#include "../core.h"

void SetupLuaClassGCFootMotion(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootMotion>("CFootMotion")
        .addProperty("Strides", &GCFootMotion::GetStrides, &GCFootMotion::SetStrides)
        .addProperty("Name", &GCFootMotion::GetName, &GCFootMotion::SetName)
        .addProperty("Additive", &GCFootMotion::GetAdditive, &GCFootMotion::SetAdditive)
        .endClass();
}