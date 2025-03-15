#include "../../scripting.h"
#include "../../../../entrypoint.h"
#include "../../../../player/playermanager/PlayerManager.h"

#include <vector>
#include <map>

PluginDatabase::PluginDatabase(std::string m_connection_name)
{
    this->connection_name = m_connection_name;
    this->db = g_dbManager->GetDatabase(this->connection_name);

    if (!this->db && this->connection_name != "default_connection") {
        PRINTF("Database connection \"%s\" doesn't exists inside the database configurations. Automatically falling back to \"default_connection\".\n", m_connection_name.c_str());
        this->db = g_dbManager->GetDatabase("default_connection");
    }

    if (!this->db)
        this->dbConnected = false;
    else {
        this->dbConnected = this->db->Connect();
        if (!this->dbConnected) {
            PRINTF("An error has occured while trying to connect to database \"%s\":\nError: %s\n", m_connection_name.c_str(), this->db->GetError().c_str());
        }
    }
}


void PluginDatabase::Query(std::string query, EValue callback, EContext* L)
{
    if (this->db->GetKind() != "mysql" && this->db->GetKind() != "sqlite") {
        PLUGIN_PRINT("Database - Query", "This function is supporting only MySQL databases.\n");
        return;
    }
    std::string uuid = get_uuid();

    EValue databaseRequestsQueue = EValue::getGlobal(L, "databaseRequestsQueue");
    if (databaseRequestsQueue.isTable())
        databaseRequestsQueue.setProperty(uuid, EValue(callback));

    DatabaseQueryQueue queue = {
        query,
        uuid,
    };
    this->db->AddQueryQueue(queue);
}

void PluginDatabase::QueryParams(std::string query, std::map<EValue, EValue> params, EValue callback, EContext* L)
{
    if (this->db->GetKind() != "mysql" && this->db->GetKind() != "sqlite") {
        PLUGIN_PRINT("Database - Query", "This function is supporting only MySQL databases.\n");
        return;
    }

    bool has_ats = (query.find_first_of("@") != std::string::npos);
    bool has_brace = (query.find_first_of("{") != std::string::npos);
    bool has_bracket = (query.find_first_of("[") != std::string::npos);

    for (auto it = params.begin(); it != params.end(); ++it)
    {
        EValue first = *(EValue*)(&(it->first));
        std::string key = first.isString() ? first.cast<char const*>() : first.tostring();
        std::string value = EscapeString(it->second.isString() ? it->second.cast<char const*>() : it->second.tostring());

        if (has_ats)
            query = replace(query, "@" + key, value);

        if (has_brace)
            query = replace(query, "{" + key + "}", value);

        if (has_bracket)
            query = replace(query, "[" + key + "]", value);
    }

    return Query(query, callback, L);
}

bool PluginDatabase::IsConnected()
{
    if (!this->db || !this->db->IsConnected()) return false;
    return this->dbConnected;
}

std::string PluginDatabase::EscapeString(std::string str)
{
    if (!this->db || !this->db->IsConnected()) return str;
    return this->db->EscapeValue(str);
}

std::string PluginDatabase::GetVersion()
{
    if (!this->db || !this->db->IsConnected()) return "";
    return this->db->GetVersion();
}