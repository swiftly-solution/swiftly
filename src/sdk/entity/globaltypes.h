#pragma once
#include <platform.h>
#include "../schema.h"

struct GameTime_t
{
public:
    typedef GameTime_t ThisClass;
    static constexpr const char *ThisClassName = "GameTime_t";
    static constexpr bool IsStruct = true;

    SCHEMA_FIELD_OFFSET(float, m_Value, 0)
};

class CNetworkTransmitComponent
{
public:
    typedef CNetworkTransmitComponent ThisClass;
    static constexpr const char *ThisClassName = "CNetworkTransmitComponent";
    static constexpr bool IsStruct = false;

    SCHEMA_FIELD_OFFSET(uint8_t, m_nTransmitStateOwnedCounter, 0)
};

class CNetworkVelocityVector
{
public:
    typedef CNetworkVelocityVector ThisClass;
    static constexpr const char *ThisClassName = "CNetworkVelocityVector";
    static constexpr bool IsStruct = false;

    SCHEMA_FIELD_OFFSET(float, m_vecX, 0)
    SCHEMA_FIELD_OFFSET(float, m_vecY, 0)
    SCHEMA_FIELD_OFFSET(float, m_vecZ, 0)
};

class CNetworkOriginCellCoordQuantizedVector
{
public:
    typedef CNetworkOriginCellCoordQuantizedVector ThisClass;
    static constexpr const char *ThisClassName = "CNetworkOriginCellCoordQuantizedVector";
    static constexpr bool IsStruct = false;

    SCHEMA_FIELD_OFFSET(uint16, m_cellX, 0)
    SCHEMA_FIELD_OFFSET(uint16, m_cellY, 0)
    SCHEMA_FIELD_OFFSET(uint16, m_cellZ, 0)
    SCHEMA_FIELD_OFFSET(uint16, m_nOutsideWorld, 0)

    // These are actually CNetworkedQuantizedFloat but we don't have the definition for it...
    SCHEMA_FIELD_OFFSET(float, m_vecX, 0)
    SCHEMA_FIELD_OFFSET(float, m_vecY, 0)
    SCHEMA_FIELD_OFFSET(float, m_vecZ, 0)
};

class CInButtonState
{
public:
    typedef CInButtonState ThisClass;
    static constexpr const char *ThisClassName = "CInButtonState";
    static constexpr bool IsStruct = false;

    SCHEMA_FIELD_POINTER_OFFSET(uint64_t, m_pButtonStates, 0)
};

class CGlowProperty
{
public:
    typedef CGlowProperty ThisClass;
    static constexpr const char *ThisClassName = "CGlowProperty";
    static constexpr bool IsStruct = false;

    SCHEMA_FIELD_OFFSET(Vector, m_fGlowColor, 0)
    SCHEMA_FIELD_OFFSET(int, m_iGlowType, 0)
    SCHEMA_FIELD_OFFSET(int, m_nGlowRange, 0)
    SCHEMA_FIELD_OFFSET(Color, m_glowColorOverride, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bFlashing, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bGlowing, 0)
};