#include "../../../core/scripting/generated/classes/GCPhysTorque.h"
#include "../core.h"

void SetupLuaClassGCPhysTorque(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysTorque>("CPhysTorque")
        .addProperty("Axis", &GCPhysTorque::GetAxis, &GCPhysTorque::SetAxis)
        .endClass();
}