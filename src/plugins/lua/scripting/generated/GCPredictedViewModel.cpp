#include "../../../core/scripting/generated/classes/GCPredictedViewModel.h"
#include "../core.h"

void SetupLuaClassGCPredictedViewModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPredictedViewModel>("CPredictedViewModel")

        .endClass();
}