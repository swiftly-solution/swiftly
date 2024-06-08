#include "../../../core/scripting/generated/classes/GCHitBoxSet.h"
#include "../core.h"

void SetupLuaClassGCHitBoxSet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHitBoxSet>("CHitBoxSet")
        .addProperty("Name", &GCHitBoxSet::GetName, &GCHitBoxSet::SetName)
        .addProperty("NameHash", &GCHitBoxSet::GetNameHash, &GCHitBoxSet::SetNameHash)
        .addProperty("HitBoxes", &GCHitBoxSet::GetHitBoxes, &GCHitBoxSet::SetHitBoxes)
        .addProperty("SourceFilename", &GCHitBoxSet::GetSourceFilename, &GCHitBoxSet::SetSourceFilename)
        .endClass();
}