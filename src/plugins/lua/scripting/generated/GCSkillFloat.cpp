#include "../../../core/scripting/generated/classes/GCSkillFloat.h"
#include "../core.h"

void SetupLuaClassGCSkillFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkillFloat>("CSkillFloat")
        .addProperty("Value", &GCSkillFloat::GetValue, &GCSkillFloat::SetValue)
        .endClass();
}