#include "../../../core/scripting/generated/classes/GCModelConfigElement_RandomColor.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement_RandomColor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_RandomColor>("CModelConfigElement_RandomColor")

        .endClass();
}