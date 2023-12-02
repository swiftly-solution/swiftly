#include "Database.h"

const char *Database::QueryEscape(const char *query)
{
    char *newQuery = new char[strlen(query) * 2 + 1];
    mysql_real_escape_string(this->connection, newQuery, query, strlen(query));
    std::string str(newQuery);
    delete[] newQuery;
    return str.c_str();
}

bool Database::Connect()
{
    if (mysql_library_init(0, nullptr, nullptr) != 0)
    {
        this->error = "Couldn't initialize MySQL Client Library.";
        return false;
    }
    this->connection = mysql_init(nullptr);
    if (this->connection == nullptr)
    {
        this->error = mysql_error(this->connection);
        return false;
    }

    PRINTF("Database::Connect", "Port: %d\n", this->m_port);

    if (mysql_real_connect(this->connection, this->m_hostname.c_str(), this->m_username.c_str(), this->m_password.c_str(), this->m_database.c_str(), this->m_port, nullptr, 0) == nullptr)
    {
        this->Close(true);
        return false;
    }

    this->connected = true;

    return true;
}

std::vector<std::map<const char *, std::any>> Database::Query(const char *query)
{
    std::vector<std::map<const char *, std::any>> values;

    if (mysql_ping(this->connection))
    {
        this->error = mysql_error(this->connection);
        return {};
    }

    if (mysql_query(this->connection, query))
    {
        this->error = mysql_error(this->connection);
        return {};
    }

    MYSQL_RES *result = mysql_store_result(this->connection);
    if (result == nullptr)
    {
        std::map<const char *, std::any> value;

        if (mysql_field_count(this->connection) == 0)
        {
            value.insert(std::make_pair("warningCounts", (uint64)mysql_warning_count(this->connection)));
            value.insert(std::make_pair("affectedRows", mysql_affected_rows(this->connection)));
            value.insert(std::make_pair("insertId", mysql_insert_id(this->connection)));
            values.push_back(value);
        }
        else
        {
            this->error = std::string("Invalid query type.\nQuery: " + std::string(query)).c_str();
            return {};
        }
    }
    else
    {
        uint32 num_fields = mysql_num_fields(result);
        MYSQL_ROW row;
        MYSQL_FIELD *field;

        std::vector<const char *> fields;
        while ((field = mysql_fetch_field(result)))
            fields.push_back(field->name);

        while ((row = mysql_fetch_row(result)))
        {
            std::map<const char *, std::any> value;
            for (uint32 i = 0; i < num_fields; i++)
                value.insert(std::make_pair(fields[i], row[i] ? row[i] : "NULL"));

            values.push_back(value);
        }
        mysql_free_result(result);
    }

    return values;
}

void Database::Close(bool containsError)
{
    if (containsError)
        this->error = mysql_error(this->connection);
    mysql_close(this->connection);
}

const char *Database::GetError()
{
    const char *err = nullptr;
    memcpy(&err, &this->error, sizeof(err));
    this->error = nullptr;
    return err;
}