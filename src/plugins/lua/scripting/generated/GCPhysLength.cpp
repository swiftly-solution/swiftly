#include "../../../core/scripting/generated/classes/GCPhysLength.h"
#include "../core.h"

void SetupLuaClassGCPhysLength(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysLength>("CPhysLength")
        .addProperty("Offset", &GCPhysLength::GetOffset, &GCPhysLength::SetOffset)
        .addProperty("Attach", &GCPhysLength::GetAttach, &GCPhysLength::SetAttach)
        .addProperty("AddLength", &GCPhysLength::GetAddLength, &GCPhysLength::SetAddLength)
        .addProperty("MinLength", &GCPhysLength::GetMinLength, &GCPhysLength::SetMinLength)
        .addProperty("TotalLength", &GCPhysLength::GetTotalLength, &GCPhysLength::SetTotalLength)
        .addProperty("EnableCollision", &GCPhysLength::GetEnableCollision, &GCPhysLength::SetEnableCollision)
        .endClass();
}