#include "../../../core/scripting/generated/classes/GCAnimEnum.h"
#include "../core.h"

void SetupLuaClassGCAnimEnum(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEnum>("CAnimEnum")
        .addProperty("Value", &GCAnimEnum::GetValue, &GCAnimEnum::SetValue)
        .endClass();
}