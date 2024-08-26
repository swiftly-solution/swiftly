/**************************************************
 * This feature was inspired from https://github.com/Source2ZE/MultiAddonManager/tree/9e3c17b2d6263389417782e2971d339bf6c948e6
 * Thanks to Source2ZE Team for providing a base implementation for the Addons Manager feature with their repository.
 ***************************************************/

#include "addons.h"
#include "../files/Files.h"
#include "../hooks/FuncHook.h"
#include "../usermessages/usermessages.h"
#include "clients.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

#include <thread>
#include <cmath>
#include <algorithm>

#include "../../vendor/dynlib/module.h"
#include "networkbasetypes.pb.h"

#define HAS_MEMBER(DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT.HasMember(MEMBER_NAME))              \
    return AddonsPrint(string_format("The field \"%s\" doesn't exists.", MEMBER_PATH))

#define IS_ARRAY(DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsArray())            \
    return AddonsPrint(string_format("The field \"%s\" is not an array.", MEMBER_PATH))
#define IS_STRING(DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsString())            \
    return AddonsPrint(string_format("The field \"%s\" is not a string.", MEMBER_PATH))
#define IS_BOOL(DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsBool())            \
    return AddonsPrint(string_format("The field \"%s\" is not a boolean.", MEMBER_PATH))
#define IS_UINT(DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsUint())            \
    return AddonsPrint(string_format("The field \"%s\" is not an unsigned integer.", MEMBER_PATH))

SH_DECL_MANUALHOOK2(SendNetMessage, WIN_LINUX(15, 16), 0, 0, bool, CNetMessage*, NetChannelBufType_t);
int sendNetMessageHookID = -1;

FuncHook<decltype(Hook_HostStateRequest)> THostStateRequest(Hook_HostStateRequest, "HostStateRequest");

size_t FormatArgs(char* buffer, size_t maxlength, const char* fmt, va_list params)
{
    size_t len = vsnprintf(buffer, maxlength, fmt, params);

    if (len >= maxlength)
    {
        len = maxlength - 1;
        buffer[len] = '\0';
    }

    return len;
}

const char* format(const char* str, ...)
{
    va_list ap;
    char buffer[2048];

    va_start(ap, str);
    FormatArgs(buffer, sizeof(buffer), str, ap);
    va_end(ap);

    std::string return_str = buffer;

    return return_str.c_str();
}

void* Hook_HostStateRequest(void* a1, void** pRequest)
{
    if (g_addons.GetStatus() == false || g_addons.GetAddons().size() == 0)
        return THostStateRequest(a1, pRequest);

    CUtlString* psNextMap = (CUtlString*)(pRequest + 5);
    CUtlString* psAddonString = (CUtlString*)(pRequest + 11);

    std::string sExtraAddonString = implode(g_addons.GetAddons(), ",");

    static std::string sCurrentMap = psNextMap->Get();

    if (psNextMap->IsEqual_CaseSensitive(sCurrentMap.c_str()))
    {
        if (g_addons.currentWorkshopMap.empty())
            psAddonString->Clear();
        else
            psAddonString->Set(g_addons.currentWorkshopMap.c_str());
    }
    else
    {
        sCurrentMap = psNextMap->Get();
    }

    if (!psAddonString->IsEmpty())
    {
        g_addons.currentWorkshopMap = psAddonString->Get();
        psAddonString->Format("%s,%s", psAddonString->Get(), sExtraAddonString.c_str());
    }
    else
    {
        g_addons.currentWorkshopMap.clear();
        psAddonString->Set(sExtraAddonString.c_str());
    }

    return THostStateRequest(a1, pRequest);
}

void AddonsPrint(std::string str)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Addons", "%s\n", str.c_str());
}

void Addons::Initialize()
{
    DynLibUtils::CModule enginemodule("engine2");
    void* serverSideClientVTable = enginemodule.GetVirtualTableByName("CServerSideClient");
    sendNetMessageHookID = SH_ADD_MANUALDVPHOOK(SendNetMessage, serverSideClientVTable, SH_MEMBER(this, &Addons::SendNetMessage), false);
}

void Addons::Destroy()
{
    SH_REMOVE_HOOK_ID(sendNetMessageHookID);
}

bool Addons::SendNetMessage(CNetMessage* pData, NetChannelBufType_t bufType)
{
    CServerSideClient* pClient = META_IFACEPTR(CServerSideClient);
    NetMessageInfo_t* info = pData->GetNetMessage()->GetNetMessageInfo();
    if (!UserMessages_SendNetMessage(pClient->GetNetChannel(), pData, bufType))
        RETURN_META_VALUE(MRES_SUPERCEDE, false);

    if (info->m_MessageId != 7 || g_addons.GetStatus() == false || g_addons.GetAddons().size() == 0)
        RETURN_META_VALUE(MRES_IGNORED, true);

    ClientJoinInfo_t* pPendingClient = GetPendingClient(pClient->GetNetChannel());
    if (pPendingClient)
    {
        auto pMsg = pData->ToPB<CNETMsg_SignonState>();
        pMsg->set_addons(g_addons.GetAddons()[pPendingClient->addon].c_str());
        pMsg->set_signon_state(SIGNONSTATE_CHANGELEVEL);
        pPendingClient->signon_timestamp = Plat_FloatTime();
    }

    RETURN_META_VALUE(MRES_HANDLED, true);
}

