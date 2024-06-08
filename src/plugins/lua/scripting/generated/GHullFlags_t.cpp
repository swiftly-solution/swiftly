#include "../../../core/scripting/generated/classes/GHullFlags_t.h"
#include "../core.h"

void SetupLuaClassGHullFlags_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GHullFlags_t>("HullFlags_t")
        .addProperty("Hull_Human", &GHullFlags_t::GetHull_Human, &GHullFlags_t::SetHull_Human)
        .addProperty("Hull_SmallCentered", &GHullFlags_t::GetHull_SmallCentered, &GHullFlags_t::SetHull_SmallCentered)
        .addProperty("Hull_WideHuman", &GHullFlags_t::GetHull_WideHuman, &GHullFlags_t::SetHull_WideHuman)
        .addProperty("Hull_Tiny", &GHullFlags_t::GetHull_Tiny, &GHullFlags_t::SetHull_Tiny)
        .addProperty("Hull_Medium", &GHullFlags_t::GetHull_Medium, &GHullFlags_t::SetHull_Medium)
        .addProperty("Hull_TinyCentered", &GHullFlags_t::GetHull_TinyCentered, &GHullFlags_t::SetHull_TinyCentered)
        .addProperty("Hull_Large", &GHullFlags_t::GetHull_Large, &GHullFlags_t::SetHull_Large)
        .addProperty("Hull_LargeCentered", &GHullFlags_t::GetHull_LargeCentered, &GHullFlags_t::SetHull_LargeCentered)
        .addProperty("Hull_MediumTall", &GHullFlags_t::GetHull_MediumTall, &GHullFlags_t::SetHull_MediumTall)
        .addProperty("Hull_Small", &GHullFlags_t::GetHull_Small, &GHullFlags_t::SetHull_Small)
        .endClass();
}