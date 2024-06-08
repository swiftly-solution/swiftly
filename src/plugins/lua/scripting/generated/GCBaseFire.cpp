#include "../../../core/scripting/generated/classes/GCBaseFire.h"
#include "../core.h"

void SetupLuaClassGCBaseFire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseFire>("CBaseFire")
        .addProperty("Scale", &GCBaseFire::GetScale, &GCBaseFire::SetScale)
        .addProperty("StartScale", &GCBaseFire::GetStartScale, &GCBaseFire::SetStartScale)
        .addProperty("ScaleTime", &GCBaseFire::GetScaleTime, &GCBaseFire::SetScaleTime)
        .addProperty("Flags", &GCBaseFire::GetFlags, &GCBaseFire::SetFlags)
        .endClass();
}