#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/error/en.h>

class LuaConfigClass
{
public:
    LuaConfigClass() {}
};

void SetupLuaConfiguration(luacpp::LuaState *state, Plugin *plugin)
{
    auto configClass = state->CreateClass<LuaConfigClass>("Configuration").DefConstructor();

    configClass.DefMember("Exists", [](LuaConfigClass *base, const char *key) -> bool
                          { return scripting_Configuration_Exists(key); })
        .DefMember("FetchArraySize", [](LuaConfigClass *base, const char *key) -> uint32
                   { return scripting_Configuration_FetchArraySize(key); })
        .DefMember("Fetch", [state](LuaConfigClass *base, const char *key) -> luacpp::LuaObject
                   { 
                        const char *data = scripting_Configuration_Fetch(key);

                        rapidjson::Document document;
                        document.Parse(data);

                        if (document.HasParseError()) {
                            PRINTF("Runtime", "An error has occured while reading configuration from memory.\nError: %s\n", GetParseError_En(document.GetParseError()));
                            return state->CreateNil();
                        }

                        if (document["value"].IsString())
                            return state->CreateString(document["value"].GetString());
                        else if (document["value"].IsInt())
                            return state->CreateInteger(document["value"].GetInt());
                        else if (document["value"].IsInt64())
                            return state->CreateInteger(document["value"].GetInt64());
                        else if (document["value"].IsUint())
                            return state->CreateInteger(document["value"].GetUint());
                        else if (document["value"].IsUint64())
                            return state->CreateInteger(document["value"].GetUint64());
                        else if (document["value"].IsBool())
                            return state->CreateInteger(document["value"].GetBool());
                        else if (document["value"].IsFloat())
                            return state->CreateNumber(document["value"].GetFloat());
                        else if (document["value"].IsDouble())
                            return state->CreateNumber(document["value"].GetDouble());
                        else
                            return state->CreateNil(); });

    state->DoString("config = Configuration()");

    PRINT("Scripting - Lua", "Configuration loaded.\n");
}