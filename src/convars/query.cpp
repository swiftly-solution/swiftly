#include "convars.h"
#include "../sdk/entity/CRecipientFilters.h"
#include "../../vendor/dynlib/module.h"
#include "../sdk/entity/serversideclient.h"
#include "../player/PlayerManager.h"

std::map<std::string, std::string> languages = {
    { "arabic", "ar" },
    { "bulgarian", "bg" },
    { "schinese", "zh-CN" },
    { "tchinese", "zh-TW" },
    { "czech", "cs" },
    { "danish", "da" },
    { "dutch", "nl" },
    { "english", "en" },
    { "finnish", "fi" },
    { "french", "fr" },
    { "german", "de" },
    { "greek", "el" },
    { "hungarian", "hu" },
    { "indonesian", "id" },
    { "italian", "it" },
    { "japanese", "ja" },
    { "koreana", "ko" },
    { "norwegian", "no" },
    { "polish", "pl" },
    { "portuguese", "pt" },
    { "brazilian", "pt-BR" },
    { "romanian", "ro" },
    { "russian", "ru" },
    { "spanish", "es" },
    { "latam", "es-419" },
    { "swedish", "sv" },
    { "thai", "th" },
    { "turkish", "tr" },
    { "ukrainian", "uk" },
    { "vietnamese", "vn" },
};

SH_DECL_MANUALHOOK1(OnConVarQuery, 0, 0, 0, bool, const CNetMessagePB<CCLCMsg_RespondCvarValue>&);

int OnConVarQueryID = -1;

void ConvarQuery::Initialize()
{
    SH_MANUALHOOK_RECONFIGURE(OnConVarQuery, g_Offsets->GetOffset("CServerSideClient_OnConVarQuery"), 0, 0);

    DynLibUtils::CModule eng = DetermineModuleByLibrary("engine2");
    void* serverSideClientVTable = eng.GetVirtualTableByName("CServerSideClient");
    OnConVarQueryID = SH_ADD_MANUALDVPHOOK(OnConVarQuery, serverSideClientVTable, SH_MEMBER(this, &ConvarQuery::OnConVarQuery), true);
}

void ConvarQuery::Destroy()
{
    SH_REMOVE_HOOK_ID(OnConVarQueryID);
}

bool ConvarQuery::OnConVarQuery(const CNetMessagePB<CCLCMsg_RespondCvarValue>& msg)
{
    auto client = META_IFACEPTR(CServerSideClient);

    if (msg.name() == "cl_language") {
        if (languages.find(msg.value()) != languages.end()) {
            auto player = g_playerManager->GetPlayer(client->GetPlayerSlot());
            if (player != nullptr) player->language = languages.at(msg.value());
        }
    }

    RETURN_META_VALUE(MRES_IGNORED, true);
}


void ConvarQuery::QueryCvarClient(CPlayerSlot slot, std::string cvarName)
{
    auto pMsg = g_pNetworkMessages->FindNetworkMessagePartial("GetCvarValue");

    auto msg = pMsg->AllocateMessage()->ToPB<CSVCMsg_GetCvarValue>();
    msg->set_cvar_name(cvarName.c_str());

    CSingleRecipientFilter filter(slot.Get());
    g_pGameEventSystem->PostEventAbstract(-1, false, &filter, pMsg, msg, 0);

    delete msg;
}