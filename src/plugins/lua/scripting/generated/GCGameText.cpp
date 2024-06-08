#include "../../../core/scripting/generated/classes/GCGameText.h"
#include "../core.h"

void SetupLuaClassGCGameText(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameText>("CGameText")
        .addProperty("Message", &GCGameText::GetMessage, &GCGameText::SetMessage)
        .addProperty("TextParms", &GCGameText::GetTextParms, &GCGameText::SetTextParms)
        .endClass();
}