#include "../../../core/scripting/generated/classes/GSignatureOutflow_Continue.h"
#include "../core.h"

void SetupLuaClassGSignatureOutflow_Continue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSignatureOutflow_Continue>("SignatureOutflow_Continue")

        .endClass();
}