#include "../../scripting.h"
#include "../../../../entrypoint.h"
#include "../../../../player/playermanager/PlayerManager.h"

#include <vector>
#include <map>

PluginDatabase::PluginDatabase(std::string m_connection_name)
{
    this->connection_name = m_connection_name;
    this->db = g_dbManager->GetDatabase(this->connection_name);
    
    if(!this->db && this->connection_name != "default_connection") {
        PRINTF("Database connection \"%s\" doesn't exists inside the database configurations. Automatically falling back to \"default_connection\".\n", m_connection_name.c_str());
        this->db = g_dbManager->GetDatabase("default_connection");
    }

    if (!this->db)
        this->dbConnected = false;
    else
        this->dbConnected = this->db->Connect();
}

bool PluginDatabase::IsConnected()
{
    if(!this->db || !this->db->IsConnected()) return false;
    return this->dbConnected;
}

std::string PluginDatabase::EscapeString(std::string str)
{
    if(!this->db || !this->db->IsConnected()) return str;
    return this->db->EscapeValue(str);
}

std::string PluginDatabase::GetVersion()
{
    if(!this->db || !this->db->IsConnected()) return "";
    return this->db->GetVersion();
}