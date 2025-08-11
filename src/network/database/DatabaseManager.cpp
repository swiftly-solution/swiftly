#include "DatabaseManager.h"
#include <core/entrypoint.h>
#include <filesystem/files/files.h>
#include "DBDriver.h"
#include <swiftly-ext/core.h>
#include <rapidjson/json.hpp>

std::vector<DBDriver*> dbDrivers;

void DatabasesError(std::string error)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Databases", "Error: %s\n", error.c_str());
}

void WriteJSONFile(std::string path, rapidjson::Value& j);

void DatabaseManager::LoadDatabases()
{
    bool modified = false;
    rapidjson::Document databasesConfigFile;
    databasesConfigFile.Parse(Files::Read(databasesPath).c_str());
    if (databasesConfigFile.HasParseError())
        return DatabasesError(string_format("A parsing error has been detected.\nError (offset %u): %s\n", (unsigned)databasesConfigFile.GetErrorOffset(), GetParseError_En(databasesConfigFile.GetParseError())));

    if (!databasesConfigFile.IsObject())
        return DatabasesError("Databases file needs to be an object.");

    for (auto itr = databasesConfigFile.MemberBegin(); itr != databasesConfigFile.MemberEnd(); ++itr)
    {
        if (!itr->value.IsObject())
        {
            DatabasesError(string_format("Database connection \"%s\" needs to be an object.", itr->name.GetString()));
            continue;
        }

        if (!itr->value.HasMember("kind")) {
            modified = true;
            itr->value.AddMember(rapidjson::Value().SetString("kind", databasesConfigFile.GetAllocator()), rapidjson::Value().SetString("mysql", databasesConfigFile.GetAllocator()), databasesConfigFile.GetAllocator());
        }

        const char* connectionName = itr->name.GetString();
        std::map<std::string, std::string> connection_details;

        for (auto it = itr->value.MemberBegin(); it != itr->value.MemberEnd(); ++it)
        {
            if (it->value.IsNumber()) connection_details.insert({ it->name.GetString(), std::to_string(it->value.GetInt64()) });
            else if (it->value.IsString()) connection_details.insert({ it->name.GetString(), it->value.GetString() });
        }

        IDatabase* db = nullptr;

        for (auto driver : dbDrivers) {
            if (driver->GetKind() == connection_details["kind"]) {
                db = driver->RegisterDatabase();
                break;
            }
        }

        if (!db) {
            PLUGIN_PRINTF("Database", "Database kind %s used by \"%s\" doesn't have an extension. It will be registered but queries will not be executed.\n", connection_details["kind"].c_str(), connectionName);
            databases.insert({ connectionName, nullptr });
        }
        else {
            db->SetConnectionConfig(connection_details);
            databases.insert({ connectionName, db });
        }

        databases_credentials.insert({ connectionName, connection_details });
        database_kind.insert({ connectionName, connection_details["kind"] });
    }

    if (modified) {
        WriteJSONFile("addons/swiftly/configs/databases.json", databasesConfigFile);
    }

    PLUGIN_PRINTF("Database", "%d databases have been succesfully loaded.\n", databases.size());
}

IDatabase* DatabaseManager::GetDatabase(std::string name)
{
    if (databases.find(name) == databases.end())
        return nullptr;

    return databases.at(name);
}

std::map<std::string, std::string> DatabaseManager::GetDatabaseCredentials(std::string name)
{
    if (databases.find(name) == databases.end()) return {};

    return databases_credentials[name];
}

std::string DatabaseManager::GetDatabaseKind(std::string name)
{
    if (databases.find(name) == databases.end()) return "unknown";

    return database_kind[name];
}

EXT_API void swiftly_RegisterDBDriver(void* driverPtr)
{
    dbDrivers.push_back((DBDriver*)driverPtr);
}