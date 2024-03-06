#include "swiftly.h"

const char *filePath;
const char *plName;

void print(const char *str, ...)
{
    void *printfunc = FetchFunctionPtr(filePath, "scripting_Print");
    if (printfunc != nullptr)
    {
        va_list ap;
        char buffer[2048];

        va_start(ap, str);
        UTIL_FormatArgs(buffer, sizeof(buffer), str, ap);
        va_end(ap);

        reinterpret_cast<PrintFunction>(printfunc)(buffer);
    }
}

const char *FetchTranslation(const char *key)
{
    void *translationfunc = FetchFunctionPtr(nullptr, "scripting_Translations_Fetch");
    if (translationfunc)
        return reinterpret_cast<FetchTranslationFunction>(translationfunc)(key);
    else
    {
        NOT_SUPPORTED("scripting_Translations_Fetch");
        return nullptr;
    }
}

void Swiftly_Setup(const char *pluginName, const char *mainFilePath)
{
    filePath = mainFilePath;
    plName = pluginName;
}

PluginState GetPluginState(const char *plugin_name)
{
    void *statefunc = FetchFunctionPtr(filePath, "scripting_GetPluginState");
    if (statefunc)
        return reinterpret_cast<PluginStateFunc>(statefunc)(plugin_name);
    else
    {
        NOT_SUPPORTED("scripting_GetPluginState");
        return STOPPED;
    }
}