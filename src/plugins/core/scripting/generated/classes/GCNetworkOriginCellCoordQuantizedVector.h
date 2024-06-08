class GCNetworkOriginCellCoordQuantizedVector;

#ifndef _gccnetworkorigincellcoordquantizedvector_h
#define _gccnetworkorigincellcoordquantizedvector_h

#include "../../../scripting.h"




class GCNetworkOriginCellCoordQuantizedVector
{
private:
    void *m_ptr;

public:
    GCNetworkOriginCellCoordQuantizedVector() {}
    GCNetworkOriginCellCoordQuantizedVector(void *ptr) : m_ptr(ptr) {}

    uint16_t GetCellX() const { return GetSchemaValue<uint16_t>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellX"); }
    void SetCellX(uint16_t value) { SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellX", false, value); }
    uint16_t GetCellY() const { return GetSchemaValue<uint16_t>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellY"); }
    void SetCellY(uint16_t value) { SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellY", false, value); }
    uint16_t GetCellZ() const { return GetSchemaValue<uint16_t>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellZ"); }
    void SetCellZ(uint16_t value) { SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellZ", false, value); }
    uint16_t GetOutsideWorld() const { return GetSchemaValue<uint16_t>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_nOutsideWorld"); }
    void SetOutsideWorld(uint16_t value) { SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_nOutsideWorld", false, value); }
    float GetX() const { return GetSchemaValue<float>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecX"); }
    void SetX(float value) { SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecX", false, value); }
    float GetY() const { return GetSchemaValue<float>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecY"); }
    void SetY(float value) { SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecY", false, value); }
    float GetZ() const { return GetSchemaValue<float>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecZ"); }
    void SetZ(float value) { SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecZ", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif