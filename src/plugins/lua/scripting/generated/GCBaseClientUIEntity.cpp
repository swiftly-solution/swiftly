#include "../../../core/scripting/generated/classes/GCBaseClientUIEntity.h"
#include "../core.h"

void SetupLuaClassGCBaseClientUIEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseClientUIEntity>("CBaseClientUIEntity")
        .addProperty("Enabled", &GCBaseClientUIEntity::GetEnabled, &GCBaseClientUIEntity::SetEnabled)
        .addProperty("DialogXMLName", &GCBaseClientUIEntity::GetDialogXMLName, &GCBaseClientUIEntity::SetDialogXMLName)
        .addProperty("PanelClassName", &GCBaseClientUIEntity::GetPanelClassName, &GCBaseClientUIEntity::SetPanelClassName)
        .addProperty("PanelID", &GCBaseClientUIEntity::GetPanelID, &GCBaseClientUIEntity::SetPanelID)
        .addProperty("CustomOutput0", &GCBaseClientUIEntity::GetCustomOutput0, &GCBaseClientUIEntity::SetCustomOutput0)
        .addProperty("CustomOutput1", &GCBaseClientUIEntity::GetCustomOutput1, &GCBaseClientUIEntity::SetCustomOutput1)
        .addProperty("CustomOutput2", &GCBaseClientUIEntity::GetCustomOutput2, &GCBaseClientUIEntity::SetCustomOutput2)
        .addProperty("CustomOutput3", &GCBaseClientUIEntity::GetCustomOutput3, &GCBaseClientUIEntity::SetCustomOutput3)
        .addProperty("CustomOutput4", &GCBaseClientUIEntity::GetCustomOutput4, &GCBaseClientUIEntity::SetCustomOutput4)
        .addProperty("CustomOutput5", &GCBaseClientUIEntity::GetCustomOutput5, &GCBaseClientUIEntity::SetCustomOutput5)
        .addProperty("CustomOutput6", &GCBaseClientUIEntity::GetCustomOutput6, &GCBaseClientUIEntity::SetCustomOutput6)
        .addProperty("CustomOutput7", &GCBaseClientUIEntity::GetCustomOutput7, &GCBaseClientUIEntity::SetCustomOutput7)
        .addProperty("CustomOutput8", &GCBaseClientUIEntity::GetCustomOutput8, &GCBaseClientUIEntity::SetCustomOutput8)
        .addProperty("CustomOutput9", &GCBaseClientUIEntity::GetCustomOutput9, &GCBaseClientUIEntity::SetCustomOutput9)
        .endClass();
}