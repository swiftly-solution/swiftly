class GJiggleBoneSettingsList_t;

#ifndef _gcjigglebonesettingslist_t_h
#define _gcjigglebonesettingslist_t_h

#include "../../../scripting.h"


#include "GJiggleBoneSettings_t.h"

class GJiggleBoneSettingsList_t
{
private:
    void *m_ptr;

public:
    GJiggleBoneSettingsList_t() {}
    GJiggleBoneSettingsList_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GJiggleBoneSettings_t> GetBoneSettings() const { CUtlVector<GJiggleBoneSettings_t>* vec = GetSchemaValue<CUtlVector<GJiggleBoneSettings_t>*>(m_ptr, "JiggleBoneSettingsList_t", "m_boneSettings"); std::vector<GJiggleBoneSettings_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneSettings(std::vector<GJiggleBoneSettings_t> value) { SetSchemaValueCUtlVector<GJiggleBoneSettings_t>(m_ptr, "JiggleBoneSettingsList_t", "m_boneSettings", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif