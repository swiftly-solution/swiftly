#include "../../../core/scripting/generated/classes/GCBlood.h"
#include "../core.h"

void SetupLuaClassGCBlood(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBlood>("CBlood")
        .addProperty("SprayAngles", &GCBlood::GetSprayAngles, &GCBlood::SetSprayAngles)
        .addProperty("SprayDir", &GCBlood::GetSprayDir, &GCBlood::SetSprayDir)
        .addProperty("Amount", &GCBlood::GetAmount, &GCBlood::SetAmount)
        .addProperty("Color", &GCBlood::GetColor, &GCBlood::SetColor)
        .endClass();
}