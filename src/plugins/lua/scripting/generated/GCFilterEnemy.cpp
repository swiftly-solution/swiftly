#include "../../../core/scripting/generated/classes/GCFilterEnemy.h"
#include "../core.h"

void SetupLuaClassGCFilterEnemy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterEnemy>("CFilterEnemy")
        .addProperty("EnemyName", &GCFilterEnemy::GetEnemyName, &GCFilterEnemy::SetEnemyName)
        .addProperty("Radius", &GCFilterEnemy::GetRadius, &GCFilterEnemy::SetRadius)
        .addProperty("OuterRadius", &GCFilterEnemy::GetOuterRadius, &GCFilterEnemy::SetOuterRadius)
        .addProperty("MaxSquadmatesPerEnemy", &GCFilterEnemy::GetMaxSquadmatesPerEnemy, &GCFilterEnemy::SetMaxSquadmatesPerEnemy)
        .addProperty("PlayerName", &GCFilterEnemy::GetPlayerName, &GCFilterEnemy::SetPlayerName)
        .endClass();
}