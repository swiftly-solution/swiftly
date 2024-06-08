#include "../../../core/scripting/generated/classes/GCCommentaryAuto.h"
#include "../core.h"

void SetupLuaClassGCCommentaryAuto(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCommentaryAuto>("CCommentaryAuto")
        .addProperty("OnCommentaryNewGame", &GCCommentaryAuto::GetOnCommentaryNewGame, &GCCommentaryAuto::SetOnCommentaryNewGame)
        .addProperty("OnCommentaryMidGame", &GCCommentaryAuto::GetOnCommentaryMidGame, &GCCommentaryAuto::SetOnCommentaryMidGame)
        .addProperty("OnCommentaryMultiplayerSpawn", &GCCommentaryAuto::GetOnCommentaryMultiplayerSpawn, &GCCommentaryAuto::SetOnCommentaryMultiplayerSpawn)
        .endClass();
}