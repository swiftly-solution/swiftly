#include <scripting/core.h>

#include <network/database/DatabaseManager.h>

#include <utils/common.h>
#include <utils/utils.h>

#ifdef strdup
#undef strdup
#endif

std::string& FetchPluginName(EContext* state);

void Query(IDatabase* db, std::string query, std::string callback, EContext* ctx)
{
    if (db->GetKind() != "mysql" && db->GetKind() != "sqlite") {
        PLUGIN_PRINT("Database - Query", "This function is supporting only SQL databases.\n");
        return;
    }
    const char* nq = (const char*)(strdup(query.c_str()));
    if (!nq) return;

    DatabaseQueryQueue queue = {
        nq,
        callback,
        FetchPluginName(ctx)
    };
    db->AddQueryQueue(queue);
}

LoadScriptingComponent(database, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("DB");

    ADD_CLASS_FUNCTION("DB", "DB", [](FunctionContext* context, ClassData* data) -> void {
        std::string connection_name = context->GetArgumentOr<std::string>(0, "default_connection");
        bool shouldSkipDefaultConnection = context->GetArgumentOr<bool>(1, false);

        auto db = g_dbManager.GetDatabase(connection_name);
        if (!db && connection_name != "default_connection") {
            PRINTF("Database connection \"%s\" doesn't exists inside the database configurations. Automatically falling back to \"default_connection\".\n", connection_name.c_str());
            if (!shouldSkipDefaultConnection) db = g_dbManager.GetDatabase("default_connection");
        }

        if (!db) {
            PRINTF("An error has occured while trying to connect to database \"%s\":\nError: Invalid connection inside `addons/swiftly/configs/databases.json`\n", connection_name.c_str());
        }
        else if (!db->Connect()) {
            PRINTF("An error has occured while trying to connect to database \"%s\":\nError: %s\n", connection_name.c_str(), db->GetError().c_str());
        }

        data->SetData("db", db);
    });

    ADD_CLASS_FUNCTION("DB", "IsConnected", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        if (!db) return context->SetReturn(false);

        context->SetReturn(db->IsConnected());
    });

    ADD_CLASS_FUNCTION("DB", "EscapeString", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        std::string str = context->GetArgumentOr<std::string>(0, "");

        if (!db || !db->IsConnected()) return context->SetReturn(str);

        context->SetReturn(db->EscapeValue(str));
    });

    ADD_CLASS_FUNCTION("DB", "GetVersion", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        if (!db || !db->IsConnected()) return context->SetReturn("");

        context->SetReturn(db->GetVersion());
    });

    ADD_CLASS_FUNCTION("DB", "Query", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        if (!db || !db->IsConnected()) return;

        std::string query = context->GetArgumentOr<std::string>(0, "");
        if (query == "") return;

        std::string callback = context->GetArgument<std::string>(1);
        Query(db, query, callback, context->GetPluginContext());
    });

    ADD_CLASS_FUNCTION("DB", "QueryBuilder", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        if (!db || !db->IsConnected()) return context->SetReturn(nullptr);

        context->SetReturn(db->ProvideQueryBuilderTable());
    });
})