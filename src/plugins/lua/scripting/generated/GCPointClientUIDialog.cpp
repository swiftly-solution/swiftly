#include "../../../core/scripting/generated/classes/GCPointClientUIDialog.h"
#include "../core.h"

void SetupLuaClassGCPointClientUIDialog(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointClientUIDialog>("CPointClientUIDialog")
        .addProperty("Activator", &GCPointClientUIDialog::GetActivator, &GCPointClientUIDialog::SetActivator)
        .addProperty("StartEnabled", &GCPointClientUIDialog::GetStartEnabled, &GCPointClientUIDialog::SetStartEnabled)
        .endClass();
}