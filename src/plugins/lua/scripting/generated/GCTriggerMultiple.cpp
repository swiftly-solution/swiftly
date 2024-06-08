#include "../../../core/scripting/generated/classes/GCTriggerMultiple.h"
#include "../core.h"

void SetupLuaClassGCTriggerMultiple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerMultiple>("CTriggerMultiple")
        .addProperty("OnTrigger", &GCTriggerMultiple::GetOnTrigger, &GCTriggerMultiple::SetOnTrigger)
        .endClass();
}