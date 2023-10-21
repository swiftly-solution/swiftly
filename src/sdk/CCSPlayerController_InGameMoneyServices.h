#pragma once
#include "schemasystem.h"

class CCSPlayerController_InGameMoneyServices
{
public:
	SCHEMA_FIELD(int32_t, CCSPlayerController_InGameMoneyServices, m_iAccount);
	SCHEMA_FIELD(int32_t, CCSPlayerController_InGameMoneyServices, m_iStartAccount);
};