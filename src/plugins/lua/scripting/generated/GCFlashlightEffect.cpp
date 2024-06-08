#include "../../../core/scripting/generated/classes/GCFlashlightEffect.h"
#include "../core.h"

void SetupLuaClassGCFlashlightEffect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlashlightEffect>("CFlashlightEffect")
        .addProperty("IsOn", &GCFlashlightEffect::GetIsOn, &GCFlashlightEffect::SetIsOn)
        .addProperty("MuzzleFlashEnabled", &GCFlashlightEffect::GetMuzzleFlashEnabled, &GCFlashlightEffect::SetMuzzleFlashEnabled)
        .addProperty("MuzzleFlashBrightness", &GCFlashlightEffect::GetMuzzleFlashBrightness, &GCFlashlightEffect::SetMuzzleFlashBrightness)
        .addProperty("QuatMuzzleFlashOrientation", &GCFlashlightEffect::GetQuatMuzzleFlashOrientation, &GCFlashlightEffect::SetQuatMuzzleFlashOrientation)
        .addProperty("MuzzleFlashOrigin", &GCFlashlightEffect::GetMuzzleFlashOrigin, &GCFlashlightEffect::SetMuzzleFlashOrigin)
        .addProperty("Fov", &GCFlashlightEffect::GetFov, &GCFlashlightEffect::SetFov)
        .addProperty("FarZ", &GCFlashlightEffect::GetFarZ, &GCFlashlightEffect::SetFarZ)
        .addProperty("LinearAtten", &GCFlashlightEffect::GetLinearAtten, &GCFlashlightEffect::SetLinearAtten)
        .addProperty("CastsShadows", &GCFlashlightEffect::GetCastsShadows, &GCFlashlightEffect::SetCastsShadows)
        .addProperty("CurrentPullBackDist", &GCFlashlightEffect::GetCurrentPullBackDist, &GCFlashlightEffect::SetCurrentPullBackDist)
        .addProperty("TextureName", &GCFlashlightEffect::GetTextureName, &GCFlashlightEffect::SetTextureName)
        .endClass();
}