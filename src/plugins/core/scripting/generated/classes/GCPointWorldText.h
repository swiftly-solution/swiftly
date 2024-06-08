class GCPointWorldText;

#ifndef _gccpointworldtext_h
#define _gccpointworldtext_h

#include "../../../scripting.h"

#include "../types/GPointWorldTextJustifyHorizontal_t.h"
#include "../types/GPointWorldTextJustifyVertical_t.h"
#include "../types/GPointWorldTextReorientMode_t.h"


class GCPointWorldText
{
private:
    void *m_ptr;

public:
    GCPointWorldText() {}
    GCPointWorldText(void *ptr) : m_ptr(ptr) {}

    std::string GetMessageText() const { return GetSchemaValue<char*>(m_ptr, "CPointWorldText", "m_messageText"); }
    void SetMessageText(std::string value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_messageText", false, value); }
    std::string GetFontName() const { return GetSchemaValue<char*>(m_ptr, "CPointWorldText", "m_FontName"); }
    void SetFontName(std::string value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_FontName", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CPointWorldText", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_bEnabled", false, value); }
    bool GetFullbright() const { return GetSchemaValue<bool>(m_ptr, "CPointWorldText", "m_bFullbright"); }
    void SetFullbright(bool value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_bFullbright", false, value); }
    float GetWorldUnitsPerPx() const { return GetSchemaValue<float>(m_ptr, "CPointWorldText", "m_flWorldUnitsPerPx"); }
    void SetWorldUnitsPerPx(float value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_flWorldUnitsPerPx", false, value); }
    float GetFontSize() const { return GetSchemaValue<float>(m_ptr, "CPointWorldText", "m_flFontSize"); }
    void SetFontSize(float value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_flFontSize", false, value); }
    float GetDepthOffset() const { return GetSchemaValue<float>(m_ptr, "CPointWorldText", "m_flDepthOffset"); }
    void SetDepthOffset(float value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_flDepthOffset", false, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CPointWorldText", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_Color", false, value); }
    PointWorldTextJustifyHorizontal_t GetJustifyHorizontal() const { return GetSchemaValue<PointWorldTextJustifyHorizontal_t>(m_ptr, "CPointWorldText", "m_nJustifyHorizontal"); }
    void SetJustifyHorizontal(PointWorldTextJustifyHorizontal_t value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_nJustifyHorizontal", false, value); }
    PointWorldTextJustifyVertical_t GetJustifyVertical() const { return GetSchemaValue<PointWorldTextJustifyVertical_t>(m_ptr, "CPointWorldText", "m_nJustifyVertical"); }
    void SetJustifyVertical(PointWorldTextJustifyVertical_t value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_nJustifyVertical", false, value); }
    PointWorldTextReorientMode_t GetReorientMode() const { return GetSchemaValue<PointWorldTextReorientMode_t>(m_ptr, "CPointWorldText", "m_nReorientMode"); }
    void SetReorientMode(PointWorldTextReorientMode_t value) { SetSchemaValue(m_ptr, "CPointWorldText", "m_nReorientMode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif