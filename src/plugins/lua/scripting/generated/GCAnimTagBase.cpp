#include "../../../core/scripting/generated/classes/GCAnimTagBase.h"
#include "../core.h"

void SetupLuaClassGCAnimTagBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimTagBase>("CAnimTagBase")
        .addProperty("Comment", &GCAnimTagBase::GetComment, &GCAnimTagBase::SetComment)
        .addProperty("TagID", &GCAnimTagBase::GetTagID, &GCAnimTagBase::SetTagID)
        .addProperty("IsReferenced", &GCAnimTagBase::GetIsReferenced, &GCAnimTagBase::SetIsReferenced)
        .endClass();
}