class GCPhysSurfacePropertiesSoundNames;

#ifndef _gccphyssurfacepropertiessoundnames_h
#define _gccphyssurfacepropertiessoundnames_h

#include "../../../scripting.h"




class GCPhysSurfacePropertiesSoundNames
{
private:
    void *m_ptr;

public:
    GCPhysSurfacePropertiesSoundNames() {}
    GCPhysSurfacePropertiesSoundNames(void *ptr) : m_ptr(ptr) {}

    CUtlString GetImpactSoft() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_impactSoft"); }
    void SetImpactSoft(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_impactSoft", false, value); }
    CUtlString GetImpactHard() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_impactHard"); }
    void SetImpactHard(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_impactHard", false, value); }
    CUtlString GetScrapeSmooth() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_scrapeSmooth"); }
    void SetScrapeSmooth(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_scrapeSmooth", false, value); }
    CUtlString GetScrapeRough() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_scrapeRough"); }
    void SetScrapeRough(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_scrapeRough", false, value); }
    CUtlString GetBulletImpact() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_bulletImpact"); }
    void SetBulletImpact(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_bulletImpact", false, value); }
    CUtlString GetRolling() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_rolling"); }
    void SetRolling(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_rolling", false, value); }
    CUtlString GetBreak() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_break"); }
    void SetBreak(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_break", false, value); }
    CUtlString GetStrain() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_strain"); }
    void SetStrain(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_strain", false, value); }
    CUtlString GetMeleeImpact() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_meleeImpact"); }
    void SetMeleeImpact(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_meleeImpact", false, value); }
    CUtlString GetPushOff() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_pushOff"); }
    void SetPushOff(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_pushOff", false, value); }
    CUtlString GetSkidStop() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_skidStop"); }
    void SetSkidStop(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesSoundNames", "m_skidStop", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif