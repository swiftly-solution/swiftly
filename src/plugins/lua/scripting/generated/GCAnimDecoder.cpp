#include "../../../core/scripting/generated/classes/GCAnimDecoder.h"
#include "../core.h"

void SetupLuaClassGCAnimDecoder(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimDecoder>("CAnimDecoder")
        .addProperty("Name", &GCAnimDecoder::GetName, &GCAnimDecoder::SetName)
        .addProperty("Version", &GCAnimDecoder::GetVersion, &GCAnimDecoder::SetVersion)
        .addProperty("Type", &GCAnimDecoder::GetType, &GCAnimDecoder::SetType)
        .endClass();
}