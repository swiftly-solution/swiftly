#include "../../../core/scripting/generated/classes/GCNetworkOriginCellCoordQuantizedVector.h"
#include "../core.h"

void SetupLuaClassGCNetworkOriginCellCoordQuantizedVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkOriginCellCoordQuantizedVector>("CNetworkOriginCellCoordQuantizedVector")
        .addProperty("CellX", &GCNetworkOriginCellCoordQuantizedVector::GetCellX, &GCNetworkOriginCellCoordQuantizedVector::SetCellX)
        .addProperty("CellY", &GCNetworkOriginCellCoordQuantizedVector::GetCellY, &GCNetworkOriginCellCoordQuantizedVector::SetCellY)
        .addProperty("CellZ", &GCNetworkOriginCellCoordQuantizedVector::GetCellZ, &GCNetworkOriginCellCoordQuantizedVector::SetCellZ)
        .addProperty("OutsideWorld", &GCNetworkOriginCellCoordQuantizedVector::GetOutsideWorld, &GCNetworkOriginCellCoordQuantizedVector::SetOutsideWorld)
        .addProperty("X", &GCNetworkOriginCellCoordQuantizedVector::GetX, &GCNetworkOriginCellCoordQuantizedVector::SetX)
        .addProperty("Y", &GCNetworkOriginCellCoordQuantizedVector::GetY, &GCNetworkOriginCellCoordQuantizedVector::SetY)
        .addProperty("Z", &GCNetworkOriginCellCoordQuantizedVector::GetZ, &GCNetworkOriginCellCoordQuantizedVector::SetZ)
        .endClass();
}