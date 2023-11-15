#ifndef _swiftly_database_h
#define _swiftly_database_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include <map>
#include <vector>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

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

DB_Result DeserializeData(const char *jsonData)
{
    DB_Result result;

    rapidjson::Document document;
    document.Parse(jsonData);

    if (document.IsArray())
    {
        for (const auto &entry : document.GetArray())
        {
            std::map<std::string, BaseValue *> mp;

            for (auto it = entry.MemberBegin(); it != entry.MemberEnd(); ++it)
            {
                const char *key = it->name.GetString();

                if (it->value.IsString())
                    mp.insert(std::make_pair(key, new TypedValue<const char *>(it->value.GetString())));
                else if (it->value.IsInt())
                    mp.insert(std::make_pair(key, new TypedValue<int>(it->value.GetInt())));
                else if (it->value.IsInt64())
                    mp.insert(std::make_pair(key, new TypedValue<int64_t>(it->value.GetInt64())));
                else if (it->value.IsUint())
                    mp.insert(std::make_pair(key, new TypedValue<uint32_t>(it->value.GetUint())));
                else if (it->value.IsUint64())
                    mp.insert(std::make_pair(key, new TypedValue<uint64_t>(it->value.GetUint64())));
                else if (it->value.IsBool())
                    mp.insert(std::make_pair(key, new TypedValue<bool>(it->value.GetBool())));
                else if (it->value.IsFloat())
                    mp.insert(std::make_pair(key, new TypedValue<float>(it->value.GetFloat())));
                else if (it->value.IsDouble())
                    mp.insert(std::make_pair(key, new TypedValue<double>(it->value.GetDouble())));
            }

            result.push_back(mp);
        }
    }

    return result;
}

class Database
{
private:
    const char *m_connectionName;
    bool m_connected = false;

public:
    Database(const char *connectionName) : m_connectionName(connectionName)
    {
        void *database_Connect = FetchFunctionPtr(nullptr, "scripting_Database_Connect");
        if (database_Connect)
            m_connected = reinterpret_cast<Database_Connect>(database_Connect)(this->m_connectionName);
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
            return reinterpret_cast<Database_EscapeString>(database_EscapeString)(this->m_connectionName, value);
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

        const char *serialized = reinterpret_cast<Database_Query>(database_Query)(this->m_connectionName, buffer);

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