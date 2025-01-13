#pragma once
#include <platform.h>
#include "globaltypes.h"
#include "CBaseEntity.h"

enum PointWorldTextJustifyHorizontal_t : uint32_t
{
    POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_LEFT = 0,
    POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_CENTER = 1,
    POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_RIGHT = 2,
};

enum PointWorldTextJustifyVertical_t : uint32_t
{
    POINT_WORLD_TEXT_JUSTIFY_VERTICAL_BOTTOM = 0,
    POINT_WORLD_TEXT_JUSTIFY_VERTICAL_CENTER = 1,
    POINT_WORLD_TEXT_JUSTIFY_VERTICAL_TOP = 2,
};

enum PointWorldTextReorientMode_t : uint32_t
{
    POINT_WORLD_TEXT_REORIENT_NONE = 0,
    POINT_WORLD_TEXT_REORIENT_AROUND_UP = 1,
};

class CPointWorldText : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CPointWorldText)

    SCHEMA_FIELD_POINTER_OFFSET(char, m_messageText, 0);
    SCHEMA_FIELD_POINTER_OFFSET(char, m_FontName, 0);
    SCHEMA_FIELD_POINTER_OFFSET(char, m_BackgroundMaterialName, 0);

    SCHEMA_FIELD_OFFSET(bool, m_bEnabled, 0);
    SCHEMA_FIELD_OFFSET(bool, m_bFullbright, 0);
    SCHEMA_FIELD_OFFSET(float, m_flWorldUnitsPerPx, 0);
    SCHEMA_FIELD_OFFSET(float, m_flFontSize, 0);
    SCHEMA_FIELD_OFFSET(float, m_flDepthOffset, 0);
    SCHEMA_FIELD_OFFSET(bool, m_bDrawBackground, 0);
    SCHEMA_FIELD_OFFSET(float, m_flBackgroundBorderWidth, 0);
    SCHEMA_FIELD_OFFSET(float, m_flBackgroundBorderHeight, 0);
    SCHEMA_FIELD_OFFSET(float, m_flBackgroundWorldToUV, 0);
    SCHEMA_FIELD_OFFSET(Color, m_Color, 0);
    SCHEMA_FIELD_OFFSET(PointWorldTextJustifyHorizontal_t, m_nJustifyHorizontal, 0);
    SCHEMA_FIELD_OFFSET(PointWorldTextJustifyVertical_t, m_nJustifyVertical, 0);
    SCHEMA_FIELD_OFFSET(PointWorldTextReorientMode_t, m_nReorientMode, 0);

    void SetText(const char* msg) {
        AcceptInput("SetMessage", nullptr, nullptr, msg);
    }

    void Enable() {
        AcceptInput("Enable");
    }

    void Disable() {
        AcceptInput("Disable");
    }
};
