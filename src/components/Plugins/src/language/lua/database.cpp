#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>
#include <thread>

class LuaDatabaseClass
{
private:
    bool m_connected = false;
    std::string connectionName;

public:
    LuaDatabaseClass(const char *connection_name)
    {
        this->connectionName = connection_name;
        std::thread th([this, connection_name]()
                       { this->m_connected = scripting_Database_Connect(connection_name); });
        th.detach();
    }

    ~LuaDatabaseClass() {}

    bool IsConnected()
    {
        return this->m_connected;
    }

    std::string GetConnectionName()
    {
        return this->connectionName;
    }
};

void SetupLuaDatabase(luacpp::LuaState *state, Plugin *plugin)
{
    auto databaseClass = state->CreateClass<LuaDatabaseClass>("Database").DefConstructor<const char *>();

    databaseClass.DefMember("EscapeString", [](LuaDatabaseClass *base, const char *value) -> const char *
                            { return scripting_Database_EscapeString(base->GetConnectionName().c_str(), value); })
        .DefMember("Query", [state](LuaDatabaseClass *base, const char *query) -> luacpp::LuaTable
                   {
                    luacpp::LuaTable tbl = state->CreateTable();

                    std::vector<std::map<const char *, std::any>> result = scripting_Database_QueryRaw(base->GetConnectionName().c_str(), query);

                    for(uint32_t i = 0; i < result.size(); i++) {
                        luacpp::LuaTable rowTbl = state->CreateTable();

                        for(std::map<const char *, std::any>::iterator it = result[i].begin(); it != result[i].end(); ++it)
                        {
                            const char* key = it->first;
                            std::any value = it->second;

                            if (value.type() == typeid(const char *))
                                rowTbl.SetString(key, std::any_cast<const char *>(value));
                            else if (value.type() == typeid(std::string))
                                rowTbl.SetString(key, std::any_cast<std::string>(value).c_str());
                            else if (value.type() == typeid(uint64))
                                rowTbl.SetInteger(key, std::any_cast<uint64>(value));
                            else if (value.type() == typeid(uint32))
                                rowTbl.SetInteger(key, std::any_cast<uint32>(value));
                            else if (value.type() == typeid(uint16))
                                rowTbl.SetInteger(key, std::any_cast<uint16>(value));
                            else if (value.type() == typeid(uint8))
                                rowTbl.SetInteger(key, std::any_cast<uint8>(value));
                            else if (value.type() == typeid(int64))
                                rowTbl.SetInteger(key, std::any_cast<int64>(value));
                            else if (value.type() == typeid(int32))
                                rowTbl.SetInteger(key, std::any_cast<int32>(value));
                            else if (value.type() == typeid(int16))
                                rowTbl.SetInteger(key, std::any_cast<int16>(value));
                            else if (value.type() == typeid(int8))
                                rowTbl.SetInteger(key, std::any_cast<int8>(value));
                            else if (value.type() == typeid(bool))
                                rowTbl.SetInteger(key, std::any_cast<bool>(value));
                            else if (value.type() == typeid(float))
                                rowTbl.SetNumber(key, std::any_cast<float>(value));
                            else if (value.type() == typeid(double))
                                rowTbl.SetNumber(key, std::any_cast<double>(value));
                        }

                        tbl.Set(i + 1, rowTbl);
                    }

                    return tbl; });

    state->DoString("db = nil;");

    PRINT("Scripting - Lua", "Database loaded.\n");
}