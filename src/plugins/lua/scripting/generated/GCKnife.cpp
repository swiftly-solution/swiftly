#include "../../../core/scripting/generated/classes/GCKnife.h"
#include "../core.h"

void SetupLuaClassGCKnife(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCKnife>("CKnife")
        .addProperty("FirstAttack", &GCKnife::GetFirstAttack, &GCKnife::SetFirstAttack)
        .endClass();
}