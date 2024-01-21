#ifndef _swiftly_exports_h
#define _swiftly_exports_h

#include <cstdint>
#include <string>
#include <vector>
#include <any>

#include "swiftly_memory.h"
#include "types.h"
#include "swiftly_utils.h"

typedef const char *(*Exports_Call)(const char *, const char *, const char *);
typedef void (*Exports_Register)(const char *, const char *, void *);
typedef void (*Exports_Unregister)(const char *, const char *);

std::string SerializeData(std::vector<std::any> data);
std::any DeserializeConfigData(const char *jsonData);

class Exports
{
private:
    std::string m_pluginName;

public:
    Exports(std::string pluginName) : m_pluginName(pluginName) {}

    template <typename T, typename... Args>
    T Call(std::string plugin_name, std::string export_name, Args &&...args)
    {
        void *exports_Call = FetchFunctionPtr(nullptr, "scripting_Exports_Call");
        if (exports_Call)
        {
            std::vector<std::any> toSendArgs = {args...};
            const char *jsonData = SerializeData(toSendArgs).c_str();
            const char *retData = reinterpret_cast<Exports_Call>(exports_Call)(plugin_name.c_str(), export_name.c_str(), jsonData);

            try
            {
                return std::any_cast<T>(DeserializeConfigData(retData));
            }
            catch (std::bad_any_cast &err)
            {
                return 0;
            }
        }
        else
        {
            NOT_SUPPORTED("scripting_Exports_Call");
            return 0;
        }
    }
};

extern Exports *exports;

#endif