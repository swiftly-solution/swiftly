#include "../../../core/scripting/generated/classes/GCDspPresetModifierList.h"
#include "../core.h"

void SetupLuaClassGCDspPresetModifierList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDspPresetModifierList>("CDspPresetModifierList")
        .addProperty("DspName", &GCDspPresetModifierList::GetDspName, &GCDspPresetModifierList::SetDspName)
        .addProperty("Modifiers", &GCDspPresetModifierList::GetModifiers, &GCDspPresetModifierList::SetModifiers)
        .endClass();
}