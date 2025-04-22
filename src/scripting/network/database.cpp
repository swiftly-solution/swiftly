#include <scripting/core.h>

#include <network/database/DatabaseManager.h>

#include <utils/common.h>
#include <utils/utils.h>

void Query(IDatabase* db, std::string query, EValue callback, EContext* L)
{
    if (db->GetKind() != "mysql" && db->GetKind() != "sqlite") {
        PLUGIN_PRINT("Database - Query", "This function is supporting only SQL databases.\n");
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
    db->AddQueryQueue(queue);
}

LoadScriptingComponent(database, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Database");

    ADD_CLASS_FUNCTION("Database", "Database", [](FunctionContext* context, ClassData* data) -> void {
        std::string connection_name = context->GetArgumentOr<std::string>(0, "default_connection");
        auto db = g_dbManager.GetDatabase(connection_name);
        if (!db && connection_name != "default_connection") {
            PRINTF("Database connection \"%s\" doesn't exists inside the database configurations. Automatically falling back to \"default_connection\".\n", connection_name.c_str());
            db = g_dbManager.GetDatabase("default_connection");
        }

        if (!db->Connect()) {
            PRINTF("An error has occured while trying to connect to database \"%s\":\nError: %s\n", connection_name.c_str(), db->GetError().c_str());
        }

        data->SetData("connection_name", connection_name);
        data->SetData("db", db);
    });

    ADD_CLASS_FUNCTION("Database", "IsConnected", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        if (!db) return context->SetReturn(false);

        context->SetReturn(db->IsConnected());
    });

    ADD_CLASS_FUNCTION("Database", "EscapeString", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        std::string str = context->GetArgumentOr<std::string>(0, "");

        if (!db || !db->IsConnected()) return context->SetReturn(str);

        context->SetReturn(db->EscapeValue(str));
    });

    ADD_CLASS_FUNCTION("Database", "GetVersion", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        if (!db || !db->IsConnected()) return context->SetReturn("");

        context->SetReturn(db->GetVersion());
    });

    ADD_CLASS_FUNCTION("Database", "Query", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        if (!db || !db->IsConnected()) return;

        std::string query = context->GetArgumentOr<std::string>(0, "");
        if (query == "") return;

        EValue callback = context->GetArgument<EValue>(1);

        Query(db, query, callback, context->GetPluginContext());
    });

    ADD_CLASS_FUNCTION("Database", "QueryParams", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        if (!db || !db->IsConnected()) return;

        std::string query = context->GetArgumentOr<std::string>(0, "");
        if (query == "") return;

        std::map<EValue, EValue> params = context->GetArgumentOr<std::map<EValue, EValue>>(1, std::map<EValue, EValue>{});
        EValue callback = context->GetArgument<EValue>(2);

        bool has_ats = (query.find_first_of("@") != std::string::npos);
        bool has_brace = (query.find_first_of("{") != std::string::npos);
        bool has_bracket = (query.find_first_of("[") != std::string::npos);

        for (auto it = params.begin(); it != params.end(); ++it)
        {
            EValue first = *(EValue*)(&(it->first));
            std::string key = first.isString() ? first.cast<std::string>() : first.tostring();
            std::string value = db->EscapeValue(it->second.isString() ? it->second.cast<std::string>() : it->second.tostring());

            if (has_ats)
                query = replace(query, "@" + key, value);

            if (has_brace)
                query = replace(query, "{" + key + "}", value);

            if (has_bracket)
                query = replace(query, "[" + key + "]", value);
        }

        Query(db, query, callback, context->GetPluginContext());
    });

    ADD_CLASS_FUNCTION("Database", "ExecuteQB", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        if (!db || !db->IsConnected()) return;

        std::string query = context->GetArgumentOr<std::string>(0, "");
        if (query == "") return;

        EValue callback = context->GetArgument<EValue>(1);

        std::string uuid = get_uuid();

        EValue databaseRequestsQueue = EValue::getGlobal(context->GetPluginContext(), "databaseRequestsQueue");
        if (databaseRequestsQueue.isTable()) {
            databaseRequestsQueue.setProperty(uuid, EValue(callback));
        }

        DatabaseQueryQueue queue = {
            query,
            uuid,
        };
        db->AddQueryQueue(queue);
    });

    ADD_CLASS_FUNCTION("Database", "QueryBuilder", [](FunctionContext* context, ClassData* data) -> void {
        IDatabase* db = data->GetData<IDatabase*>("db");
        if (!db || !db->IsConnected()) return context->SetReturn(nullptr);

        EContext* L = context->GetPluginContext();
        EValue global = EValue::getGlobal(L, db->ProvideQueryBuilderTable());
        context->SetReturn(global(data));
    });
})