#include "../../scripting.h"
#include "../../../../sdk/entity/CCSPlayerPawn.h"
#include "../../../../sdk/entity/CCSPlayerController.h"
#include "../../../../sdk/entity/services.h"
#include "../../../../memory/hooks/FuncHook.h"

SH_DECL_MANUALHOOK1_void(CheckMovingGround, 0, 0, 0, double);

int checkMovingGroundID = -1;

void PluginMisc::Initialize()
{
    auto server = DetermineModuleByLibrary("server");
    void* movementservicesvtable = server.GetVirtualTableByName("CCSPlayer_MovementServices");
    SH_MANUALHOOK_RECONFIGURE(CheckMovingGround, g_Offsets->GetOffset("CCSPlayer_MovementServices_CheckMovingGround"), 0, 0);

    checkMovingGroundID = SH_ADD_MANUALDVPHOOK(CheckMovingGround, movementservicesvtable, SH_MEMBER(this, &PluginMisc::CheckMovingGround), false);
}

void PluginMisc::Destroy()
{
    SH_REMOVE_HOOK_ID(checkMovingGroundID);
}

int playerTicks[64] = {0};

void PluginMisc::CheckMovingGround(double frametime)
{
    CCSPlayer_MovementServices *pMove = META_IFACEPTR(CCSPlayer_MovementServices);
	CCSPlayerPawn *pPawn = (CCSPlayerPawn *)(((CPlayer_MovementServices*)pMove)->m_pPawn);
	CCSPlayerController *pController = pPawn->m_hOriginalController().Get();

    if (!pPawn || !pController)
		RETURN_META(MRES_IGNORED);

	int playerid = pController->GetPlayerSlot();

    if(playerTicks[playerid] == engine->GetServerGlobals()->tickcount)
        RETURN_META(MRES_SUPERCEDE);

    playerTicks[playerid] = engine->GetServerGlobals()->tickcount;

	RETURN_META(MRES_IGNORED);
}