void Addons::BuildAddonPath(std::string pszAddon, std::string& buffer)
{
    static CBufferStringGrowable<MAX_PATH> s_sWorkingDir;
    ExecuteOnce(g_pFullFileSystem->GetSearchPath("EXECUTABLE_PATH", GET_SEARCH_PATH_ALL, s_sWorkingDir, 1));

    std::string str = s_sWorkingDir.Get();
    std::vector<std::string> strSplit = explode(str, WIN_LINUX("\\", "/"));
    strSplit.pop_back();
    strSplit.pop_back();
    strSplit.pop_back();
    strSplit.push_back("csgo");

    buffer = string_format("%s/steamapps/workshop/content/730/%s/%s.vpk", implode(strSplit, "/").c_str(), pszAddon.c_str(), pszAddon.c_str());
}

bool Addons::MountAddon(std::string pszAddon, bool addToTail)
{
    if (pszAddon.size() == 0 || pszAddon.empty() || pszAddon.length() == 0)
        return false;

    PublishedFileId_t iAddon = V_StringToUint64(pszAddon.c_str(), 0);
    uint32 iAddonState = g_SteamAPI.SteamUGC()->GetItemState(iAddon);
    if (!(iAddonState & k_EItemStateInstalled) || (iAddonState & k_EItemStateNeedsUpdate))
    {
        AddonsPrint(string_format("Addon %s is %s, it was queued to %s.", pszAddon.c_str(), !(iAddonState & k_EItemStateInstalled) ? "not installed" : "outdated", !(iAddonState & k_EItemStateInstalled) ? "download" : "update"));
        this->DownloadAddon(pszAddon, true, true);
        return false;
    }

    std::string path;
    this->BuildAddonPath(pszAddon, path);

    if (!g_pFullFileSystem->FileExists(path.c_str()))
    {
        AddonsPrint(string_format("Addon %s was not found at %s.", pszAddon.c_str(), path.c_str()));
        return false;
    }

    if (this->ExistsInVector<std::string>(this->mountedAddons, pszAddon))
    {
        AddonsPrint(string_format("Addon %s is already mounted.", pszAddon.c_str()));
        return false;
    }

    g_pFullFileSystem->AddSearchPath(path.c_str(), "GAME", addToTail ? PATH_ADD_TO_TAIL : PATH_ADD_TO_HEAD, SEARCH_PATH_PRIORITY_VPK);
    this->mountedAddons.push_back(pszAddon);
    AddonsPrint(string_format("Addon %s mounted.", pszAddon.c_str()));

    return true;
}

bool Addons::UnmountAddon(std::string pszAddon)
{
    if (pszAddon.size() == 0 || pszAddon.empty() || pszAddon.length() == 0)
        return false;

    std::string path;
    this->BuildAddonPath(pszAddon, path);

    if (!g_pFullFileSystem->RemoveSearchPath(path.c_str(), "GAME"))
        return false;

    this->mountedAddons.erase(std::find(this->mountedAddons.begin(), this->mountedAddons.end(), pszAddon));

    AddonsPrint(string_format("Addon %s unmounted.", pszAddon.c_str()));
    return true;
}

