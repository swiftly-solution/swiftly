class GCPhysSurfaceProperties;

#ifndef _gccphyssurfaceproperties_h
#define _gccphyssurfaceproperties_h

#include "../../../scripting.h"


#include "GCPhysSurfacePropertiesPhysics.h"
#include "GCPhysSurfaceProperties.h"
#include "GCPhysSurfacePropertiesSoundNames.h"
#include "GCPhysSurfacePropertiesAudio.h"

class GCPhysSurfaceProperties
{
private:
    void *m_ptr;

public:
    GCPhysSurfaceProperties() {}
    GCPhysSurfaceProperties(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfaceProperties", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_name", false, value); }
    uint32_t GetNameHash() const { return GetSchemaValue<uint32_t>(m_ptr, "CPhysSurfaceProperties", "m_nameHash"); }
    void SetNameHash(uint32_t value) { SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_nameHash", false, value); }
    uint32_t GetBaseNameHash() const { return GetSchemaValue<uint32_t>(m_ptr, "CPhysSurfaceProperties", "m_baseNameHash"); }
    void SetBaseNameHash(uint32_t value) { SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_baseNameHash", false, value); }
    bool GetHidden() const { return GetSchemaValue<bool>(m_ptr, "CPhysSurfaceProperties", "m_bHidden"); }
    void SetHidden(bool value) { SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_bHidden", false, value); }
    CUtlString GetDescription() const { return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfaceProperties", "m_description"); }
    void SetDescription(CUtlString value) { SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_description", false, value); }
    GCPhysSurfacePropertiesPhysics GetPhysics() const { return GetSchemaValue<GCPhysSurfacePropertiesPhysics>(m_ptr, "CPhysSurfaceProperties", "m_physics"); }
    void SetPhysics(GCPhysSurfacePropertiesPhysics value) { SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_physics", false, value); }
    GCPhysSurfacePropertiesSoundNames GetAudioSounds() const { return GetSchemaValue<GCPhysSurfacePropertiesSoundNames>(m_ptr, "CPhysSurfaceProperties", "m_audioSounds"); }
    void SetAudioSounds(GCPhysSurfacePropertiesSoundNames value) { SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_audioSounds", false, value); }
    GCPhysSurfacePropertiesAudio GetAudioParams() const { return GetSchemaValue<GCPhysSurfacePropertiesAudio>(m_ptr, "CPhysSurfaceProperties", "m_audioParams"); }
    void SetAudioParams(GCPhysSurfacePropertiesAudio value) { SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_audioParams", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif