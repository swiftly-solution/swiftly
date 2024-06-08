#include "../../../core/scripting/generated/classes/GSampleCode.h"
#include "../core.h"

void SetupLuaClassGSampleCode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSampleCode>("SampleCode")
        .addProperty("SubCode", &GSampleCode::GetSubCode, &GSampleCode::SetSubCode)
        .endClass();
}