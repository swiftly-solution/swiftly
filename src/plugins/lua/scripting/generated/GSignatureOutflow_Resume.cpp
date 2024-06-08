#include "../../../core/scripting/generated/classes/GSignatureOutflow_Resume.h"
#include "../core.h"

void SetupLuaClassGSignatureOutflow_Resume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSignatureOutflow_Resume>("SignatureOutflow_Resume")

        .endClass();
}