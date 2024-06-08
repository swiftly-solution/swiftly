#include "../../../core/scripting/generated/classes/GCAnimDataChannelDesc.h"
#include "../core.h"

void SetupLuaClassGCAnimDataChannelDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimDataChannelDesc>("CAnimDataChannelDesc")
        .addProperty("ChannelClass", &GCAnimDataChannelDesc::GetChannelClass, &GCAnimDataChannelDesc::SetChannelClass)
        .addProperty("VariableName", &GCAnimDataChannelDesc::GetVariableName, &GCAnimDataChannelDesc::SetVariableName)
        .addProperty("Flags", &GCAnimDataChannelDesc::GetFlags, &GCAnimDataChannelDesc::SetFlags)
        .addProperty("Type", &GCAnimDataChannelDesc::GetType, &GCAnimDataChannelDesc::SetType)
        .addProperty("Grouping", &GCAnimDataChannelDesc::GetGrouping, &GCAnimDataChannelDesc::SetGrouping)
        .addProperty("Description", &GCAnimDataChannelDesc::GetDescription, &GCAnimDataChannelDesc::SetDescription)
        .addProperty("ElementNameArray", &GCAnimDataChannelDesc::GetElementNameArray, &GCAnimDataChannelDesc::SetElementNameArray)
        .addProperty("ElementIndexArray", &GCAnimDataChannelDesc::GetElementIndexArray, &GCAnimDataChannelDesc::SetElementIndexArray)
        .addProperty("ElementMaskArray", &GCAnimDataChannelDesc::GetElementMaskArray, &GCAnimDataChannelDesc::SetElementMaskArray)
        .endClass();
}