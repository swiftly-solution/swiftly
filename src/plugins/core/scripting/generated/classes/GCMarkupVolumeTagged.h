class GCMarkupVolumeTagged;

#ifndef _gccmarkupvolumetagged_h
#define _gccmarkupvolumetagged_h

#include "../../../scripting.h"




class GCMarkupVolumeTagged
{
private:
    void *m_ptr;

public:
    GCMarkupVolumeTagged() {}
    GCMarkupVolumeTagged(void *ptr) : m_ptr(ptr) {}

    bool GetIsGroup() const { return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged", "m_bIsGroup"); }
    void SetIsGroup(bool value) { SetSchemaValue(m_ptr, "CMarkupVolumeTagged", "m_bIsGroup", false, value); }
    bool GetGroupByPrefab() const { return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged", "m_bGroupByPrefab"); }
    void SetGroupByPrefab(bool value) { SetSchemaValue(m_ptr, "CMarkupVolumeTagged", "m_bGroupByPrefab", false, value); }
    bool GetGroupByVolume() const { return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged", "m_bGroupByVolume"); }
    void SetGroupByVolume(bool value) { SetSchemaValue(m_ptr, "CMarkupVolumeTagged", "m_bGroupByVolume", false, value); }
    bool GetGroupOtherGroups() const { return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged", "m_bGroupOtherGroups"); }
    void SetGroupOtherGroups(bool value) { SetSchemaValue(m_ptr, "CMarkupVolumeTagged", "m_bGroupOtherGroups", false, value); }
    bool GetIsInGroup() const { return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged", "m_bIsInGroup"); }
    void SetIsInGroup(bool value) { SetSchemaValue(m_ptr, "CMarkupVolumeTagged", "m_bIsInGroup", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif