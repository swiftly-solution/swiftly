#include "../../../core/scripting/generated/classes/GCAnimEncodeDifference.h"
#include "../core.h"

void SetupLuaClassGCAnimEncodeDifference(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEncodeDifference>("CAnimEncodeDifference")
        .addProperty("BoneArray", &GCAnimEncodeDifference::GetBoneArray, &GCAnimEncodeDifference::SetBoneArray)
        .addProperty("MorphArray", &GCAnimEncodeDifference::GetMorphArray, &GCAnimEncodeDifference::SetMorphArray)
        .addProperty("UserArray", &GCAnimEncodeDifference::GetUserArray, &GCAnimEncodeDifference::SetUserArray)
        .addProperty("HasRotationBitArray", &GCAnimEncodeDifference::GetHasRotationBitArray, &GCAnimEncodeDifference::SetHasRotationBitArray)
        .addProperty("HasMovementBitArray", &GCAnimEncodeDifference::GetHasMovementBitArray, &GCAnimEncodeDifference::SetHasMovementBitArray)
        .addProperty("HasMorphBitArray", &GCAnimEncodeDifference::GetHasMorphBitArray, &GCAnimEncodeDifference::SetHasMorphBitArray)
        .addProperty("HasUserBitArray", &GCAnimEncodeDifference::GetHasUserBitArray, &GCAnimEncodeDifference::SetHasUserBitArray)
        .endClass();
}