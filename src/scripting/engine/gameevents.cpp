#include <memory/hooks/functions.h>

#include <plugins/manager.h>
#include <sdk/schema.h>
#include <sdk/components/CTakeDamageInfo.h>
#include <network/usermessages/usermessage.h>
#include <embedder/src/Embedder.h>

#include "ehandle.h"
#include "cs_usercmd.pb.h"

dyno::ReturnAction CCSPlayerPawnBase_PostThinkPre(dyno::CallbackType type, dyno::IHook& hook)
{
    void* _this = hook.getArgument<void*>(0);
    if (!_this) return dyno::ReturnAction::Ignored;

    CHandle<CEntityInstance> originalController = schema::GetProp<CHandle<CEntityInstance>>(_this, "CCSPlayerPawnBase", "m_hOriginalController");
    if (!originalController) return dyno::ReturnAction::Ignored;

    auto playerid = originalController.GetEntryIndex() - 1;

    if (g_pluginManager.ExecuteEvent("core", "OnPlayerPostThink", std::vector<std::any>{ playerid }, {}) == EventResult::Stop)
        return dyno::ReturnAction::Supercede;

    return dyno::ReturnAction::Ignored;
}

FunctionHook CCSPlayerPawnBase_PostThink("CCSPlayerPawnBase_PostThink", dyno::CallbackType::Pre, CCSPlayerPawnBase_PostThinkPre, "p", 'v');

bool OnClientChat(int playerid, std::string text, bool teamonly)
{
    ClassData data({ { "plugin_name", std::string("core") } }, "Event", nullptr);
    g_pluginManager.ExecuteEvent("core", "OnClientChat", { playerid, text, teamonly }, &data);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(data.GetAnyData("event_return"));
    }
    catch (std::bad_any_cast& e)
    {
        response = true;
    }

    return response;
}

void OnClientConvarQuery(int playerid, std::string convar_name, std::string convar_value)
{
    g_pluginManager.ExecuteEvent("core", "OnClientConvarQuery", { playerid, convar_name, convar_value }, {});
}

dyno::ReturnAction Hook_CGameRules_TerminateRound(dyno::CallbackType type, dyno::IHook& hook)
{
    ClassData data({ { "plugin_name", std::string("core") } }, "Event", nullptr);
    g_pluginManager.ExecuteEvent("core", "OnTerminateRound", std::vector<std::any>{ hook.getArgument<float>(1), hook.getArgument<uint32_t>(2) }, & data);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(data.GetAnyData("event_return"));
    }
    catch (std::bad_any_cast& e)
    {
        response = true;
    }

    if (!response) return dyno::ReturnAction::Supercede;

    return dyno::ReturnAction::Ignored;
}

FunctionHook CGameRules_TerminateRound("CGameRules_TerminateRound", dyno::CallbackType::Pre, Hook_CGameRules_TerminateRound, "pfuIu", 'v');

dyno::ReturnAction Hook_CEntityIdentity_AcceptInput(dyno::CallbackType type, dyno::IHook& hook)
{
    ClassData data({ { "plugin_name", std::string("core") } }, "Event", nullptr);
    ClassData* ThisPlayer = new ClassData({ { "class_name", std::string("CEntityInstance") }, { "class_ptr", (void*)(hook.getArgument<CEntityIdentity*>(0)->m_pInstance) } }, "SDKClass", nullptr);
    ClassData* Activator = new ClassData({ { "class_name", std::string("CEntityInstance") }, { "class_ptr", (void*)(hook.getArgument<CEntityInstance*>(2)) } }, "SDKClass", nullptr);
    ClassData* Caller = new ClassData({ { "class_name", std::string("CEntityInstance") }, { "class_ptr", (void*)(hook.getArgument<CEntityInstance*>(3)) } }, "SDKClass", nullptr);

    g_pluginManager.ExecuteEvent("core", "OnEntityAcceptInput", { ThisPlayer, hook.getArgument<CUtlSymbolLarge*>(1)->String(), Activator, Caller, hook.getArgument<variant_t*>(4)->ToString(), hook.getArgument<int>(5) }, &data);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(data.GetAnyData("event_return"));
    }
    catch (std::bad_any_cast& e)
    {
        response = true;
    }

    delete ThisPlayer;
    delete Activator;
    delete Caller;

    if (!response) return dyno::ReturnAction::Supercede;

    return dyno::ReturnAction::Ignored;
}

