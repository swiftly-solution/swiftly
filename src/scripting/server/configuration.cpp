#include <scripting/core.h>
#include <utils/common.h>
#include <utils/utils.h>

#include <memory/encoders/json.h>
#include <filesystem/files/files.h>
#include <server/configuration/configuration.h>
#include <rapidjson/json.hpp>

void WriteJSONFile(std::string path, rapidjson::Value& j);

void ParseAndFillConfiguration(rapidjson::Value& initDoc, rapidjson::Value& config, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>& allocator, bool& wasEdited)
{
    for (auto it = initDoc.MemberBegin(); it != initDoc.MemberEnd(); ++it)
    {
        const char* key = it->name.GetString();
        if (!config.HasMember(key))
        {
            config.AddMember(it->name, initDoc[key], allocator);
            wasEdited = true;
        }
        else if (config[key].IsObject() && initDoc[key].IsObject())
        {
            ParseAndFillConfiguration(initDoc[key], config[key], allocator, wasEdited);
        }
    }
}

LoadScriptingComponent(configuration, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Configuration");

    ADD_CLASS_FUNCTION("Configuration", "Configuration", [](FunctionContext* context, ClassData* data) -> void {});

    ADD_CLASS_FUNCTION("Configuration", "Exists", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(false);

        std::map<std::string, std::any> config = g_Config.FetchPluginConfiguration();
        context->SetReturn(config.find(key) != config.end());
    });

    ADD_CLASS_FUNCTION("Configuration", "Reload", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        g_Config.LoadPluginConfig(key);
    });

    ADD_CLASS_FUNCTION("Configuration", "FetchArraySize", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(0);

        std::map<std::string, unsigned int> arraySizes = g_Config.FetchConfigArraySizes();

        if (arraySizes.find(key) == arraySizes.end()) return context->SetReturn(0);
    
        context->SetReturn(arraySizes[key]);
    });

    ADD_CLASS_FUNCTION("Configuration", "Fetch", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(nullptr);

        std::map<std::string, std::any> config = g_Config.FetchPluginConfiguration();
        context->SetReturn(config[key]);
    });

    ADD_CLASS_FUNCTION("Configuration", "Create", [](FunctionContext* context, ClassData* data) -> void {
        std::string configurationKey = context->GetArgumentOr<std::string>(0, "");
        if(configurationKey == "") return;

        EValue table = context->GetArgument<EValue>(1);
        EContext* L = context->GetPluginContext();
        if (!table.isTable()) return;

        rapidjson::Document doc(rapidjson::kObjectType);

        std::string jsonResult = "";
        if(L->GetKind() == ContextKinds::Lua) {
            EValue rapidJsonTable = EValue::getGlobal(L, "json");
            if (!rapidJsonTable["encode"].isFunction())
                return;
    
            EValue encodedResult(L);
            try
            {
                encodedResult = rapidJsonTable["encode"](table);
            }
            catch (EException& e)
            {
                PLUGIN_PRINTF("Configuration - Create", "An error has occured: %s\n", e.what());
                return;
            }
    
            if (encodedResult.isNull())
                return;
    
            jsonResult = encodedResult.cast<std::string>();
        } else if(L->GetKind() == ContextKinds::JavaScript) {
            jsonResult = EValue(L, JS_JSONStringify(L->GetJSState(), table.pushJS(), JS_NULL, JS_NULL)).cast<std::string>();
        }

        doc.Parse(jsonResult.c_str());
        if (Files::ExistsPath("addons/swiftly/configs/plugins/" + configurationKey + ".json"))
        {
            std::string key = replace(configurationKey, "/", ".");
            key = replace(configurationKey, "\\", ".");

            if (g_Config.HasKey(key))
            {
                rapidjson::Document configFile = encoders::json::FromString("addons/swiftly/configs/plugins/" + configurationKey + ".json", "addons/swiftly/configs/plugins/" + configurationKey + ".json");
                if (configFile.HasParseError()) return;

                bool wasEdited = false;

                ParseAndFillConfiguration(doc, configFile, configFile.GetAllocator(), wasEdited);

                if (wasEdited)
                {
                    WriteJSONFile("addons/swiftly/configs/plugins/" + configurationKey + ".json", configFile);
                    g_Config.LoadPluginConfig(configurationKey);
                }
            }
            else
                g_Config.LoadPluginConfig(configurationKey);
        }
        else
        {
            rapidjson::StringBuffer buffer;
            rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

            doc.Accept(writer);
            std::string content = buffer.GetString();

            Files::Write("addons/swiftly/configs/plugins/" + configurationKey + ".json", content, false);
            g_Config.LoadPluginConfig(configurationKey);
        }
    });

})