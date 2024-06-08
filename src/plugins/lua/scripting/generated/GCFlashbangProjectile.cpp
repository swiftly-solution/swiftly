#include "../../../core/scripting/generated/classes/GCFlashbangProjectile.h"
#include "../core.h"

void SetupLuaClassGCFlashbangProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlashbangProjectile>("CFlashbangProjectile")
        .addProperty("TimeToDetonate", &GCFlashbangProjectile::GetTimeToDetonate, &GCFlashbangProjectile::SetTimeToDetonate)
        .addProperty("NumOpponentsHit", &GCFlashbangProjectile::GetNumOpponentsHit, &GCFlashbangProjectile::SetNumOpponentsHit)
        .addProperty("NumTeammatesHit", &GCFlashbangProjectile::GetNumTeammatesHit, &GCFlashbangProjectile::SetNumTeammatesHit)
        .endClass();
}