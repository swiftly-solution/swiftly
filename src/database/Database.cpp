#include "Database.h"

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

    if (mysql_real_connect(this->connection, this->m_hostname, this->m_username, this->m_password, this->m_database, 0, nullptr, 0) == nullptr)
    {
        this->Close(true);
        return false;
    }

    return true;
}

void Database::Close(bool containsError)
{
    if (containsError)
        this->error = mysql_error(this->connection);
    mysql_close(this->connection);
}

const char *Database::GetError()
{
    return this->error;
}