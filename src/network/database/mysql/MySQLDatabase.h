#ifndef _network_database_mysql_mysqldatabase_h
#define _network_database_mysql_mysqldatabase_h

#include "../IDatabase.h"
#ifdef _WIN32
#include <winsock2.h>
#endif
#include <mysql.h>
#include <mutex>

class MySQLDatabase : public IDatabase
{
private:
    uint16_t m_port;
    std::string m_hostname;
    std::string m_username;
    std::string m_password;
    std::string m_database;
    MYSQL* connection;
    bool connected = false;

    std::mutex mtx;

    const char* error = nullptr;
public:
    void SetConnectionConfig(std::map<std::string, std::string> connection_details);

    bool Connect();
    void Close(bool setError);

    std::string GetKind();
    std::string GetVersion();

    bool IsConnected();

    bool HasError();
    std::string GetError();

    std::vector<std::map<std::string, std::any>> Query(std::any query);
    std::string EscapeValue(std::string query);
};

#endif