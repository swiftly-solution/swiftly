#include "../../../core/scripting/generated/classes/GPermModelInfo_t.h"
#include "../core.h"

void SetupLuaClassGPermModelInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPermModelInfo_t>("PermModelInfo_t")
        .addProperty("Flags", &GPermModelInfo_t::GetFlags, &GPermModelInfo_t::SetFlags)
        .addProperty("HullMin", &GPermModelInfo_t::GetHullMin, &GPermModelInfo_t::SetHullMin)
        .addProperty("HullMax", &GPermModelInfo_t::GetHullMax, &GPermModelInfo_t::SetHullMax)
        .addProperty("ViewMin", &GPermModelInfo_t::GetViewMin, &GPermModelInfo_t::SetViewMin)
        .addProperty("ViewMax", &GPermModelInfo_t::GetViewMax, &GPermModelInfo_t::SetViewMax)
        .addProperty("Mass", &GPermModelInfo_t::GetMass, &GPermModelInfo_t::SetMass)
        .addProperty("EyePosition", &GPermModelInfo_t::GetEyePosition, &GPermModelInfo_t::SetEyePosition)
        .addProperty("MaxEyeDeflection", &GPermModelInfo_t::GetMaxEyeDeflection, &GPermModelInfo_t::SetMaxEyeDeflection)
        .addProperty("SurfaceProperty", &GPermModelInfo_t::GetSurfaceProperty, &GPermModelInfo_t::SetSurfaceProperty)
        .addProperty("KeyValueText", &GPermModelInfo_t::GetKeyValueText, &GPermModelInfo_t::SetKeyValueText)
        .endClass();
}