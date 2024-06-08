#include "../../../core/scripting/generated/classes/GManifestTestResource_t.h"
#include "../core.h"

void SetupLuaClassGManifestTestResource_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GManifestTestResource_t>("ManifestTestResource_t")
        .addProperty("Name", &GManifestTestResource_t::GetName, &GManifestTestResource_t::SetName)
        .endClass();
}