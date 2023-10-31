#include "../inc/Plugin.h"
#include "../../../common.h"

typedef void (*OnPluginStartFunction)();
typedef void (*OnProgramLoadFunction)(const char *);

void Plugin::StartPlugin()
{
    void *OnProgramLoad = this->FetchFunction("Internal_OnProgramLoad");
    void *RegisterPlayer = this->FetchFunction("Internal_RegisterPlayer");
    if (OnProgramLoad == nullptr || RegisterPlayer == nullptr)
    {
        PRINTF("Plugin", "Stopped loading plugin %s because the base functions are not present.\n", "PLUGIN_NAME");
        return;
    }

    reinterpret_cast<OnProgramLoadFunction>(OnProgramLoad)(std::string(PATH).append(WIN_LINUX("/bin/win64/swiftly.dll", "/bin/linuxsteamrt64/swiftly.so")).c_str());

    void *OnPluginStart = this->FetchFunction("Internal_OnPluginStart");
    if (OnPluginStart)
    {
        reinterpret_cast<OnPluginStartFunction>(OnPluginStart)();
    }

    this->SetPluginLoaded(true);
}