bool Addons::PrintDownload()
{
    if (this->downloadQueue.size() == 0)
        return false;

    uint64 downloadedBytes = 0;
    uint64 totalBytes = 0;

    PublishedFileId_t iAddon = *this->downloadQueue.begin();

    if (!g_SteamAPI.SteamUGC()->GetItemDownloadInfo(iAddon, &downloadedBytes, &totalBytes) || !totalBytes)
        return false;

    if (this->downloadProgresses.find(iAddon) == this->downloadProgresses.end())
    {
        ProgressBar* bar = new ProgressBar();
        bar->SetBarPrefix(string_format("%lli: Downloading ", iAddon));
        bar->SetProgress(0);

        DownloadInfo info = {
            downloadedBytes,
            totalBytes,
            0,
            GetTime(),
            bar,
        };

        this->downloadProgresses.insert({ iAddon, info });

        AddonsPrint(bar->GetContent(format("[0s] [0.00MB/%.2fMB] 0.00%%", ((double)totalBytes / 1024.0f / 1024.0f))));
    }
    else
    {
        DownloadInfo info = this->downloadProgresses.at(iAddon);

        uint64_t thistime = (GetTime() - info.timestamp);
        info.elapsedTime += thistime;
        info.timestamp = GetTime();

        uint64 readThisTime = (downloadedBytes - info.bytesNow);
        double speedInBytes = readThisTime / (thistime / 1000.0);
        double speedInKbps = speedInBytes / 1024;
        double speedInMbps = speedInKbps / 1024;

        std::string unit;
        double speed;

        if (speedInMbps >= 1.0)
        {
            unit = "MB/s";
            speed = speedInMbps;
        }
        else if (speedInMbps >= 1.0)
        {
            unit = "KB/s";
            speed = speedInKbps;
        }
        else
        {
            unit = "B/s";
            speed = speedInBytes;
        }

        info.bytesNow = downloadedBytes;
        info.progressBar->SetProgress(static_cast<size_t>(std::floor(((double)downloadedBytes / (double)totalBytes) * 100.f)));
        this->downloadProgresses[iAddon] = info;

        AddonsPrint(info.progressBar->GetContent(format("[%.0fs] [%.2fMB/%.2fMB] %.2f%% - %.2f %s", ((double)info.elapsedTime / 1000.0f), ((double)downloadedBytes / 1024.0f / 1024.0f), ((double)totalBytes / 1024.0f / 1024.0f), (((double)downloadedBytes / (double)totalBytes) * 100.f), speed, unit.c_str())));
    }

    return true;
}

void Addons::DownloadAddon(std::string pszAddon, bool important, bool force)
{
    if (!g_SteamAPI.SteamUGC())
        return AddonsPrint(string_format("Steam API is not initialized. Download aborted for addon %s.", pszAddon.c_str()));

    PublishedFileId_t iAddon = V_StringToUint64(pszAddon.c_str(), 0);
    if (iAddon == 0)
        return AddonsPrint(string_format("Invalid addon %s.", pszAddon.c_str()));

    if (this->ExistsInVector<PublishedFileId_t>(this->downloadQueue, iAddon))
        return AddonsPrint(string_format("Addon %s is already queued for downloading.", pszAddon.c_str()));

    uint32 nItemState = g_SteamAPI.SteamUGC()->GetItemState(iAddon);

    if (!force && (nItemState & k_EItemStateInstalled) && !(nItemState & k_EItemStateNeedsUpdate))
        return AddonsPrint(string_format("Addon %s is already installed and up to date.", pszAddon.c_str()));

    if (!g_SteamAPI.SteamUGC()->DownloadItem(iAddon, false))
        return AddonsPrint(string_format("The download for %lli failed to start due to server not being logged on Steam or the ID being invalid.", iAddon));

    if (important && !this->ExistsInVector<PublishedFileId_t>(importantDownloads, iAddon))
        this->importantDownloads.push_back(iAddon);

    this->downloadQueue.push_back(iAddon);
    AddonsPrint(string_format("The download for %s started.", pszAddon.c_str()));
}

void Addons::RefreshAddons(bool reloadMap)
{
    if (!g_SteamAPI.SteamUGC())
        return;

    AddonsPrint(string_format("Refreshing addons list. (%s)", implode(this->addonsList, ",").c_str()));

    for (auto it = this->mountedAddons.rbegin(); it != this->mountedAddons.rend(); ++it)
        if (!this->UnmountAddon(*it))
            AddonsPrint(string_format("Failed to unmount %s.", (*it).c_str()));

    bool allMounted = true;

    for (size_t i = 0; i < this->addonsList.size(); i++)
        if (!this->MountAddon(this->addonsList[i]))
            allMounted = false;

    if (allMounted && reloadMap)
        this->ReloadMap();
}

void Addons::ClearAddons()
{
    this->addonsList.clear();
    for (int i = this->mountedAddons.size() - 1; i >= 0; i--)
        this->UnmountAddon(this->mountedAddons[i]);
}

void Addons::ReloadMap()
{
    std::string cmd;

    if (this->currentWorkshopMap.empty())
        cmd = string_format("changelevel %s", engine->GetServerGlobals()->mapname.ToCStr());
    else
        cmd = string_format("host_workshop_map %s", currentWorkshopMap.c_str());

    engine->ServerCommand(cmd.c_str());
}

