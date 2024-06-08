#include "../../../core/scripting/generated/classes/GCPathTrack.h"
#include "../core.h"

void SetupLuaClassGCPathTrack(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathTrack>("CPathTrack")
        .addProperty("Pnext", &GCPathTrack::GetPnext, &GCPathTrack::SetPnext)
        .addProperty("Pprevious", &GCPathTrack::GetPprevious, &GCPathTrack::SetPprevious)
        .addProperty("Paltpath", &GCPathTrack::GetPaltpath, &GCPathTrack::SetPaltpath)
        .addProperty("Radius", &GCPathTrack::GetRadius, &GCPathTrack::SetRadius)
        .addProperty("Length", &GCPathTrack::GetLength, &GCPathTrack::SetLength)
        .addProperty("AltName", &GCPathTrack::GetAltName, &GCPathTrack::SetAltName)
        .addProperty("IterVal", &GCPathTrack::GetIterVal, &GCPathTrack::SetIterVal)
        .addProperty("OrientationType", &GCPathTrack::GetOrientationType, &GCPathTrack::SetOrientationType)
        .addProperty("OnPass", &GCPathTrack::GetOnPass, &GCPathTrack::SetOnPass)
        .endClass();
}