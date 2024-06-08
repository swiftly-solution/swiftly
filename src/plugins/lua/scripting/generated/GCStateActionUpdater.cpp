#include "../../../core/scripting/generated/classes/GCStateActionUpdater.h"
#include "../core.h"

void SetupLuaClassGCStateActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateActionUpdater>("CStateActionUpdater")
        .addProperty("Behavior", &GCStateActionUpdater::GetBehavior, &GCStateActionUpdater::SetBehavior)
        .endClass();
}