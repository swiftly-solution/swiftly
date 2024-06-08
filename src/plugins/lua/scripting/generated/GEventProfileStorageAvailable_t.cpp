#include "../../../core/scripting/generated/classes/GEventProfileStorageAvailable_t.h"
#include "../core.h"

void SetupLuaClassGEventProfileStorageAvailable_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventProfileStorageAvailable_t>("EventProfileStorageAvailable_t")
        .addProperty("SplitScreenSlot", &GEventProfileStorageAvailable_t::GetSplitScreenSlot, &GEventProfileStorageAvailable_t::SetSplitScreenSlot)
        .endClass();
}