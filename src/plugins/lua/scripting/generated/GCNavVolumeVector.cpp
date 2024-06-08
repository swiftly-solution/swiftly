#include "../../../core/scripting/generated/classes/GCNavVolumeVector.h"
#include "../core.h"

void SetupLuaClassGCNavVolumeVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeVector>("CNavVolumeVector")
        .addProperty("HasBeenPreFiltered", &GCNavVolumeVector::GetHasBeenPreFiltered, &GCNavVolumeVector::SetHasBeenPreFiltered)
        .endClass();
}