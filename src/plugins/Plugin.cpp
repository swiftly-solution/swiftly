#include "Plugin.h"
#include "../tools/crashreporter/CallStack.h"
#include "core/scripting.h"
#include "../extensions/ExtensionManager.h"
#include "../server/commands/CommandsManager.h"

extern "C"
{
    LUALIB_API int luaopen_rapidjson(lua_State* L);
}

void SetupScriptingEnvironment(Plugin* plugin, EContext* state);

Plugin::Plugin(std::string m_name, PluginKind_t m_kind)
{
    this->name = m_name;
    this->kind = m_kind;
}

Plugin::~Plugin() {
}

std::string Plugin::GetName()
{
    return this->name;
}

PluginKind_t Plugin::GetKind()
{
    return this->kind;
}

PluginState_t Plugin::GetPluginState()
{
    return this->state;
}

void Plugin::SetPluginState(PluginState_t state)
{
    this->state = state;
}

std::string Plugin::GetLoadError()
{
    return this->loadError;
}

void Plugin::SetLoadError(std::string error)
{
    this->loadError = error;
}

EventResult Plugin::TriggerEvent(std::string invokedBy, std::string eventName, std::string eventPayload, PluginEvent* event)
{
    if (this->GetPluginState() == PluginState_t::Stopped && eventName != "OnPluginStart" && eventName != "OnAllPluginsLoaded")
        return EventResult::Continue;

    if (!this->globalEventHandler)
        return EventResult::Continue;

    if (this->eventHandlers.find(eventName) == this->eventHandlers.end())
        return EventResult::Continue;

    if (eventName != "OnGameTick") REGISTER_CALLSTACK(this->GetName(), string_format("Event: %s(invokedBy=\"%s\",payload=\"%s\",event=%p)", eventName.c_str(), invokedBy.c_str(), eventPayload.c_str(), (void*)event));
    PERF_RECORD(string_format("event:%s:%s", invokedBy.c_str(), eventName.c_str()), this->GetName());

    int res = (int)EventResult::Continue;
    try
    {
        EValue func = *this->globalEventHandler;
        auto result = func(event, invokedBy, eventName, eventPayload);

        if (!result.isNumber())
            return EventResult::Continue;

        res = result.cast<int>();
        if (res < (int)EventResult::Continue || res >(int)EventResult::Handled)
            return EventResult::Continue;
    }
    catch (EException& e)
    {
        PRINTF("An error has occured: %s\n", e.what());
    }

    return (EventResult)res;
}

int64_t Plugin::GetMemoryUsage()
{
    if (this->GetPluginState() == PluginState_t::Stopped) return 0;
    return ctx->GetMemoryUsage();
}

std::string Plugin::GetAuthor()
{
    if (this->GetPluginState() == PluginState_t::Stopped)
        return "";

    auto func = EValue::getGlobal(ctx, "GetPluginAuthor");
    return func().cast<std::string>();
}

std::string Plugin::GetWebsite()
{
    if (this->GetPluginState() == PluginState_t::Stopped)
        return "";

    auto func = EValue::getGlobal(ctx, "GetPluginWebsite");
    return func().cast<std::string>();
}

std::string Plugin::GetVersion()
{
    if (this->GetPluginState() == PluginState_t::Stopped)
        return "";

    auto func = EValue::getGlobal(ctx, "GetPluginVersion");
    return func().cast<std::string>();
}

std::string Plugin::GetPlName()
{
    if (this->GetPluginState() == PluginState_t::Stopped)
        return "";

    auto func = EValue::getGlobal(ctx, "GetPluginName");
    return func().cast<std::string>();
}

void Plugin::RegisterEventHandler(void* functionPtr)
{
    EValue* handlerRef = (EValue*)functionPtr;
    if (!handlerRef->isFunction())
        return;

    this->globalEventHandler = handlerRef;
}

void Plugin::RegisterEventHandling(std::string eventName)
{
    if (this->eventHandlers.find(eventName) == this->eventHandlers.end()) this->eventHandlers.insert(eventName);
    eventManager->RegisterGameEventListen(eventName);
}

void Plugin::UnregisterEventHandling(std::string eventName)
{
    auto it = this->eventHandlers.find(eventName);
    if (it != this->eventHandlers.end()) this->eventHandlers.erase(it);
}

