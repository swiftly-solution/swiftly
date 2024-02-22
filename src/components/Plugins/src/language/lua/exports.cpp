#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

#include <vector>
#include <map>
#include <string>
#include <any>

std::string SerializeExportData(std::vector<std::any> data);
std::any DeserializeExpData(const char *jsonData);

class GetExportsClass
{
public:
    std::string plugin_name;

    GetExportsClass(const char *name) : plugin_name(name) {}
};

void SetupLuaExports(luacpp::LuaState *state, Plugin *plugin)
{
    if (state->Get("expFuncCache").GetType() == LUA_TNIL)
        state->CreateTable("expFuncCache");

    state->CreateFunction([plugin, state](const char *export_name, luacpp::LuaObject func) -> void
                          {
                              if (func.GetType() != LUA_TFUNCTION)
                              {
                                  PRINT("Runtime", "Export second argument needs to be a function.\n");
                                  return;
                              }

                              luacpp::LuaTable tbl = state->GetTable("expFuncCache");
                              tbl.Set(export_name, func);
                              scripting_Exports_Register(plugin->GetName().c_str(), export_name, reinterpret_cast<void*>(&func)); },
                          "export");

    state->CreateFunction([plugin](const char *export_name) -> void
                          { scripting_Exports_Unregister(plugin->GetName().c_str(), export_name); },
                          "UnregisterExport");

    auto exportsClass = state->CreateClass<GetExportsClass>("GetExports").DefConstructor<const char *>();

    exportsClass.DefMember("CallExport", [plugin, state](GetExportsClass *base) -> luacpp::LuaObject
                           {
                                lua_State *st = plugin->GetLuaRawState();
                                int n = lua_gettop(st);
                                std::vector<std::any> args;
                                if ((new luacpp::LuaObject(st, 2))->GetType() != LUA_TSTRING) {
                                        PRINTF("CallExport", "The key needs to be a string.\n");
                                        return state->CreateNil();
                                    }
                                const char* export_name = (new luacpp::LuaObject(st, 2))->ToString();
                                for (int i = 3; i <= n; i++) {
                                        luacpp::LuaObject arg(st, i);
                                        if (arg.GetType() == LUA_TNIL) args.push_back(nullptr);
                                        else if (arg.GetType() == LUA_TSTRING) args.push_back(arg.ToString());
                                        else if (arg.GetType() == LUA_TBOOLEAN) args.push_back(arg.ToBool());
                                        else if (arg.GetType() == LUA_TNUMBER) {
                                            lua_rawgeti(st, LUA_REGISTRYINDEX, arg.GetRefIndex());
                                            if (lua_isinteger(st, -1) == 1) args.push_back(arg.ToInteger());
                                            else args.push_back(arg.ToNumber());
                                            lua_pop(st, 1);
                                        } else args.push_back(nullptr);
                                } 
                                std::string json = SerializeExportData(args);
                                std::string ret_data = scripting_Exports_Call(base->plugin_name.c_str(), export_name, json.c_str());

                                std::any val = DeserializeExpData(ret_data.c_str());

                                if(val.type() == typeid(int)) return state->CreateInteger(std::any_cast<int>(val));
                                else if(val.type() == typeid(int64_t)) return state->CreateInteger(std::any_cast<int64_t>(val));
                                else if(val.type() == typeid(unsigned int)) return state->CreateInteger(std::any_cast<unsigned int>(val));
                                else if(val.type() == typeid(uint64_t)) return state->CreateInteger(std::any_cast<uint64_t>(val));
                                else if(val.type() == typeid(const char*)) return state->CreateString(std::any_cast<const char*>(val));
                                else if(val.type() == typeid(std::string)) return state->CreateString(std::any_cast<std::string>(val).c_str());
                                else if(val.type() == typeid(bool)) return state->CreateInteger(std::any_cast<bool>(val) == true ? 1 : 0);
                                else if(val.type() == typeid(float)) return state->CreateNumber(std::any_cast<float>(val));
                                else if(val.type() == typeid(double)) return state->CreateNumber(std::any_cast<double>(val));
                                else return state->CreateNil(); });

    state->DoString("exports = setmetatable({}, { __newindex = function(tbl, key, val) print(\"[Swiftly] You can't create a new index on this table.\") end, __index = function(tbl, key) local exp = GetExports(key); return exp; end })");
}