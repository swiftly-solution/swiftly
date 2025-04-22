#include <memory/gamedata/gamedata.h>
#include <public/mathlib/vector.h>
#include "ehandle.h"

class CTakeDamageInfo;
typedef void (*CTakeDamageInfo_Constructor)(void*, void*, void*, void*, Vector*, Vector*, float, int, int, void*);

enum DDamageTypes_t : uint32_t
{
	DMG_GENERIC = 0x0,
	DMG_CRUSH = 0x1,
	DMG_BULLET = 0x2,
	DMG_SLASH = 0x4,
	DMG_BURN = 0x8,
	DMG_VEHICLE = 0x10,
	DMG_FALL = 0x20,
	DMG_BLAST = 0x40,
	DMG_CLUB = 0x80,
	DMG_SHOCK = 0x100,
	DMG_SONIC = 0x200,
	DMG_ENERGYBEAM = 0x400,
	DMG_DROWN = 0x4000,
	DMG_POISON = 0x8000,
	DMG_RADIATION = 0x10000,
	DMG_DROWNRECOVER = 0x20000,
	DMG_ACID = 0x40000,
	DMG_PHYSGUN = 0x100000,
	DMG_DISSOLVE = 0x200000,
	DMG_BLAST_SURFACE = 0x400000,
	DMG_BUCKSHOT = 0x1000000,
	DMG_LASTGENERICFLAG = 0x1000000,
	DMG_HEADSHOT = 0x2000000,
	DMG_DANGERZONE = 0x4000000,
};

enum TTakeDamageFlags_t : uint32_t
{
	DFLAG_NONE = 0x0,
	DFLAG_SUPPRESS_HEALTH_CHANGES = 0x1,
	DFLAG_SUPPRESS_PHYSICS_FORCE = 0x2,
	DFLAG_SUPPRESS_EFFECTS = 0x4,
	DFLAG_PREVENT_DEATH = 0x8,
	DFLAG_FORCE_DEATH = 0x10,
	DFLAG_ALWAYS_GIB = 0x20,
	DFLAG_NEVER_GIB = 0x40,
	DFLAG_REMOVE_NO_RAGDOLL = 0x80,
	DFLAG_SUPPRESS_DAMAGE_MODIFICATION = 0x100,
	DFLAG_ALWAYS_FIRE_DAMAGE_EVENTS = 0x200,
	DFLAG_RADIUS_DMG = 0x400,
	DMG_LASTDFLAG = 0x400,
	DFLAG_IGNORE_ARMOR = 0x800,
};

struct AttackerInfo_t
{
	bool m_bNeedInit;
	bool m_bIsPawn;
	bool m_bIsWorld;
	CHandle<CEntityInstance> m_hAttackerPawn;
	uint16_t m_nAttackerPlayerSlot;
	int m_iTeamChecked;
	int m_nTeam;
};

struct CTakeDamageInfoContainer
{
	CTakeDamageInfo* pInfo;
};

class CTakeDamageInfo
{
private:
	[[maybe_unused]] unsigned char __pad0000[0x8];

public:
	CTakeDamageInfo(void* pInflictor, void* pAttacker, void* pAbility, float flDamage, int bitsDamageType)
	{
		Vector vec3_origin(0.0, 0.0, 0.0);
		g_GameData.FetchSignature<CTakeDamageInfo_Constructor>("CTakeDamageInfo_Constructor")(this, pInflictor, pAttacker, pAbility, &vec3_origin, &vec3_origin, flDamage, bitsDamageType, 0, nullptr);
	}

	Vector m_vecDamageForce;
	Vector m_vecDamagePosition;
	Vector m_vecReportedPosition;
	Vector m_vecDamageDirection;
	CHandle<CEntityInstance> m_hInflictor;
	CHandle<CEntityInstance> m_hAttacker;
	CHandle<CEntityInstance> m_hAbility;
	float m_flDamage;
	float m_flTotalledDamage;
	float m_flTotalledDamageAbsorbed;
	DDamageTypes_t m_bitsDamageType;
	int32_t m_iDamageCustom;
	uint8_t m_iAmmoType;

private:
	[[maybe_unused]] uint8_t __pad0059[0xf];

public:
	float m_flOriginalDamage;
	bool m_bShouldBleed;
	bool m_bShouldSpark;

private:
	[[maybe_unused]] uint8_t __pad006e[0x2];

public:
	float m_flDamageAbsorbed;

private:
	[[maybe_unused]] uint8_t __pad0074[0x8];

public:
	TTakeDamageFlags_t m_nDamageFlags;

private:
	[[maybe_unused]] uint8_t __pad0084[0x4];

public:
	int32_t m_nNumObjectsPenetrated;
	float m_flFriendlyFireDamageReductionRatio;
	uint64_t m_hScriptInstance;
	AttackerInfo_t m_AttackerInfo;
	bool m_bInTakeDamageFlow;

private:
	[[maybe_unused]] uint8_t __pad00ad[0x4];
};