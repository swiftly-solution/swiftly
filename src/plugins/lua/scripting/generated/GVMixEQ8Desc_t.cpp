#include "../../../core/scripting/generated/classes/GVMixEQ8Desc_t.h"
#include "../core.h"

void SetupLuaClassGVMixEQ8Desc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixEQ8Desc_t>("VMixEQ8Desc_t")
        .addProperty("Stages", &GVMixEQ8Desc_t::GetStages, &GVMixEQ8Desc_t::SetStages)
        .endClass();
}