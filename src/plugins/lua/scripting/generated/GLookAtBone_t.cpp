#include "../../../core/scripting/generated/classes/GLookAtBone_t.h"
#include "../core.h"

void SetupLuaClassGLookAtBone_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GLookAtBone_t>("LookAtBone_t")
        .addProperty("Index", &GLookAtBone_t::GetIndex, &GLookAtBone_t::SetIndex)
        .addProperty("Weight", &GLookAtBone_t::GetWeight, &GLookAtBone_t::SetWeight)
        .endClass();
}