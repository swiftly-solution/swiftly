#ifndef _swiftly_h
#define _swiftly_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "playermanager.h"

typedef void (*PrintFunction)(const char *);
typedef const char *(*FetchTranslationFunction)(const char *);

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
};

const char *FetchTranslation(const char *key)
{
    void *translationfunc = FetchFunctionPtr(nullptr, "scripting_Translations_Fetch");
    if (translationfunc)
        return reinterpret_cast<FetchTranslationFunction>(translationfunc)(key);
    else
        return nullptr;
}

void Swiftly_Setup(const char *pluginName, const char *mainFilePath)
{
    filePath = mainFilePath;
    plName = pluginName;
}

#endif