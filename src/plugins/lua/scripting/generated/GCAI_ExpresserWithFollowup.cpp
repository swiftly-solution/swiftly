#include "../../../core/scripting/generated/classes/GCAI_ExpresserWithFollowup.h"
#include "../core.h"

void SetupLuaClassGCAI_ExpresserWithFollowup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAI_ExpresserWithFollowup>("CAI_ExpresserWithFollowup")
        .addProperty("PostponedFollowup", &GCAI_ExpresserWithFollowup::GetPostponedFollowup, &GCAI_ExpresserWithFollowup::SetPostponedFollowup)
        .endClass();
}