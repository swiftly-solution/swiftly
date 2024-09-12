#include "../scripting.h"
#include "../../../sdk/entity/CCSPlayerPawn.h"
#include "../../../sdk/entity/CCSPlayerController.h"
#include "../../../sdk/entity/services.h"
#include "../../../hooks/FuncHook.h"

void Hook_CBaseEntity_TakeDamage(CBaseEntity* _this, CTakeDamageInfo* damageInfo);
FuncHook<decltype(Hook_CBaseEntity_TakeDamage)> CBaseEntity_TakeDamage(Hook_CBaseEntity_TakeDamage, "CBaseEntity_TakeDamage");

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

void Hook_CBaseEntity_TakeDamage(CBaseEntity* _this, CTakeDamageInfo* damageInfo)
{
    CCSPlayerPawn* playerPawn = (CCSPlayerPawn*)_this;
    if(!playerPawn) return CBaseEntity_TakeDamage(_this, damageInfo);
    
    CCSPlayerController* playerController = (CCSPlayerController*)playerPawn->m_hController().Get();
    if(!playerController) return CBaseEntity_TakeDamage(_this, damageInfo);

    int playerid = playerController->GetPlayerSlot();
    int attackerid = -1;

    CCSPlayerPawn* attackerPawn = (CCSPlayerPawn*)damageInfo->m_hAttacker.Get();
    if(attackerPawn) {
        CCSPlayerController* attackerController = (CCSPlayerController*)attackerPawn->m_hController().Get();
        if(attackerController) attackerid = attackerController->GetPlayerSlot();
    }

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerDamage", encoders::msgpack::SerializeToString({ playerid, attackerid, string_format("%p", damageInfo), string_format("%p", damageInfo->m_hInflictor.Get()), string_format("%p", damageInfo->m_hAbility.Get()) }), event);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(event->GetReturnValue());
    }
    catch (std::bad_any_cast& e)
    {
        response = true;
    }

    delete event;

    if(!response) return;

    CBaseEntity_TakeDamage(_this, damageInfo);
}