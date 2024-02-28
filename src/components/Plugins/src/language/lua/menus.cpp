#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <string>
#include <cstdint>
#include <map>

std::string SerializeMenuData(std::vector<std::pair<std::string, std::string>> data)
{
    rapidjson::Document document(rapidjson::kArrayType);
    document.SetArray();

    for (const std::pair<std::string, std::string> entry : data)
    {
        std::string option_title = entry.first;
        std::string option_value = entry.second;

        rapidjson::Document tempdoc(rapidjson::kArrayType);
        tempdoc.PushBack(rapidjson::Value().SetString(option_title.c_str(), document.GetAllocator()), document.GetAllocator());
        tempdoc.PushBack(rapidjson::Value().SetString(option_value.c_str(), document.GetAllocator()), document.GetAllocator());

        document.PushBack(tempdoc, document.GetAllocator());
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    return std::string(buffer.GetString());
}

class LuaMenusClass
{
public:
    LuaMenusClass() {}
};

void SetupLuaMenus(luacpp::LuaState *state, Plugin *plugin)
{
    auto menusClass = state->CreateClass<LuaMenusClass>("Menus").DefConstructor<>();

    menusClass.DefMember("Register", [plugin, state](LuaMenusClass *base, const char *id, const char *title, const char *color, luacpp::LuaTable tbl) -> void
                         {
                                std::vector<std::pair<std::string, std::string>> data;

                                tbl.ForEach([&](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
                                    luacpp::LuaTable tbl(value);
                                    data.push_back({ tbl.GetString(1), tbl.GetString(2) });
                                    return true;
                                });

                                std::string serialized = SerializeMenuData(data);

                                scripting_Menus_Register(plugin->GetName().c_str(), id, title, color, serialized.c_str()); })
        .DefMember("Unregister", [plugin, state](LuaMenusClass *base, const char *id) -> void
                   { scripting_Menus_Unregister(plugin->GetName().c_str(), id); });

    state->DoString("menus = Menus()");
}