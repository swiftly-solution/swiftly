#include "../../../core/scripting/generated/classes/GCAnimKeyData.h"
#include "../core.h"

void SetupLuaClassGCAnimKeyData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimKeyData>("CAnimKeyData")
        .addProperty("Name", &GCAnimKeyData::GetName, &GCAnimKeyData::SetName)
        .addProperty("BoneArray", &GCAnimKeyData::GetBoneArray, &GCAnimKeyData::SetBoneArray)
        .addProperty("UserArray", &GCAnimKeyData::GetUserArray, &GCAnimKeyData::SetUserArray)
        .addProperty("MorphArray", &GCAnimKeyData::GetMorphArray, &GCAnimKeyData::SetMorphArray)
        .addProperty("ChannelElements", &GCAnimKeyData::GetChannelElements, &GCAnimKeyData::SetChannelElements)
        .addProperty("DataChannelArray", &GCAnimKeyData::GetDataChannelArray, &GCAnimKeyData::SetDataChannelArray)
        .endClass();
}