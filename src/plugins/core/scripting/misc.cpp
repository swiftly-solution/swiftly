#include "../scripting.h"
#include "../../../sdk/entity/CCSPlayerPawn.h"
#include "../../../sdk/entity/CCSPlayerController.h"
#include "../../../hooks/FuncHook.h"

void Hook_CBaseEntity_TakeDamage(CBaseEntity* _this, CTakeDamageInfo* damageInfo);
FuncHook<decltype(Hook_CBaseEntity_TakeDamage)> CBaseEntity_TakeDamage(Hook_CBaseEntity_TakeDamage, "CBaseEntity_TakeDamage");

void PluginMisc::Initialize()
{

}

void PluginMisc::Destroy()
{

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
    g_pluginManager->ExecuteEvent("core", "OnPlayerDamage", encoders::msgpack::SerializeToString({ playerid, attackerid, string_format("%p", damageInfo), string_format("%p", damageInfo->m_hInflictor.Get()) }), event);

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