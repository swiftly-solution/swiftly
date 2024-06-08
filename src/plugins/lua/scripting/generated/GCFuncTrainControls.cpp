#include "../../../core/scripting/generated/classes/GCFuncTrainControls.h"
#include "../core.h"

void SetupLuaClassGCFuncTrainControls(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTrainControls>("CFuncTrainControls")

        .endClass();
}