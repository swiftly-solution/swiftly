#include "../../../core/scripting/generated/classes/GModelReference_t.h"
#include "../core.h"

void SetupLuaClassGModelReference_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GModelReference_t>("ModelReference_t")
        .addProperty("RelativeProbabilityOfSpawn", &GModelReference_t::GetRelativeProbabilityOfSpawn, &GModelReference_t::SetRelativeProbabilityOfSpawn)
        .endClass();
}