#include "../../../core/scripting/generated/classes/GCModelConfigElement_UserPick.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement_UserPick(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_UserPick>("CModelConfigElement_UserPick")
        .addProperty("Choices", &GCModelConfigElement_UserPick::GetChoices, &GCModelConfigElement_UserPick::SetChoices)
        .endClass();
}