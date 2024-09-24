#ifndef _databasemanager_h
#define _databasemanager_h

#include <map>
#include "Database.h"

class DatabaseManager
{
private:
    const char *databasesPath = "addons/swiftly/configs/databases.json";
    std::map<std::string, Database *> databases;

public:
    DatabaseManager() {}
    ~DatabaseManager() {}

    void LoadDatabases();
    Database *GetDatabase(std::string name);
};

extern DatabaseManager *g_dbManager;

#endif