#ifndef _databasemanager_h
#define _databasemanager_h

#include <map>
#include "IDatabase.h"
#include "mysql/MySQLDatabase.h"

class DatabaseManager
{
private:
    const char *databasesPath = "addons/swiftly/configs/databases.json";
    std::map<std::string, IDatabase *> databases;

public:
    DatabaseManager() {}
    ~DatabaseManager() {}

    void LoadDatabases();
    IDatabase *GetDatabase(std::string name);
};

extern DatabaseManager *g_dbManager;

#endif