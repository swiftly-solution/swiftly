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
#include <string>
#include <mutex>

class Database
{
private:
    uint16 m_port;
    std::string m_hostname;
    std::string m_username;
    std::string m_password;
    std::string m_database;
    MYSQL* connection;
    bool connected = false;

    std::mutex mtx;

    const char* error = nullptr;

public:
    Database(std::string hostname, std::string username, std::string password, std::string database, uint16 port)
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
    std::string GetError();
    bool HasError() { return this->error != nullptr; }

    std::string QueryEscape(const char* query);
    std::vector<std::map<const char*, std::any>> Query(const char* query);
};

#endif