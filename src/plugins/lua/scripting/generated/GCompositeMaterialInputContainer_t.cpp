#include "../../../core/scripting/generated/classes/GCompositeMaterialInputContainer_t.h"
#include "../core.h"

void SetupLuaClassGCompositeMaterialInputContainer_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterialInputContainer_t>("CompositeMaterialInputContainer_t")
        .addProperty("Enabled", &GCompositeMaterialInputContainer_t::GetEnabled, &GCompositeMaterialInputContainer_t::SetEnabled)
        .addProperty("CompositeMaterialInputContainerSourceType", &GCompositeMaterialInputContainer_t::GetCompositeMaterialInputContainerSourceType, &GCompositeMaterialInputContainer_t::SetCompositeMaterialInputContainerSourceType)
        .addProperty("StrAttrName", &GCompositeMaterialInputContainer_t::GetStrAttrName, &GCompositeMaterialInputContainer_t::SetStrAttrName)
        .addProperty("StrAlias", &GCompositeMaterialInputContainer_t::GetStrAlias, &GCompositeMaterialInputContainer_t::SetStrAlias)
        .addProperty("LooseVariables", &GCompositeMaterialInputContainer_t::GetLooseVariables, &GCompositeMaterialInputContainer_t::SetLooseVariables)
        .addProperty("StrAttrNameForVar", &GCompositeMaterialInputContainer_t::GetStrAttrNameForVar, &GCompositeMaterialInputContainer_t::SetStrAttrNameForVar)
        .addProperty("ExposeExternally", &GCompositeMaterialInputContainer_t::GetExposeExternally, &GCompositeMaterialInputContainer_t::SetExposeExternally)
        .endClass();
}