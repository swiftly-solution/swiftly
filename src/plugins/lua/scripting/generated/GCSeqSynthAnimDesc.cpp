#include "../../../core/scripting/generated/classes/GCSeqSynthAnimDesc.h"
#include "../core.h"

void SetupLuaClassGCSeqSynthAnimDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqSynthAnimDesc>("CSeqSynthAnimDesc")
        .addProperty("Name", &GCSeqSynthAnimDesc::GetName, &GCSeqSynthAnimDesc::SetName)
        .addProperty("Flags", &GCSeqSynthAnimDesc::GetFlags, &GCSeqSynthAnimDesc::SetFlags)
        .addProperty("Transition", &GCSeqSynthAnimDesc::GetTransition, &GCSeqSynthAnimDesc::SetTransition)
        .addProperty("LocalBaseReference", &GCSeqSynthAnimDesc::GetLocalBaseReference, &GCSeqSynthAnimDesc::SetLocalBaseReference)
        .addProperty("LocalBoneMask", &GCSeqSynthAnimDesc::GetLocalBoneMask, &GCSeqSynthAnimDesc::SetLocalBoneMask)
        .addProperty("ActivityArray", &GCSeqSynthAnimDesc::GetActivityArray, &GCSeqSynthAnimDesc::SetActivityArray)
        .endClass();
}