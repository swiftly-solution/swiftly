#ifndef _database_h
#define _database_h

#include "../common.h"
#ifdef _WIN32
#include <winsock2.h>
#endif
#include <mysql.h>
#include <map>
#include <any>
#include <vector>

class Database
{
private:
    uint16 m_port;
    const char *m_hostname;
    const char *m_username;
    const char *m_password;
    const char *m_database;
    MYSQL *connection;
    bool connected = false;

    const char *error = nullptr;

public:
    Database(const char *hostname, const char *username, const char *password, const char *database, uint16 port)
    {
        this->m_hostname = hostname;
        this->m_username = username;
        this->m_password = password;
        this->m_port = port;
        this->m_database = database;
    }

    bool Connect();
    void Close(bool containsError = false);
    bool IsConnected() { return this->connected; }
    const char *GetError();
    bool HasError() { return this->error != nullptr; }

    const char *QueryEscape(const char *query);
    std::vector<std::map<const char *, std::any>> Query(const char *query);
};

#endif