#include "../../../core/scripting/generated/classes/GCEntityDissolve.h"
#include "../core.h"

void SetupLuaClassGCEntityDissolve(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityDissolve>("CEntityDissolve")
        .addProperty("FadeInStart", &GCEntityDissolve::GetFadeInStart, &GCEntityDissolve::SetFadeInStart)
        .addProperty("FadeInLength", &GCEntityDissolve::GetFadeInLength, &GCEntityDissolve::SetFadeInLength)
        .addProperty("FadeOutModelStart", &GCEntityDissolve::GetFadeOutModelStart, &GCEntityDissolve::SetFadeOutModelStart)
        .addProperty("FadeOutModelLength", &GCEntityDissolve::GetFadeOutModelLength, &GCEntityDissolve::SetFadeOutModelLength)
        .addProperty("FadeOutStart", &GCEntityDissolve::GetFadeOutStart, &GCEntityDissolve::SetFadeOutStart)
        .addProperty("FadeOutLength", &GCEntityDissolve::GetFadeOutLength, &GCEntityDissolve::SetFadeOutLength)
        .addProperty("DissolveType", &GCEntityDissolve::GetDissolveType, &GCEntityDissolve::SetDissolveType)
        .addProperty("DissolverOrigin", &GCEntityDissolve::GetDissolverOrigin, &GCEntityDissolve::SetDissolverOrigin)
        .addProperty("Magnitude", &GCEntityDissolve::GetMagnitude, &GCEntityDissolve::SetMagnitude)
        .endClass();
}