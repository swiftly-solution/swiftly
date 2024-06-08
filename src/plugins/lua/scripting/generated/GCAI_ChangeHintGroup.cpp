#include "../../../core/scripting/generated/classes/GCAI_ChangeHintGroup.h"
#include "../core.h"

void SetupLuaClassGCAI_ChangeHintGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAI_ChangeHintGroup>("CAI_ChangeHintGroup")
        .addProperty("SearchType", &GCAI_ChangeHintGroup::GetSearchType, &GCAI_ChangeHintGroup::SetSearchType)
        .addProperty("StrSearchName", &GCAI_ChangeHintGroup::GetStrSearchName, &GCAI_ChangeHintGroup::SetStrSearchName)
        .addProperty("StrNewHintGroup", &GCAI_ChangeHintGroup::GetStrNewHintGroup, &GCAI_ChangeHintGroup::SetStrNewHintGroup)
        .addProperty("Radius", &GCAI_ChangeHintGroup::GetRadius, &GCAI_ChangeHintGroup::SetRadius)
        .endClass();
}