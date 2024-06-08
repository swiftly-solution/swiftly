#include "../../../core/scripting/generated/classes/GCNavHullPresetVData.h"
#include "../core.h"

void SetupLuaClassGCNavHullPresetVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavHullPresetVData>("CNavHullPresetVData")
        .addProperty("NavHulls", &GCNavHullPresetVData::GetNavHulls, &GCNavHullPresetVData::SetNavHulls)
        .endClass();
}