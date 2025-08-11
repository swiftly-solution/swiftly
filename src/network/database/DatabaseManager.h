#ifndef _databasemanager_h
#define _databasemanager_h

#include <map>
#include "IDatabase.h"

class DatabaseManager
{
private:
    const char* databasesPath = "addons/swiftly/configs/databases.json";
    std::map<std::string, IDatabase*> databases;
    std::map<std::string, std::map<std::string, std::string>> databases_credentials;
    std::map<std::string, std::string> database_kind;

public:
    void LoadDatabases();
    IDatabase* GetDatabase(std::string name);

    std::map<std::string, std::string> GetDatabaseCredentials(std::string name);
    std::string GetDatabaseKind(std::string name);
};

extern DatabaseManager g_dbManager;

#endif