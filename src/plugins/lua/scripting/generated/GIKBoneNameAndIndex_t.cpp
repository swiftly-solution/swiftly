#include "../../../core/scripting/generated/classes/GIKBoneNameAndIndex_t.h"
#include "../core.h"

void SetupLuaClassGIKBoneNameAndIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIKBoneNameAndIndex_t>("IKBoneNameAndIndex_t")
        .addProperty("Name", &GIKBoneNameAndIndex_t::GetName, &GIKBoneNameAndIndex_t::SetName)
        .endClass();
}