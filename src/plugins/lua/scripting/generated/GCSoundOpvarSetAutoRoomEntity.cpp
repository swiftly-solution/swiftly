#include "../../../core/scripting/generated/classes/GCSoundOpvarSetAutoRoomEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundOpvarSetAutoRoomEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetAutoRoomEntity>("CSoundOpvarSetAutoRoomEntity")
        .addProperty("TraceResults", &GCSoundOpvarSetAutoRoomEntity::GetTraceResults, &GCSoundOpvarSetAutoRoomEntity::SetTraceResults)
        .addProperty("Size", &GCSoundOpvarSetAutoRoomEntity::GetSize, &GCSoundOpvarSetAutoRoomEntity::SetSize)
        .addProperty("HeightTolerance", &GCSoundOpvarSetAutoRoomEntity::GetHeightTolerance, &GCSoundOpvarSetAutoRoomEntity::SetHeightTolerance)
        .addProperty("SizeSqr", &GCSoundOpvarSetAutoRoomEntity::GetSizeSqr, &GCSoundOpvarSetAutoRoomEntity::SetSizeSqr)
        .endClass();
}