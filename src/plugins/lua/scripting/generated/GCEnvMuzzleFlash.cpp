#include "../../../core/scripting/generated/classes/GCEnvMuzzleFlash.h"
#include "../core.h"

void SetupLuaClassGCEnvMuzzleFlash(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvMuzzleFlash>("CEnvMuzzleFlash")
        .addProperty("Scale", &GCEnvMuzzleFlash::GetScale, &GCEnvMuzzleFlash::SetScale)
        .addProperty("ParentAttachment", &GCEnvMuzzleFlash::GetParentAttachment, &GCEnvMuzzleFlash::SetParentAttachment)
        .endClass();
}