void Plugin::ExecuteCommand(void* functionPtr, std::string name, int slot, std::vector<std::string> args, bool silent, std::string prefix)
{
    PERF_RECORD(string_format("command:%s", name.c_str()), this->GetName())

    if (functionPtr == nullptr)
        return;

    EValue* commandRef = (EValue*)functionPtr;

    if (!commandRef->isFunction())
        return;

    try
    {
        EValue command = *commandRef;
        int argc = args.size();
        command(slot, args, argc, silent, prefix);
    }
    catch (EException& e)
    {
        PRINTF("An error has occured while executing command '%s'.\n", name.c_str());
        PRINTF("%s\n", e.what());
    }
}

bool Plugin::LoadScriptingEnvironment()
{
    this->SetLoadError("");
    
    ctx = new EContext(GetKind() == PluginKind_t::Lua ? ContextKinds::Lua : ContextKinds::JavaScript);

    SetupScriptingEnvironment(this, ctx);

    // for (Extension* ext : extManager->GetExtensionsList())
    //     if (ext->IsLoaded()) {
    //         std::string error = "";
    //         if (!ext->GetAPI()->OnPluginLoad(this->GetName(), this->ctx, this->GetKind(), error)) {
    //             PRINTF("Failed to load plugin '%s'.\n", this->GetName().c_str());
    //             PRINTF("Error: %s.\n", error.c_str());
    //             this->SetLoadError(error);
    //             return false;
    //         }
    //     }

    std::string fileExt = GetKind() == PluginKind_t::Lua ? ".lua" : ".js";
    int loadStatus = ctx->RunFile(GeneratePath("addons/swiftly/bin/scripting/events" + fileExt));

    if (loadStatus != 0)
    {
        std::string error = EException(ctx->GetState(), ctx->GetKind(), loadStatus).what();
        PRINTF("Failed to load plugin file '%s%s'.\n", "addons/swiftly/bin/scripting/events", fileExt.c_str());
        PRINTF("Error: %s\n", error.c_str());

        this->SetLoadError(error);
        return false;
    }

    std::vector<std::string> scriptingFiles = Files::FetchFileNames("addons/swiftly/bin/scripting");
    for (std::string file : scriptingFiles)
    {
        if (ends_with(file, fileExt))
        {
            if (file == "addons/swiftly/bin/scripting/events" + fileExt)
                continue;

            int loadStatus = ctx->RunFile(GeneratePath(file));

            if (loadStatus != 0)
            {
                std::string error = EException(ctx->GetState(), ctx->GetKind(), loadStatus).what();
                PRINTF("Failed to load plugin file '%s'.\n", file.c_str());
                PRINTF("Error: %s\n", error.c_str());

                this->SetLoadError(error);
                return false;
            }
        }
    }

    GetGlobalNamespace(ctx).addConstant("AddGlobalEvents", nullptr);

    std::vector<std::string> files = Files::FetchFileNames(g_pluginManager->GetPluginBasePath(this->GetName()) + "/" + this->GetName());
    for (std::string file : files)
    {
        if (ends_with(file, fileExt))
        {
            int loadStatus = ctx->RunFile(GeneratePath(file));

            if (loadStatus != 0)
            {
                std::string error = EException(ctx->GetState(), ctx->GetKind(), loadStatus).what();
                PRINTF("Failed to load plugin file '%s'.\n", file.c_str());
                PRINTF("Error: %s\n", error.c_str());

                this->SetLoadError(error);
                return false;
            }
        }
    }

    return true;
}

void Plugin::DestroyScriptingEnvironment()
{
    std::vector<std::string> commandNames = g_commandsManager->FetchCommandsByPlugin(this->GetName());
    for (std::string command : commandNames)
        g_commandsManager->UnregisterCommand(command);

    if (this->globalEventHandler)
        delete this->globalEventHandler;

    this->eventHandlers.clear();
    delete this->ctx;
}

