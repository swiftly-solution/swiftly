class GCRopeKeyframe;

#ifndef _gccropekeyframe_h
#define _gccropekeyframe_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCRopeKeyframe
{
private:
    void *m_ptr;

public:
    GCRopeKeyframe() {}
    GCRopeKeyframe(void *ptr) : m_ptr(ptr) {}

    uint16_t GetRopeFlags() const { return GetSchemaValue<uint16_t>(m_ptr, "CRopeKeyframe", "m_RopeFlags"); }
    void SetRopeFlags(uint16_t value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_RopeFlags", false, value); }
    CUtlSymbolLarge GetNextLinkName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CRopeKeyframe", "m_iNextLinkName"); }
    void SetNextLinkName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_iNextLinkName", false, value); }
    int16_t GetSlack() const { return GetSchemaValue<int16_t>(m_ptr, "CRopeKeyframe", "m_Slack"); }
    void SetSlack(int16_t value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_Slack", false, value); }
    float GetWidth() const { return GetSchemaValue<float>(m_ptr, "CRopeKeyframe", "m_Width"); }
    void SetWidth(float value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_Width", false, value); }
    float GetTextureScale() const { return GetSchemaValue<float>(m_ptr, "CRopeKeyframe", "m_TextureScale"); }
    void SetTextureScale(float value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_TextureScale", false, value); }
    uint8_t GetSegments() const { return GetSchemaValue<uint8_t>(m_ptr, "CRopeKeyframe", "m_nSegments"); }
    void SetSegments(uint8_t value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_nSegments", false, value); }
    bool GetConstrainBetweenEndpoints() const { return GetSchemaValue<bool>(m_ptr, "CRopeKeyframe", "m_bConstrainBetweenEndpoints"); }
    void SetConstrainBetweenEndpoints(bool value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_bConstrainBetweenEndpoints", false, value); }
    CUtlSymbolLarge GetStrRopeMaterialModel() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CRopeKeyframe", "m_strRopeMaterialModel"); }
    void SetStrRopeMaterialModel(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_strRopeMaterialModel", false, value); }
    uint8_t GetSubdiv() const { return GetSchemaValue<uint8_t>(m_ptr, "CRopeKeyframe", "m_Subdiv"); }
    void SetSubdiv(uint8_t value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_Subdiv", false, value); }
    uint8_t GetChangeCount() const { return GetSchemaValue<uint8_t>(m_ptr, "CRopeKeyframe", "m_nChangeCount"); }
    void SetChangeCount(uint8_t value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_nChangeCount", false, value); }
    int16_t GetRopeLength() const { return GetSchemaValue<int16_t>(m_ptr, "CRopeKeyframe", "m_RopeLength"); }
    void SetRopeLength(int16_t value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_RopeLength", false, value); }
    uint8_t GetLockedPoints() const { return GetSchemaValue<uint8_t>(m_ptr, "CRopeKeyframe", "m_fLockedPoints"); }
    void SetLockedPoints(uint8_t value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_fLockedPoints", false, value); }
    bool GetCreatedFromMapFile() const { return GetSchemaValue<bool>(m_ptr, "CRopeKeyframe", "m_bCreatedFromMapFile"); }
    void SetCreatedFromMapFile(bool value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_bCreatedFromMapFile", false, value); }
    float GetScrollSpeed() const { return GetSchemaValue<float>(m_ptr, "CRopeKeyframe", "m_flScrollSpeed"); }
    void SetScrollSpeed(float value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_flScrollSpeed", false, value); }
    bool GetStartPointValid() const { return GetSchemaValue<bool>(m_ptr, "CRopeKeyframe", "m_bStartPointValid"); }
    void SetStartPointValid(bool value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_bStartPointValid", false, value); }
    bool GetEndPointValid() const { return GetSchemaValue<bool>(m_ptr, "CRopeKeyframe", "m_bEndPointValid"); }
    void SetEndPointValid(bool value) { SetSchemaValue(m_ptr, "CRopeKeyframe", "m_bEndPointValid", false, value); }
    GCBaseEntity* GetStartPoint() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CRopeKeyframe", "m_hStartPoint"); }
    void SetStartPoint(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'StartPoint' is not possible.\n"); }
    GCBaseEntity* GetEndPoint() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CRopeKeyframe", "m_hEndPoint"); }
    void SetEndPoint(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'EndPoint' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif