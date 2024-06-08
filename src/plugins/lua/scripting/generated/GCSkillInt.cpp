#include "../../../core/scripting/generated/classes/GCSkillInt.h"
#include "../core.h"

void SetupLuaClassGCSkillInt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkillInt>("CSkillInt")
        .addProperty("Value", &GCSkillInt::GetValue, &GCSkillInt::SetValue)
        .endClass();
}