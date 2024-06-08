#include "../../../core/scripting/generated/classes/GCAnimMovement.h"
#include "../core.h"

void SetupLuaClassGCAnimMovement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimMovement>("CAnimMovement")
        .addProperty("Endframe", &GCAnimMovement::GetEndframe, &GCAnimMovement::SetEndframe)
        .addProperty("Motionflags", &GCAnimMovement::GetMotionflags, &GCAnimMovement::SetMotionflags)
        .addProperty("0", &GCAnimMovement::Get0, &GCAnimMovement::Set0)
        .addProperty("1", &GCAnimMovement::Get1, &GCAnimMovement::Set1)
        .addProperty("Angle", &GCAnimMovement::GetAngle, &GCAnimMovement::SetAngle)
        .addProperty("Vector", &GCAnimMovement::GetVector, &GCAnimMovement::SetVector)
        .addProperty("Position", &GCAnimMovement::GetPosition, &GCAnimMovement::SetPosition)
        .endClass();
}