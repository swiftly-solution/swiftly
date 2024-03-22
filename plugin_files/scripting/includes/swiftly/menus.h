#ifndef _swiftly_menus_h
#define _swiftly_menus_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "types.h"

#include <string>
#include <unordered_map>
#include <vector>

std::string SerializeMenuData(std::vector<std::pair<std::string, std::string>> data);

typedef void (*Plugin_RegisterMenu)(const char *, const char *, const char *, const char *, const char *);
typedef void (*Plugin_UnregisterMenu)(const char *, const char *);

class Menus
{
private:
    std::string m_plugin_name;

public:
    Menus(std::string plugin_name) : m_plugin_name(plugin_name) {}

    void RegisterMenu(std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options)
    {
        try
        {
            std::string data = SerializeMenuData(options);
            REGISTER_METHOD_VOID(scripting_Menus_Register, this->m_plugin_name.c_str(), id.c_str(), title.c_str(), color.c_str(), data.c_str());
        }
        catch (std::logic_error &e)
        {
            print("[Swiftly] [Runtime] An error has occured while trying to register a menu.\n[Swiftly] [Runtime] Error: %s\n", e.what());
        }
    }

    void UnregisterMenu(std::string id)
    {
        REGISTER_METHOD_VOID(scripting_Menus_Unregister, this->m_plugin_name.c_str(), id.c_str());
    }
};

extern Menus *menus;

#endif