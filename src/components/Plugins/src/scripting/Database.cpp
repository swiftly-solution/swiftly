#include "../../../../common.h"
#include "../../../../database/DatabaseManager.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

std::string SerializeData(const std::vector<std::map<const char *, std::any>> &data)
{
    rapidjson::Document document(rapidjson::kArrayType);

    for (const auto &map : data)
    {
        rapidjson::Value entry(rapidjson::kObjectType);

        for (const auto &pair : map)
        {
            const char *key = pair.first;
            const std::any &value = pair.second;
            rapidjson::Value &keyVal = rapidjson::Value().SetString(key, document.GetAllocator());

            if (value.type() == typeid(const char *))
                entry.AddMember(keyVal, rapidjson::Value().SetString(std::any_cast<const char *>(value), document.GetAllocator()), document.GetAllocator());
            else if (value.type() == typeid(std::string))
                entry.AddMember(keyVal, rapidjson::Value().SetString(std::any_cast<std::string>(value).c_str(), document.GetAllocator()), document.GetAllocator());
            else if (value.type() == typeid(uint64))
                entry.AddMember(keyVal, rapidjson::Value().SetUint64(std::any_cast<uint64>(value)), document.GetAllocator());
            else if (value.type() == typeid(uint32))
                entry.AddMember(keyVal, rapidjson::Value().SetUint(std::any_cast<uint32>(value)), document.GetAllocator());
            else if (value.type() == typeid(uint16))
                entry.AddMember(keyVal, rapidjson::Value().SetUint(std::any_cast<uint16>(value)), document.GetAllocator());
            else if (value.type() == typeid(uint8))
                entry.AddMember(keyVal, rapidjson::Value().SetUint(std::any_cast<uint8>(value)), document.GetAllocator());
            else if (value.type() == typeid(int64))
                entry.AddMember(keyVal, rapidjson::Value().SetInt64(std::any_cast<int64>(value)), document.GetAllocator());
            else if (value.type() == typeid(int32))
                entry.AddMember(keyVal, rapidjson::Value().SetInt(std::any_cast<int32>(value)), document.GetAllocator());
            else if (value.type() == typeid(int16))
                entry.AddMember(keyVal, rapidjson::Value().SetInt(std::any_cast<int16>(value)), document.GetAllocator());
            else if (value.type() == typeid(int8))
                entry.AddMember(keyVal, rapidjson::Value().SetInt(std::any_cast<int8>(value)), document.GetAllocator());
            else if (value.type() == typeid(bool))
                entry.AddMember(keyVal, rapidjson::Value().SetBool(std::any_cast<bool>(value)), document.GetAllocator());
            else if (value.type() == typeid(float))
                entry.AddMember(keyVal, rapidjson::Value().SetFloat(std::any_cast<float>(value)), document.GetAllocator());
            else if (value.type() == typeid(double))
                entry.AddMember(keyVal, rapidjson::Value().SetDouble(std::any_cast<double>(value)), document.GetAllocator());
        }

        document.PushBack(entry, document.GetAllocator());
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    return std::string(buffer.GetString());
}

SMM_API bool scripting_Database_Connect(const char *connectionName)
{
    if (connectionName == nullptr)
        return false;

    Database *db = g_dbManager->GetDatabase(connectionName);
    if (db == nullptr)
    {
        PRINTF("Database", "Couldn't connect to the database \"%s\" because the connection details are not present in the configuration.\n", connectionName);
        return false;
    }

    if (db->IsConnected())
        return true;

    if (!db->Connect())
    {
        PRINTF("Database", "An error has been encountered while trying to connect to the database \"%s\".\n%s\n", connectionName, db->GetError().c_str());
        return false;
    }

    return true;
}

SMM_API const char *scripting_Database_EscapeString(const char *connectionName, const char *value)
{
    if (connectionName == nullptr || value == nullptr)
        return "";

    Database *db = g_dbManager->GetDatabase(connectionName);
    if (db == nullptr)
        return value;

    if (!db->IsConnected())
        return value;

    if (db->HasError())
        return value;

    return db->QueryEscape(value).c_str();
}

SMM_API const char *scripting_Database_Query(const char *connectionName, const char *query)
{
    if (connectionName == nullptr || query == nullptr)
        return SerializeData({}).c_str();

    Database *db = g_dbManager->GetDatabase(connectionName);
    if (db == nullptr)
        return SerializeData({}).c_str();

    if (!db->IsConnected())
        return SerializeData({}).c_str();

    std::vector<std::map<const char *, std::any>> results = db->Query(query);

    if (results.size() == 0 && db->HasError())
    {
        std::string err = db->GetError();
        if (err != "")
            PRINTF("Database", "An error has been encountered while a query was executed.\nQuery: \"%s\"\nError: %s\n", query, err.c_str());
        return SerializeData({}).c_str();
    }

    std::string result = SerializeData(results);
    return result.c_str();
}