#ifndef _swiftly_menus_h
#define _swiftly_menus_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "types.h"

#include <string>
#include <unordered_map>

std::string SerializeMenuData(std::unordered_map<std::string, std::string> data);

typedef void (*Plugin_RegisterMenu)(const char *, const char *, const char *, const char *, const char *);
typedef void (*Plugin_UnregisterMenu)(const char *, const char *);

class Menus
{
private:
    std::string m_plugin_name;

public:
    Menus(std::string plugin_name) : m_plugin_name(plugin_name) {}

    void RegisterMenu(std::string id, std::string title, std::string color, std::unordered_map<std::string, std::string> options)
    {
        void *menus_Register = FetchFunctionPtr(nullptr, "scripting_Menus_Register");
        if (menus_Register)
        {
            std::string data = SerializeMenuData(options);
            reinterpret_cast<Plugin_RegisterMenu>(menus_Register)(this->m_plugin_name.c_str(), id.c_str(), title.c_str(), color.c_str(), data.c_str());
        }
        else
            NOT_SUPPORTED("scripting_Menus_Register");
    }

    void UnregisterMenu(std::string id)
    {
        void *menus_Unregister = FetchFunctionPtr(nullptr, "scripting_Menus_Unregister");
        if (menus_Unregister)
        {
            reinterpret_cast<Plugin_UnregisterMenu>(menus_Unregister)(this->m_plugin_name.c_str(), id.c_str());
        }
        else
            NOT_SUPPORTED("scripting_Menus_Unregister");
    }
};

extern Menus *menus;

#endif