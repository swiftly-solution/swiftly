#include "../../../core/scripting/generated/classes/GCBoneConstraintBase.h"
#include "../core.h"

void SetupLuaClassGCBoneConstraintBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintBase>("CBoneConstraintBase")

        .endClass();
}