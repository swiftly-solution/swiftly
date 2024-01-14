#include "DatabaseManager.h"
#include "../files/Files.h"
#include "../common.h"
#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

#define HAS_MEMBER(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                  \
    if (!DOCUMENT.HasMember(MEMBER_NAME))                                               \
    {                                                                                   \
        DatabasesError(string_format("The field \"%s\" doesn't exists.", MEMBER_PATH)); \
        continue;                                                                       \
    }

#define IS_OBJECT(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                     \
    if (!DOCUMENT[MEMBER_NAME].IsObject())                                                \
    {                                                                                     \
        DatabasesError(string_format("The field \"%s\" is not an object.", MEMBER_PATH)); \
        continue;                                                                         \
    }
#define IS_ARRAY(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                     \
    if (!DOCUMENT[MEMBER_NAME].IsArray())                                                \
    {                                                                                    \
        DatabasesError(string_format("The field \"%s\" is not an array.", MEMBER_PATH)); \
        continue;                                                                        \
    }
#define IS_STRING(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                    \
    if (!DOCUMENT[MEMBER_NAME].IsString())                                               \
    {                                                                                    \
        DatabasesError(string_format("The field \"%s\" is not a string.", MEMBER_PATH)); \
        continue;                                                                        \
    }
#define IS_BOOL(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                       \
    if (!DOCUMENT[MEMBER_NAME].IsBool())                                                  \
    {                                                                                     \
        DatabasesError(string_format("The field \"%s\" is not a boolean.", MEMBER_PATH)); \
        continue;                                                                         \
    }
#define IS_NUMBER(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                    \
    if (!DOCUMENT[MEMBER_NAME].IsNumber())                                               \
    {                                                                                    \
        DatabasesError(string_format("The field \"%s\" is not a number.", MEMBER_PATH)); \
        continue;                                                                        \
    }

void DatabasesError(std::string error)
{
    if (!g_SMAPI)
        return;

    PRINTF("Databases", "Error: %s\n", error.c_str());
}

void DatabaseManager::LoadDatabases()
{
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

        const char *connectionName = itr->name.GetString();

        HAS_MEMBER(itr->value, "hostname", string_format("%s.hostname", connectionName).c_str())
        IS_STRING(itr->value, "hostname", string_format("%s.hostname", connectionName).c_str())
        HAS_MEMBER(itr->value, "username", string_format("%s.username", connectionName).c_str())
        IS_STRING(itr->value, "username", string_format("%s.username", connectionName).c_str())
        HAS_MEMBER(itr->value, "password", string_format("%s.password", connectionName).c_str())
        IS_STRING(itr->value, "password", string_format("%s.password", connectionName).c_str())
        HAS_MEMBER(itr->value, "database", string_format("%s.database", connectionName).c_str())
        IS_STRING(itr->value, "database", string_format("%s.database", connectionName).c_str())
        HAS_MEMBER(itr->value, "port", string_format("%s.port", connectionName).c_str())
        IS_NUMBER(itr->value, "port", string_format("%s.port", connectionName).c_str())

        Database *db = new Database(itr->value["hostname"].GetString(), itr->value["username"].GetString(), itr->value["password"].GetString(), itr->value["database"].GetString(), (uint16)itr->value["port"].GetUint());
        this->databases.insert(std::make_pair(connectionName, db));
    }

    PRINT("Database", "All database configuration has been succesfully loaded.\n");
}

Database *DatabaseManager::GetDatabase(std::string name)
{
    if (this->databases.find(name) == this->databases.end())
        return nullptr;

    return this->databases.at(name);
}