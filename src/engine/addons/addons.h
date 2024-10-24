/**************************************************
 * This feature was inspired from https://github.com/Source2ZE/MultiAddonManager/tree/9e3c17b2d6263389417782e2971d339bf6c948e6
 * Thanks to Source2ZE Team for providing a base implementation for the Addons Manager feature with their repository.
 ***************************************************/

#ifndef _addons_h
#define _addons_h

#include "../../common.h"
#include "../../entrypoint.h"
#include "../../utils/progressbar.h"
#include <networksystem/inetworkserializer.h>
#include <networksystem/inetworkmessages.h>

#include <vector>

class CServerSideClient;

void *Hook_HostStateRequest(void *a1, void **pRequest);
bool Hook_SendNetMessage(CServerSideClient* pClient, CNetMessage* pData, NetChannelBufType_t bufType);

struct DownloadInfo
{
    uint64 bytesNow;
    uint64 totalBytes;
    uint64_t elapsedTime;
    uint64_t timestamp;
    ProgressBar *progressBar;
};

class Addons
{
private:
    bool m_status = false;
    uint32_t timeout = 10;

    std::vector<std::string> addonsList;
    std::vector<std::string> mountedAddons;
    std::vector<PublishedFileId_t> downloadQueue;
    std::vector<PublishedFileId_t> importantDownloads;

    std::map<PublishedFileId_t, DownloadInfo> downloadProgresses;

public:
    Addons() {}

    std::string currentWorkshopMap;

    template <typename T>
    bool ExistsInVector(std::vector<T> v, T e)
    {
        return (std::find(v.begin(), v.end(), e) != v.end());
    }

    void LoadAddons();
    void ToggleStatus() { this->m_status = !this->m_status; }
    void SetStatus(bool status) { this->m_status = status; }
    bool GetStatus() { return this->m_status; }
    void SetTimeout(uint32_t timeout) { this->timeout = timeout; }
    uint32_t GetTimeout() { return this->timeout; }
    std::vector<std::string> GetAddons() { return this->addonsList; }

    void BuildAddonPath(std::string pszAddon, std::string &buffer);
    bool MountAddon(std::string pszAddon, bool addToTail = false);
    bool UnmountAddon(std::string pszAddon);
    void DownloadAddon(std::string pszAddon, bool important = false, bool force = false);
    bool PrintDownload();
    void RefreshAddons(bool reloadMap = false);
    void ClearAddons();

    void SetupThread();

    bool AddAddon(std::string pszAddon, bool refresh = false);
    bool RemoveAddon(std::string pszAddon, bool refresh = false);

    void OnAddonDownloaded(DownloadItemResult_t *result);
    bool OnClientConnect(uint64 xuid);

    void ReloadMap();
};

extern Addons g_addons;

#endif