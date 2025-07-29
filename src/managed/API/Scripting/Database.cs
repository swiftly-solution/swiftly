using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Database
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Database", "Database", CallKind.ClassFunction);
        }

        public class DB : ClassData
        {
            public DB(string connection_name): base(Internal_API.Invoker.CallNative<IntPtr>("Database", "Database", CallKind.ClassFunction, connection_name))
            {
            }
            public bool IsConnected()
            {
                return Internal_API.Invoker.CallNative<bool>("Database", "IsConnected", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public QueryBuilder QueryBuilder()
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("Database", "QueryBuilder", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public string EscapeString(string value)
            {
                return Internal_API.Invoker.CallNative<string>("Database", "EscapeString", Internal_API.CallKind.ClassFunction, m_classData, value) ?? "";
            }
            public void Query(string query, Action<string,object[]> callback)
            {
                Internal_API.Invoker.CallNative("Database", "Query", Internal_API.CallKind.ClassFunction, m_classData, query, callback);
            }
            public void QueryParams(string query, Dictionary<string, object> param, Action<string,object[]> callback)
            {
                Internal_API.Invoker.CallNative("Database", "QueryParams", Internal_API.CallKind.ClassFunction, m_classData, query, param, callback);
            }
        }
        public class QueryBuilder : ClassData
        {
            public QueryBuilder(): base(Internal_API.Invoker.CallNative<IntPtr>("QueryBuilder", "QueryBuilder", CallKind.ClassFunction))
            {
            }
            public QueryBuilder Table(string table_name)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Table", Internal_API.CallKind.ClassFunction, m_classData, table_name);
            }
            public QueryBuilder Select(string[] columns)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Select", Internal_API.CallKind.ClassFunction, m_classData, (object)columns);
            }
            public QueryBuilder Insert(Dictionary<string, object> values)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Insert", Internal_API.CallKind.ClassFunction, m_classData, values);
            }
            public QueryBuilder Update(Dictionary<string, object> values)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Update", Internal_API.CallKind.ClassFunction, m_classData, values);
            }
            public QueryBuilder Delete()
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Delete", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public QueryBuilder Where(string column, string oper, object value)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Where", Internal_API.CallKind.ClassFunction, m_classData, column, oper, value);
            }
            public QueryBuilder OrWhere(string column, string oper, object value)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "OrWhere", Internal_API.CallKind.ClassFunction, m_classData, column, oper, value);
            }
            public QueryBuilder Join(string table_name, string condition, string join_type)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Join", Internal_API.CallKind.ClassFunction, m_classData, table_name, condition, join_type);
            }
            public QueryBuilder OrderBy(Dictionary<string, string> columns)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "OrderBy", Internal_API.CallKind.ClassFunction, m_classData, columns);
            }
            public QueryBuilder Limit(int count)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Limit", Internal_API.CallKind.ClassFunction, m_classData, count);
            }
            public QueryBuilder GroupBy(string[] columns)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "GroupBy", Internal_API.CallKind.ClassFunction, m_classData, (object)columns);
            }
            public QueryBuilder Create(Dictionary<string, string> values)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Create", Internal_API.CallKind.ClassFunction, m_classData, values);
            }
            public QueryBuilder Alter(Dictionary<string, string> add_columns, Dictionary<string, string> remove_columns, Dictionary<string, string> modify_columns)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Alter", Internal_API.CallKind.ClassFunction, m_classData, add_columns, remove_columns, modify_columns);
            }
            public QueryBuilder Drop()
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Drop", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public QueryBuilder OnDuplicate(Dictionary<string, object> update_value)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "OnDuplicate", Internal_API.CallKind.ClassFunction, m_classData, update_value);
            }
            public QueryBuilder Having(string condition)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Having", Internal_API.CallKind.ClassFunction, m_classData, condition);
            }
            public QueryBuilder Distinct()
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Distinct", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public QueryBuilder Offset(int offset)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Offset", Internal_API.CallKind.ClassFunction, m_classData, offset);
            }
            public QueryBuilder Union(string query, bool all)
            {
                return Internal_API.Invoker.CallNative<QueryBuilder>("QueryBuilder", "Union", Internal_API.CallKind.ClassFunction, m_classData, query, all);
            }
            public void Execute(Action<string,object[]> callback)
            {
                Internal_API.Invoker.CallNative("QueryBuilder", "Execute", Internal_API.CallKind.ClassFunction, m_classData, callback);
            }
        }
    }
}