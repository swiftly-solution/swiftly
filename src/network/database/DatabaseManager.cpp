#include "DatabaseManager.h"
#include "../../filesystem/files/Files.h"
#include "../../common.h"
#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

void DatabasesError(std::string error)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Databases", "Error: %s\n", error.c_str());
}

void WritePluginFile(std::string path, rapidjson::Value& val);

void DatabaseManager::LoadDatabases()
{
    bool modified = false;
    rapidjson::Document databasesConfigFile;
    databasesConfigFile.Parse(Files::Read(this->databasesPath).c_str());
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

        if(!itr->value.HasMember("kind")) {
            modified = true;
            itr->value.AddMember(rapidjson::Value().SetString("kind", databasesConfigFile.GetAllocator()), rapidjson::Value().SetString("mysql", databasesConfigFile.GetAllocator()), databasesConfigFile.GetAllocator());
        }

        const char *connectionName = itr->name.GetString();
        std::map<std::string, std::string> connection_details;
        
        for(auto it = itr->value.MemberBegin(); it != itr->value.MemberEnd(); ++it)
        {
            if(it->value.IsNumber()) connection_details.insert({ it->name.GetString(), std::to_string(it->value.GetInt64()) });
            else if (it->value.IsString()) connection_details.insert({ it->name.GetString(), it->value.GetString() });
        }

        IDatabase* db = nullptr;
        if(connection_details["kind"] == "mysql" || connection_details["kind"] == "mariadb")
            db = new MySQLDatabase();

        db->SetConnectionConfig(connection_details);
        this->databases.insert({connectionName, db});
    }

    if(modified) {
        WritePluginFile("addons/swiftly/configs/databases.json", databasesConfigFile);
    }

    PLUGIN_PRINTF("Database", "%d databases have been succesfully loaded.\n", this->databases.size());
}

IDatabase *DatabaseManager::GetDatabase(std::string name)
{
    if (this->databases.find(name) == this->databases.end())
        return nullptr;

    return this->databases.at(name);
}