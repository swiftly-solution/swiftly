#ifndef _database_h
#define _database_h

#include "../common.h"
#ifdef _WIN32
#include <winsock2.h>
#endif
#include <mysql.h>

class Database
{
private:
    uint16 m_port;
    const char *m_hostname;
    const char *m_username;
    const char *m_password;
    const char *m_database;
    MYSQL *connection;

    const char *error;

public:
    Database(const char *hostname, const char *username, const char *password, const char *database, uint16 port) : m_hostname(hostname), m_username(username), m_password(password), m_port(port), m_database(database) {}

    bool Connect();
    void Close(bool containsError = false);
    const char *GetError();
};

#endif