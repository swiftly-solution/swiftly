#include "../../../core/scripting/generated/classes/GCAnimFoot.h"
#include "../core.h"

void SetupLuaClassGCAnimFoot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimFoot>("CAnimFoot")
        .addProperty("Name", &GCAnimFoot::GetName, &GCAnimFoot::SetName)
        .addProperty("BallOffset", &GCAnimFoot::GetBallOffset, &GCAnimFoot::SetBallOffset)
        .addProperty("HeelOffset", &GCAnimFoot::GetHeelOffset, &GCAnimFoot::SetHeelOffset)
        .addProperty("AnkleBoneIndex", &GCAnimFoot::GetAnkleBoneIndex, &GCAnimFoot::SetAnkleBoneIndex)
        .addProperty("ToeBoneIndex", &GCAnimFoot::GetToeBoneIndex, &GCAnimFoot::SetToeBoneIndex)
        .endClass();
}