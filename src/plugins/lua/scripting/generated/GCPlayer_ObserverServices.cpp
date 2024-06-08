#include "../../../core/scripting/generated/classes/GCPlayer_ObserverServices.h"
#include "../core.h"

void SetupLuaClassGCPlayer_ObserverServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_ObserverServices>("CPlayer_ObserverServices")
        .addProperty("ObserverMode", &GCPlayer_ObserverServices::GetObserverMode, &GCPlayer_ObserverServices::SetObserverMode)
        .addProperty("ObserverTarget", &GCPlayer_ObserverServices::GetObserverTarget, &GCPlayer_ObserverServices::SetObserverTarget)
        .addProperty("ObserverLastMode", &GCPlayer_ObserverServices::GetObserverLastMode, &GCPlayer_ObserverServices::SetObserverLastMode)
        .addProperty("ForcedObserverMode", &GCPlayer_ObserverServices::GetForcedObserverMode, &GCPlayer_ObserverServices::SetForcedObserverMode)
        .endClass();
}