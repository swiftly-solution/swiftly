#include "../../../core/scripting/generated/classes/GClutterSceneObject_t.h"
#include "../core.h"

void SetupLuaClassGClutterSceneObject_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GClutterSceneObject_t>("ClutterSceneObject_t")
        .addProperty("Bounds", &GClutterSceneObject_t::GetBounds, &GClutterSceneObject_t::SetBounds)
        .addProperty("Flags", &GClutterSceneObject_t::GetFlags, &GClutterSceneObject_t::SetFlags)
        .addProperty("Layer", &GClutterSceneObject_t::GetLayer, &GClutterSceneObject_t::SetLayer)
        .addProperty("InstancePositions", &GClutterSceneObject_t::GetInstancePositions, &GClutterSceneObject_t::SetInstancePositions)
        .addProperty("InstanceScales", &GClutterSceneObject_t::GetInstanceScales, &GClutterSceneObject_t::SetInstanceScales)
        .addProperty("InstanceTintSrgb", &GClutterSceneObject_t::GetInstanceTintSrgb, &GClutterSceneObject_t::SetInstanceTintSrgb)
        .addProperty("Tiles", &GClutterSceneObject_t::GetTiles, &GClutterSceneObject_t::SetTiles)
        .endClass();
}