#include "../../core.h"

EValue PluginDatabase::QueryBuilder(EContext* L)
{
    if (!this->db || !this->db->IsConnected()) return EValue(L);

    EValue global = EValue::getGlobal(L, db->ProvideQueryBuilderTable());
    EValue dbvar(L, this);
    return global(dbvar);
}

void PluginDatabase::ExecuteQB(std::string query, EValue cb, EContext* L)
{
    std::string uuid = get_uuid();

    EValue databaseRequestsQueue = EValue::getGlobal(L, "databaseRequestsQueue");
    if (databaseRequestsQueue.isTable()) {
        databaseRequestsQueue.setProperty(uuid, EValue(cb));
    }

    DatabaseQueryQueue queue = {
        query,
        uuid,
    };
    this->db->AddQueryQueue(queue);
}

LoadScriptingComponent(
    database,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginDatabase>("Database", state)
            .addConstructor<std::string>()
            .addFunction("IsConnected", &PluginDatabase::IsConnected)
            .addFunction("EscapeString", &PluginDatabase::EscapeString)
            .addFunction("QueryBuilder", &PluginDatabase::QueryBuilder)
            .addFunction("GetVersion", &PluginDatabase::GetVersion)
            .addFunction("ExecuteQB", &PluginDatabase::ExecuteQB)
            .addFunction("QueryParams", &PluginDatabase::QueryParams)
            .addFunction("Query", &PluginDatabase::Query)
        .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("db = Database(\"default_connection\")");  
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.db = Database(\"default_connection\")");
    }
)
