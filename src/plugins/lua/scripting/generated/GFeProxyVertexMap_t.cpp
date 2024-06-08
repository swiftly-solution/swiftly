#include "../../../core/scripting/generated/classes/GFeProxyVertexMap_t.h"
#include "../core.h"

void SetupLuaClassGFeProxyVertexMap_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeProxyVertexMap_t>("FeProxyVertexMap_t")
        .addProperty("Name", &GFeProxyVertexMap_t::GetName, &GFeProxyVertexMap_t::SetName)
        .addProperty("Weight", &GFeProxyVertexMap_t::GetWeight, &GFeProxyVertexMap_t::SetWeight)
        .endClass();
}