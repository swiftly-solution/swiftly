#include "../core.h"

LoadLuaScriptingComponent(
    database,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginDatabase>("Database")
            .addConstructor<void (*)(std::string)>()
            .addFunction("IsConnected", &PluginDatabase::IsConnected)
            .addFunction("EscapeString", &PluginDatabase::EscapeString)
            .addFunction("Query", &PluginDatabase::QueryLua)
            .addFunction("QueryParams", &PluginDatabase::QueryParamsLua)
            .addFunction("QueryBuilder", &PluginDatabase::QueryBuilderLua)
            .endClass();

        luabridge::getGlobalNamespace(state)
            .beginClass<PluginDatabaseQueryBuilder>("QueryBuilder")
            .addConstructor<void (*)(PluginDatabase*)>()
            .addFunction("Table", &PluginDatabaseQueryBuilder::Table)
            .addFunction("Select", &PluginDatabaseQueryBuilder::Select)
            .addFunction("Insert", &PluginDatabaseQueryBuilder::Insert)
            .addFunction("Update", &PluginDatabaseQueryBuilder::Update)
            .addFunction("Delete", &PluginDatabaseQueryBuilder::Delete)
            .addFunction("Where", &PluginDatabaseQueryBuilder::Where)
            .addFunction("OrWhere", &PluginDatabaseQueryBuilder::Where)
            .addFunction("Join", &PluginDatabaseQueryBuilder::Join)
            .addFunction("OrderBy", &PluginDatabaseQueryBuilder::OrderBy)
            .addFunction("Limit", &PluginDatabaseQueryBuilder::Limit)
            .addFunction("GroupBy", &PluginDatabaseQueryBuilder::GroupBy)
            .addFunction("Execute", &PluginDatabaseQueryBuilder::Execute)
            .addFunction("ToString", &PluginDatabaseQueryBuilder::ToString)
            .endClass();

        luaL_dostring(state, "db = Database(\"default_connection\")");
    }
)