FunctionHook CEntityIdentity_AcceptInput("CEntityIdentity_AcceptInput", dyno::CallbackType::Pre, Hook_CEntityIdentity_AcceptInput, "pppppi", 'v');

dyno::ReturnAction Hook_CBaseEntity_TakeDamage(dyno::CallbackType type, dyno::IHook& hook)
{
    void* _this = hook.getArgument<void*>(0);
    CTakeDamageInfo* info = hook.getArgument<CTakeDamageInfo*>(1);

    if (((CEntityInstance*)_this)->GetClassname() != std::string("player")) return dyno::ReturnAction::Ignored;
    CHandle<CEntityInstance> playerController = schema::GetProp<CHandle<CEntityInstance>>(_this, "CBasePlayerPawn", "m_hController");
    if (!playerController) return dyno::ReturnAction::Ignored;

    int playerid = playerController.GetEntryIndex() - 1;
    int attackerid = -1;

    auto attackerPawn = info->m_hAttacker;
    if (attackerPawn) {
        CHandle<CEntityInstance> attackerController = schema::GetProp<CHandle<CEntityInstance>>(attackerPawn.Get(), "CBasePlayerPawn", "m_hController");
        if (attackerController) attackerid = attackerController.GetEntryIndex() - 1;
    }

    ClassData data({ { "plugin_name", std::string("core") } }, "Event", nullptr);
    ClassData* damageinfo = new ClassData({ { "class_name", std::string("CTakeDamageInfo") }, { "class_ptr", (void*)info } }, "SDKClass", nullptr);
    ClassData* Inflictor = new ClassData({ { "class_name", std::string("CBaseEntity") }, { "class_ptr", (void*)(info->m_hInflictor.Get()) } }, "SDKClass", nullptr);
    ClassData* Ability = new ClassData({ { "class_name", std::string("CBaseEntity") }, { "class_ptr", (void*)(info->m_hAbility.Get()) } }, "SDKClass", nullptr);

    g_pluginManager.ExecuteEvent("core", "OnPlayerDamage", { playerid, attackerid, damageinfo, Inflictor, Ability }, &data);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(data.GetAnyData("event_return"));
    }
    catch (std::bad_any_cast& e)
    {
        response = true;
    }

    delete damageinfo;
    delete Inflictor;
    delete Ability;

    if (!response) return dyno::ReturnAction::Supercede;

    return dyno::ReturnAction::Ignored;
}

FunctionHook CBaseEntity_TakeDamage("CBaseEntity_TakeDamage", dyno::CallbackType::Pre, Hook_CBaseEntity_TakeDamage, "pp", 'v');

class CUserCmd
{
public:
    [[maybe_unused]] char pad0[0x10];
    CSGOUserCmdPB cmd;
    [[maybe_unused]] char pad1[0x38];
#ifdef _WIN32
    [[maybe_unused]] char pad2[0x8];
#endif
};

dyno::ReturnAction Hook_CCSPlayerController_ProcessUsercmds(dyno::CallbackType type, dyno::IHook& hook)
{
    CEntityInstance* controller = (CEntityInstance*)(hook.getArgument<void*>(0));
    CUserCmd* cmdList = hook.getArgument<CUserCmd*>(1);
    int numcmds = hook.getArgument<int>(2);
    bool paused = hook.getArgument<bool>(3);
    float margin = hook.getArgument<float>(4);

    std::vector<UserMessage*> ums;
    std::vector<std::any> userMessages;

    for (int i = 0; i < numcmds; i++) {
        auto um = new UserMessage((google::protobuf::Message*)(&cmdList[i].cmd));
        ums.push_back(um);
        userMessages.push_back(new ClassData({ { "um_ptr", um } }, "UserMessage", nullptr));
    }

    g_pluginManager.ExecuteEvent("core", "OnClientProcessUsercmds", { controller->m_pEntity->m_EHandle.GetEntryIndex() - 1, userMessages, numcmds, paused, margin }, {});

    for (int i = 0; i < numcmds; i++) {
        delete ums[i];
        delete std::any_cast<ClassData*>(userMessages[i]);
    }

    return dyno::ReturnAction::Ignored;
}

FunctionHook CCSPlayerController_ProcessUsercmds("CCSPlayerController_ProcessUsercmds", dyno::CallbackType::Pre, Hook_CCSPlayerController_ProcessUsercmds, "ppibf", 'p');