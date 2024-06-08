#include "../../../core/scripting/generated/classes/GRnPlane_t.h"
#include "../core.h"

void SetupLuaClassGRnPlane_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnPlane_t>("RnPlane_t")
        .addProperty("Normal", &GRnPlane_t::GetNormal, &GRnPlane_t::SetNormal)
        .addProperty("Offset", &GRnPlane_t::GetOffset, &GRnPlane_t::SetOffset)
        .endClass();
}