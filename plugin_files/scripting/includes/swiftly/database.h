#ifndef _swiftly_database_h
#define _swiftly_database_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include <map>
#include <vector>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <cstdarg>

class BaseValue
{
public:
    virtual ~BaseValue() {}
    virtual std::string getType() const = 0;
};

template <typename T>
class TypedValue : public BaseValue
{
public:
    TypedValue(const T &value) : data(value) {}

    T getValue() const
    {
        return data;
    }

    std::string getType() const override
    {
        return typeid(T).name();
    }

private:
    T data;
};

typedef std::vector<std::map<std::string, BaseValue *>> DB_Result;
typedef const char *(*Database_Query)(const char *, const char *);

DB_Result DeserializeData(const char *jsonData);

class Database
{
private:
    std::string m_connectionName;
    bool m_connected = false;

public:
    Database(std::string connectionName) : m_connectionName(connectionName)
    {
        void *database_Connect = FetchFunctionPtr(nullptr, "scripting_Database_Connect");
        if (database_Connect)
            m_connected = reinterpret_cast<Database_Connect>(database_Connect)(this->m_connectionName.c_str());
    }
    ~Database()
    {
        m_connected = false;
    }

    bool IsConnected() { return this->m_connected; }

    const char *EscapeString(const char *value)
    {
        if (value == nullptr)
            return "";
        if (!m_connected)
            return value;

        void *database_EscapeString = FetchFunctionPtr(nullptr, "scripting_Database_EscapeString");
        if (database_EscapeString)
            return reinterpret_cast<Database_EscapeString>(database_EscapeString)(this->m_connectionName.c_str(), value);
        else
            return "";
    }

    DB_Result Query(const char *query, ...)
    {
        if (!m_connected)
            return {};

        void *database_Query = FetchFunctionPtr(nullptr, "scripting_Database_Query");
        if (!database_Query)
            return {};

        va_list ap;
        char buffer[2048];

        va_start(ap, query);
        UTIL_FormatArgs(buffer, sizeof(buffer), query, ap);
        va_end(ap);

        const char *serialized = reinterpret_cast<Database_Query>(database_Query)(this->m_connectionName.c_str(), buffer);

        return DeserializeData(serialized);
    }

    std::vector<std::string> fetchFields(DB_Result result)
    {
        if (result.size() == 0)
            return {};

        std::vector<std::string> fields;

        for (auto v : result[0])
            fields.push_back(v.first);

        return fields;
    }

    template <typename T>
    T fetchValue(DB_Result result, uint64_t row, std::string column)
    {
        if (result.size() < row)
            return 0;

        if (result[row].find(column) == result[row].end())
            return 0;

        return dynamic_cast<TypedValue<T> *>(result[row][column])->getValue();
    }
};

extern Database *db;

#endif