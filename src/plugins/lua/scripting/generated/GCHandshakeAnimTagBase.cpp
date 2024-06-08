#include "../../../core/scripting/generated/classes/GCHandshakeAnimTagBase.h"
#include "../core.h"

void SetupLuaClassGCHandshakeAnimTagBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHandshakeAnimTagBase>("CHandshakeAnimTagBase")
        .addProperty("IsDisableTag", &GCHandshakeAnimTagBase::GetIsDisableTag, &GCHandshakeAnimTagBase::SetIsDisableTag)
        .endClass();
}