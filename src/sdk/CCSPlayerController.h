#pragma once
#include "CCSPlayerController_InGameMoneyServices.h"
#include "CBasePlayerController.h"
#include "CCSPlayerPawn.h"
#include "ehandle.h"
#include "schemasystem.h"

class CCSPlayerController : public CBasePlayerController
{
public:
	SCHEMA_FIELD(CCSPlayerController_InGameMoneyServices*, CCSPlayerController, m_pInGameMoneyServices);
	SCHEMA_FIELD(CUtlSymbolLarge, CCSPlayerController, m_szClan);
	SCHEMA_FIELD(char[32], CCSPlayerController, m_szClanName);
	SCHEMA_FIELD(CHandle<CCSPlayerPawn>, CCSPlayerController, m_hPlayerPawn);
};