bool Plugin::ExecuteStart()
{
    auto PluginAuthor = EValue::getGlobal(ctx, "GetPluginAuthor");
    if (!PluginAuthor.isFunction())
    {
        PRINTF("Failed to load plugin '%s'.\n", this->GetName().c_str());
        PRINT("Error: Mandatory function 'GetPluginAuthor' is not defined.\n");
        this->SetLoadError("Mandatory function 'GetPluginAuthor' is not defined.");
        return false;
    }

    auto PluginWebsite = EValue::getGlobal(ctx, "GetPluginWebsite");
    if (!PluginWebsite.isFunction())
    {
        PRINTF("Failed to load plugin '%s'.\n", this->GetName().c_str());
        PRINT("Error: Mandatory function 'GetPluginWebsite' is not defined.\n");
        this->SetLoadError("Mandatory function 'GetPluginWebsite' is not defined.");
        return false;
    }

    auto PluginVersion = EValue::getGlobal(ctx, "GetPluginVersion");
    if (!PluginVersion.isFunction())
    {
        PRINTF("Failed to load plugin '%s'.\n", this->GetName().c_str());
        PRINT("Error: Mandatory function 'GetPluginVersion' is not defined.\n");
        this->SetLoadError("Mandatory function 'GetPluginVersion' is not defined.");
        return false;
    }

    auto PluginName = EValue::getGlobal(ctx, "GetPluginName");
    if (!PluginName.isFunction())
    {
        PRINTF("Failed to load plugin '%s'.\n", this->GetName().c_str());
        PRINT("Error: Mandatory function 'GetPluginName' is not defined.\n");
        this->SetLoadError("Mandatory function 'GetPluginName' is not defined.");
        return false;
    }

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    TriggerEvent("core", "OnPluginStart", encoders::msgpack::SerializeToString({}), event);
    delete event;

    return true;
}

bool Plugin::ExecuteStop()
{
    for (Extension* ext : extManager->GetExtensionsList())
        if (ext->IsLoaded()) {
            std::string error = "";
            if (!ext->GetAPI()->OnPluginUnload(this->GetName(), this->ctx, this->GetKind(), error)) {
                PRINTF("Failed to unload plugin '%s'.\n", this->GetName().c_str());
                PRINTF("Error: %s.\n", error.c_str());
                return false;
            }
        }

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    TriggerEvent("core", "OnPluginStop", encoders::msgpack::SerializeToString({}), event);
    delete event;

    return true;
}

std::vector<EValue*> emptyTable;

