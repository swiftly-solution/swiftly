#include "../../../core/scripting/generated/classes/GCompositeMaterialMatchFilter_t.h"
#include "../core.h"

void SetupLuaClassGCompositeMaterialMatchFilter_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterialMatchFilter_t>("CompositeMaterialMatchFilter_t")
        .addProperty("CompositeMaterialMatchFilterType", &GCompositeMaterialMatchFilter_t::GetCompositeMaterialMatchFilterType, &GCompositeMaterialMatchFilter_t::SetCompositeMaterialMatchFilterType)
        .addProperty("StrMatchFilter", &GCompositeMaterialMatchFilter_t::GetStrMatchFilter, &GCompositeMaterialMatchFilter_t::SetStrMatchFilter)
        .addProperty("StrMatchValue", &GCompositeMaterialMatchFilter_t::GetStrMatchValue, &GCompositeMaterialMatchFilter_t::SetStrMatchValue)
        .addProperty("PassWhenTrue", &GCompositeMaterialMatchFilter_t::GetPassWhenTrue, &GCompositeMaterialMatchFilter_t::SetPassWhenTrue)
        .endClass();
}