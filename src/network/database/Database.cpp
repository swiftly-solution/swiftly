#include "Database.h"
#include "../../filesystem/files/Files.h"

std::string Database::QueryEscape(const char* query)
{
    char* newQuery = new char[strlen(query) * 2 + 1];
    mysql_real_escape_string(this->connection, newQuery, query, strlen(query));
    std::string str(newQuery);
    delete[] newQuery;
    return str;
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

    my_bool my_true = true;
    mysql_options(this->connection, MYSQL_OPT_RECONNECT, &my_true);

    unsigned int timeout = 60;
    mysql_options(this->connection, MYSQL_OPT_CONNECT_TIMEOUT, &timeout);
    mysql_options(this->connection, MYSQL_OPT_READ_TIMEOUT, &timeout);
    mysql_options(this->connection, MYSQL_OPT_WRITE_TIMEOUT, &timeout);

    mysql_set_character_set(this->connection, "utf8");

    if (mysql_real_connect(this->connection, this->m_hostname.c_str(), this->m_username.c_str(), this->m_password.c_str(), this->m_database.c_str(), this->m_port, nullptr, 0) == nullptr)
    {
        this->Close(true);
        return false;
    }

    this->connected = true;

    return true;
}

static constexpr int MYSQL_JSON = 245;

std::any ParseFieldType(enum_field_types type, const char* value, uint32_t length)
{
    if (type == enum_field_types::MYSQL_TYPE_FLOAT || type == enum_field_types::MYSQL_TYPE_DOUBLE || type == enum_field_types::MYSQL_TYPE_DECIMAL)
        return atof(value);
    else if (type == enum_field_types::MYSQL_TYPE_SHORT || type == enum_field_types::MYSQL_TYPE_TINY || type == enum_field_types::MYSQL_TYPE_INT24 || type == enum_field_types::MYSQL_TYPE_LONG || type == enum_field_types::MYSQL_TYPE_NEWDECIMAL)
        return atoi(value);
    else if (type == enum_field_types::MYSQL_TYPE_VARCHAR || type == enum_field_types::MYSQL_TYPE_VAR_STRING || type == enum_field_types::MYSQL_TYPE_BLOB || type == MYSQL_JSON || type == enum_field_types::MYSQL_TYPE_TIMESTAMP) {
        return std::string(value, length + 1);
    }
    else if (type == enum_field_types::MYSQL_TYPE_LONGLONG)
        return strtoll(value, nullptr, 10);
    else
    {
        PLUGIN_PRINTF("Database - ParseFieldType", "Invalid field type: %d.\n", type);
        return std::string("NULL");
    }
}

std::vector<std::map<std::string, std::any>> Database::Query(const char* query)
{
    std::lock_guard<std::mutex> lock(mtx);
    std::vector<std::map<std::string, std::any>> values;

    if (!this->connected)
        return {};

    if (mysql_ping(this->connection))
    {
        this->error = mysql_error(this->connection);
        return {};
    }

    if (mysql_real_query(this->connection, query, strlen(query)))
    {
        this->error = mysql_error(this->connection);
        return {};
    }

    MYSQL_RES* result = mysql_use_result(this->connection);
    if (result == nullptr)
    {
        std::map<std::string, std::any> value;

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
        MYSQL_ROW row;
        MYSQL_FIELD* fields = mysql_fetch_fields(result);
        int num_fields = mysql_num_fields(result);

        while ((row = mysql_fetch_row(result))) {
            std::map<std::string, std::any> value;
            unsigned long *lengths = mysql_fetch_lengths(result);

            for (int i = 0; i < num_fields; i++) {
                value.insert({ fields[i].name, row[i] ? ParseFieldType(fields[i].type, row[i], lengths[i]) : "NULL" });
            }

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

std::string Database::GetError()
{
    if (!this->error)
        return "";

    std::string err(this->error);
    this->error = nullptr;
    return err;
}