EValue SerializeData(std::any data, EContext* state)
{
    std::any value = data;

    if (!value.has_value())
        return EValue(state);

    try
    {
        if (value.type() == typeid(const char*)) {
            auto val = std::any_cast<const char*>(value);
            if (val == nullptr) return EValue(state, std::string(""));
            return EValue(state, std::string(val));
        }
        else if (value.type() == typeid(char*)) {
            auto val = std::any_cast<char*>(value);
            if (val == nullptr) return EValue(state, std::string(""));
            return EValue(state, std::string(val));
        }
        else if (value.type() == typeid(std::string)) {
            std::string val = std::any_cast<std::string>(value);
            if (starts_with(val, "JSON⇚") && ends_with(val, "⇛")) {
                std::string json = explode(explode(val, "⇚")[1], "⇛")[0];

                if(state->GetKind() == ContextKinds::Lua) {
                    EValue rapidJsonTable = EValue::getGlobal(state, "json");
                    if (!rapidJsonTable["decode"].isFunction())
                        return EValue(state, emptyTable);

                    EValue decodedResult(state);
                    try
                    {
                        decodedResult = rapidJsonTable["decode"](json);
                    }
                    catch (EException& e)
                    {
                        PLUGIN_PRINTF("SerializeData", "An error has occured: %s\n", e.what());
                        return EValue(state, emptyTable);
                    }

                    if (decodedResult.isNull())
                        return EValue(state, emptyTable);

                    return decodedResult;
                } else if(state->GetKind() == ContextKinds::JavaScript) {
                    return EValue(state, JS_ParseJSON((JSContext*)state->GetState(), json.c_str(), json.length(), "SerializeData"));
                } else return EValue(state);
            }
            else return EValue(state, val);
        }
        else if (value.type() == typeid(uint64))
            return EValue(state, std::any_cast<uint64>(value));
        else if (value.type() == typeid(uint32))
            return EValue(state, std::any_cast<uint32>(value));
        else if (value.type() == typeid(unsigned long))
            return EValue(state, std::any_cast<unsigned long>(value));
        else if (value.type() == typeid(uint16))
            return EValue(state, std::any_cast<uint16>(value));
        else if (value.type() == typeid(uint8))
            return EValue(state, std::any_cast<uint8>(value));
        else if (value.type() == typeid(int64))
            return EValue(state, std::any_cast<int64>(value));
        else if (value.type() == typeid(int32))
            return EValue(state, std::any_cast<int32>(value));
        else if (value.type() == typeid(long))
            return EValue(state, std::any_cast<long>(value));
        else if (value.type() == typeid(int16))
            return EValue(state, std::any_cast<int16>(value));
        else if (value.type() == typeid(int8))
            return EValue(state, std::any_cast<int8>(value));
        else if (value.type() == typeid(bool))
            return EValue(state, std::any_cast<bool>(value));
        else if (value.type() == typeid(float))
            return EValue(state, std::any_cast<float>(value));
        else if (value.type() == typeid(double))
            return EValue(state, std::any_cast<double>(value));
        else if (value.type() == typeid(Color))
            return EValue(state, std::any_cast<Color>(value));
        else if (value.type() == typeid(Vector2D))
            return EValue(state, std::any_cast<Vector2D>(value));
        else if (value.type() == typeid(Vector))
            return EValue(state, std::any_cast<Vector>(value));
        else if (value.type() == typeid(Vector4D))
            return EValue(state, std::any_cast<Vector4D>(value));
        else if (value.type() == typeid(QAngle))
            return EValue(state, std::any_cast<QAngle>(value));
        else if (value.type() == typeid(std::nullptr_t))
            return EValue(state);
        else if (value.type() == typeid(std::vector<std::string>))
        {
            if(state->GetKind() == ContextKinds::Lua) {
                std::vector<std::string> tmpval = std::any_cast<std::vector<std::string>>(value);
                std::string tbl = tmpval[0];
    
                EValue load = EValue::getGlobal(state, "load");
                try
                {
                    EValue loadReturnValue = load(tbl);
                    if (!loadReturnValue.isFunction())
                        return EValue(state, emptyTable);
    
                    EValue loadFuncRetVal = loadReturnValue();
                    if (!loadFuncRetVal.isTable())
                        return EValue(state, emptyTable);
    
                    return loadFuncRetVal;
                }
                catch (EException& e)
                {
                    PRINTF("Exception: %s\n", e.what());
                    return EValue(state, emptyTable);
                }
            } else {
                PRINT("Cannot convert Lua table to JS object.\n");
                return EValue(state);
            }
        }
        else if (value.type() == typeid(std::vector<std::any>))
        {
            return EValue(state, std::any_cast<std::vector<std::any>>(value));
        }
        else
        {
            PRINTF("Unknown Data Type: %s\n", value.type().name());
            return EValue(state);
        }
    }
    catch (std::bad_any_cast& err)
    {
        PRINTF("Invalid casting: %s\n", err.what());
        return EValue(state);
    }

    return EValue(state);
}

std::any DeserializeData(EValue ref, EContext* state)
{
    if (ref.isBool())
        return ref.cast<bool>();
    else if (ref.isNull())
        return nullptr;
    else if (ref.isNumber())
        return ref.cast<int64_t>();
    else if (ref.isString())
        return ref.cast<std::string>();
    else if (ref.isTable())
    {
        if(state->GetKind() == ContextKinds::Lua) {
            EValue serpentDump = EValue::getGlobal(state, "serpent")["dump"];
            EValue serpentDumpReturnValue = serpentDump(ref);

            std::vector<std::string> tmptbl;
            tmptbl.push_back(serpentDumpReturnValue.cast<std::string>());

            return tmptbl;
        } else if(state->GetKind() == ContextKinds::JavaScript) {
            std::vector<std::string> tmptbl;
            return tmptbl;
        } else return nullptr;
    }
    else if (ref.isInstance<Color>())
        return ref.cast<Color>();
    else if (ref.isInstance<Vector2D>())
        return ref.cast<Vector2D>();
    else if (ref.isInstance<Vector>())
        return ref.cast<Vector>();
    else if (ref.isInstance<Vector4D>())
        return ref.cast<Vector4D>();
    else if (ref.isInstance<QAngle>())
        return ref.cast<QAngle>();
    else
        return nullptr;
}