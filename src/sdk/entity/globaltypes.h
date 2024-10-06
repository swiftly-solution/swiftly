#pragma once

#include <tier0/platform.h>
#include "../schema/schema.h"
#include "soundflags.h"
#include <mathlib/vector.h>

class CNetworkTransmitComponent
{
public:
    typedef CNetworkTransmitComponent ThisClass;
    static constexpr const char *ThisClassName = "CNetworkTransmitComponent";
    static constexpr bool IsStruct = false;
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
    static constexpr bool IsStruct = true;

    SCHEMA_FIELD_POINTER_OFFSET(uint64_t, m_pButtonStates, 0)
};

class CGlowProperty
{
public:
    typedef CGlowProperty ThisClass;
    static constexpr const char *ThisClassName = "CGlowProperty";
    static constexpr bool IsStruct = true;

    SCHEMA_FIELD_OFFSET(Vector, m_fGlowColor, 0)
    SCHEMA_FIELD_OFFSET(int, m_iGlowType, 0)
    SCHEMA_FIELD_OFFSET(int, m_nGlowRange, 0)
    SCHEMA_FIELD_OFFSET(Color, m_glowColorOverride, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bFlashing, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bGlowing, 0)
};

typedef uint32 SoundEventGuid_t;
struct SndOpEventGuid_t
{
    SoundEventGuid_t m_nGuid;
    uint64 m_hStackHash;
};

enum gender_t : uint8
{
    GENDER_NONE = 0x0,
    GENDER_MALE = 0x1,
    GENDER_FEMALE = 0x2,
    GENDER_NAMVET = 0x3,
    GENDER_TEENGIRL = 0x4,
    GENDER_BIKER = 0x5,
    GENDER_MANAGER = 0x6,
    GENDER_GAMBLER = 0x7,
    GENDER_PRODUCER = 0x8,
    GENDER_COACH = 0x9,
    GENDER_MECHANIC = 0xA,
    GENDER_CEDA = 0xB,
    GENDER_CRAWLER = 0xC,
    GENDER_UNDISTRACTABLE = 0xD,
    GENDER_FALLEN = 0xE,
    GENDER_RIOT_CONTROL = 0xF,
    GENDER_CLOWN = 0x10,
    GENDER_JIMMY = 0x11,
    GENDER_HOSPITAL_PATIENT = 0x12,
    GENDER_BRIDE = 0x13,
    GENDER_LAST = 0x14,
};

struct EmitSound_t
{
    EmitSound_t() : m_nChannel(0),
                    m_pSoundName(0),
                    m_flVolume(1.0f),
                    m_SoundLevel(SNDLVL_NONE),
                    m_nFlags(0),
                    m_nPitch(100),
                    m_pOrigin(0),
                    m_flSoundTime(0.0f),
                    m_pflSoundDuration(0),
                    m_bEmitCloseCaption(true),
                    m_bWarnOnMissingCloseCaption(false),
                    m_bWarnOnDirectWaveReference(false),
                    m_nSpeakerEntity(-1),
                    m_UtlVecSoundOrigin(),
                    m_nForceGuid(0),
                    m_SpeakerGender(GENDER_NONE)
    {
    }
    int m_nChannel;
    const char *m_pSoundName;
    float m_flVolume;
    soundlevel_t m_SoundLevel;
    int m_nFlags;
    int m_nPitch;
    const Vector *m_pOrigin;
    float m_flSoundTime;
    float *m_pflSoundDuration;
    bool m_bEmitCloseCaption;
    bool m_bWarnOnMissingCloseCaption;
    bool m_bWarnOnDirectWaveReference;
    CEntityIndex m_nSpeakerEntity;
    CUtlVector<Vector, CUtlMemory<Vector, int>> m_UtlVecSoundOrigin;
    SoundEventGuid_t m_nForceGuid;
    gender_t m_SpeakerGender;
};