void Addons::OnAddonDownloaded(DownloadItemResult_t* result)
{
    if (result->m_eResult == k_EResultOK)
        AddonsPrint(string_format("Addon %lli was succesfully downloaded.", result->m_nPublishedFileId));
    else
        AddonsPrint(string_format("Addon %lli download failed with status code %d.", result->m_nPublishedFileId, result->m_eResult));

    if (!this->ExistsInVector<PublishedFileId_t>(this->downloadQueue, result->m_nPublishedFileId))
        return;

    if (this->downloadProgresses.find(result->m_nPublishedFileId) != this->downloadProgresses.end())
    {
        DownloadInfo info = this->downloadProgresses.at(result->m_nPublishedFileId);

        info.elapsedTime += (GetTime() - info.timestamp);
        info.timestamp = GetTime();

        info.progressBar->SetBarPrefix(string_format("%lli: Downloaded ", result->m_nPublishedFileId));
        info.progressBar->SetProgress(100);

        AddonsPrint(info.progressBar->GetContent(format("[%.0fs] [%.2fMB] %.2f%%", ((double)info.elapsedTime / 1000.0f), ((double)info.totalBytes / 1024.0f / 1024.0f), 100.0f)));

        delete info.progressBar;

        this->downloadProgresses.erase(result->m_nPublishedFileId);
    }

    this->downloadQueue.erase(std::find(this->downloadQueue.begin(), this->downloadQueue.end(), result->m_nPublishedFileId));

    std::vector<PublishedFileId_t>::iterator it = std::find(this->importantDownloads.begin(), this->importantDownloads.end(), result->m_nPublishedFileId);
    bool found = (it != this->importantDownloads.end());
    if (found)
        this->importantDownloads.erase(it);

    if (found && this->importantDownloads.size() == 0)
    {
        AddonsPrint(string_format("All addons were succesfully downloaded, reloading map %s.", engine->GetServerGlobals()->mapname.ToCStr()));
        this->ReloadMap();
    }
}

bool Addons::AddAddon(std::string pszAddon, bool refresh)
{
    if (this->ExistsInVector<std::string>(this->addonsList, pszAddon))
    {
        AddonsPrint(string_format("Addon %s already exists in the list.", pszAddon.c_str()));
        return false;
    }

    AddonsPrint(string_format("Addon %s was added to the list.", pszAddon.c_str()));
    if (refresh)
        this->RefreshAddons();

    return true;
}

bool Addons::RemoveAddon(std::string pszAddon, bool refresh)
{
    if (!this->ExistsInVector<std::string>(this->addonsList, pszAddon))
    {
        AddonsPrint(string_format("Addon %s is not in the list.", pszAddon.c_str()));
        return false;
    }

    this->addonsList.erase(std::find(this->addonsList.begin(), this->addonsList.end(), pszAddon));

    AddonsPrint(string_format("Addon %s was removed from the list.", pszAddon.c_str()));
    if (refresh)
        this->RefreshAddons();

    return true;
}

void Addons::LoadAddons()
{
    this->ClearAddons();

    rapidjson::Document addonsFile;
    addonsFile.Parse(Files::Read("addons/swiftly/configs/addons.json").c_str());
    if (addonsFile.HasParseError())
        return AddonsPrint(string_format("A parsing error has been detected.\nError (offset %u): %s\n", (unsigned)addonsFile.GetErrorOffset(), GetParseError_En(addonsFile.GetParseError())).c_str());

    HAS_MEMBER(addonsFile, "enabled", "enabled");
    IS_BOOL(addonsFile, "enabled", "enabled");
    this->SetStatus(addonsFile["enabled"].GetBool());

    HAS_MEMBER(addonsFile, "timeout", "timeout");
    IS_UINT(addonsFile, "timeout", "timeout");
    this->SetTimeout(addonsFile["timeout"].GetUint());

    HAS_MEMBER(addonsFile, "addons", "addons");
    IS_ARRAY(addonsFile, "addons", "addons");

    for (rapidjson::size_t i = 0; i < addonsFile["addons"].Size(); i++)
    {
        IS_STRING(addonsFile["addons"], i, string_format("addons[%d]", i).c_str());
        if (std::string(addonsFile["addons"][i].GetString()).size() > 0)
            this->addonsList.push_back(addonsFile["addons"][i].GetString());
    }

    AddonsPrint(string_format("Loaded %d addon%s.", this->addonsList.size(), this->addonsList.size() == 1 ? "" : "s").c_str());
    this->RefreshAddons();
}

bool Addons::OnClientConnect(uint64 xuid)
{
    if (g_addons.GetStatus() == false || g_addons.GetAddons().size() == 0)
        return true;

    int idx;
    ClientJoinInfo_t* pendingClient = GetPendingClient(xuid, idx);

    if (!pendingClient)
    {
        AddPendingClient(xuid);
        return false;
    }
    else if ((Plat_FloatTime() - pendingClient->signon_timestamp) < static_cast<double>(this->GetTimeout()))
    {
        pendingClient->addon++;
        if ((size_t)pendingClient->addon >= this->addonsList.size())
        {
            g_ClientsPendingAddon.FastRemove(idx);
            return true;
        }
    }

    return false;
}

void Addons::SetupThread()
{
    std::thread([&]() -> void
        {
            while (true) {
                uint64_t sleeptime = this->PrintDownload() ? 100 : 1000;
                std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime));
            } })
        .detach();
}