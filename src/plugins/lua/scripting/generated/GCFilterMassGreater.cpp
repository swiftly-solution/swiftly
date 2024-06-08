#include "../../../core/scripting/generated/classes/GCFilterMassGreater.h"
#include "../core.h"

void SetupLuaClassGCFilterMassGreater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterMassGreater>("CFilterMassGreater")
        .addProperty("FilterMass", &GCFilterMassGreater::GetFilterMass, &GCFilterMassGreater::SetFilterMass)
        .endClass();
}