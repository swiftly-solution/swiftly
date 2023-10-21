#pragma once
#include "CPlayer_ItemServices.h"
#include "CBaseEntity.h"
#include "schemasystem.h"

class CCSPlayer_ItemServices : public CPlayer_ItemServices
{
public:
	virtual ~CCSPlayer_ItemServices() = 0;
private:
	virtual void unk_01() = 0;
	virtual void unk_02() = 0;
	virtual void unk_03() = 0;
	virtual void unk_04() = 0;
	virtual void unk_05() = 0;
	virtual void unk_06() = 0;
	virtual void unk_07() = 0;
	virtual void unk_08() = 0;
	virtual void unk_09() = 0;
	virtual void unk_10() = 0;
	virtual void unk_11() = 0;
	virtual void unk_12() = 0;
	virtual void unk_13() = 0;
	virtual void unk_14() = 0;
	virtual SC_CBaseEntity* _GiveNamedItem(const char* pchName) = 0;
public:
	virtual bool GiveNamedItemBool(const char* pchName) = 0;
	virtual SC_CBaseEntity* GiveNamedItem(const char* pchName) = 0;

	SCHEMA_FIELD(bool, CCSPlayer_ItemServices, m_bHasDefuser);
	SCHEMA_FIELD(bool, CCSPlayer_ItemServices, m_bHasHelmet);
	SCHEMA_FIELD(bool, CCSPlayer_ItemServices, m_bHasHeavyArmor);
};