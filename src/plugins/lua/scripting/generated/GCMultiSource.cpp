#include "../../../core/scripting/generated/classes/GCMultiSource.h"
#include "../core.h"

void SetupLuaClassGCMultiSource(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMultiSource>("CMultiSource")
        .addProperty("RgEntities", &GCMultiSource::GetRgEntities, &GCMultiSource::SetRgEntities)
        .addProperty("RgTriggered", &GCMultiSource::GetRgTriggered, &GCMultiSource::SetRgTriggered)
        .addProperty("OnTrigger", &GCMultiSource::GetOnTrigger, &GCMultiSource::SetOnTrigger)
        .addProperty("Total", &GCMultiSource::GetTotal, &GCMultiSource::SetTotal)
        .addProperty("Globalstate", &GCMultiSource::GetGlobalstate, &GCMultiSource::SetGlobalstate)
        .endClass();
}