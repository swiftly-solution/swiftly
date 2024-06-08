#include "../../../core/scripting/generated/classes/GCEnvLaser.h"
#include "../core.h"

void SetupLuaClassGCEnvLaser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvLaser>("CEnvLaser")
        .addProperty("LaserTarget", &GCEnvLaser::GetLaserTarget, &GCEnvLaser::SetLaserTarget)
        .addProperty("Sprite", &GCEnvLaser::GetSprite, &GCEnvLaser::SetSprite)
        .addProperty("SpriteName", &GCEnvLaser::GetSpriteName, &GCEnvLaser::SetSpriteName)
        .addProperty("FirePosition", &GCEnvLaser::GetFirePosition, &GCEnvLaser::SetFirePosition)
        .addProperty("StartFrame", &GCEnvLaser::GetStartFrame, &GCEnvLaser::SetStartFrame)
        .endClass();
}