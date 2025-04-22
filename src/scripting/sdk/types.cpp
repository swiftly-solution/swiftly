#include <scripting/core.h>

#include <sdk/access.h>

void DummyGetSetType(FunctionContext* context, ClassData* data) {}

LoadScriptingComponent(sdktypes, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_FUNCTION("IsTypeClass", [](FunctionContext* context) -> void {
        auto types = g_sdk.GetSDKTypes();
        context->SetReturn(types.find(context->GetArgumentOr<std::string>(0, "")) != types.end());
    });

    ADD_FUNCTION("GenerateTypeFactory", [](FunctionContext* context) -> void {
        context->SetReturn(MAKE_CLASS_INSTANCE("SDKType", { { "class_name", context->GetArgument<std::string>(0) } }));
    });

    auto types = g_sdk.GetSDKTypes();

    ADD_CLASS("SDKType");

    for (auto it = types.begin(); it != types.end(); ++it) {
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            ADD_CLASS_MEMBER("SDKType", it2->first, DummyGetSetType, DummyGetSetType);
        }
    }

    ADD_CLASS_MEMBER_PRE("SDKType", ".*", [](FunctionContext* context, ClassData* data) -> void {
        auto class_name = data->GetData<std::string>("class_name");
        std::string member_name = str_split(context->GetFunctionKey(), " ")[1];

        auto types = g_sdk.GetSDKTypes();

        if (types.find(class_name) == types.end()) {
            context->StopExecution();
            return context->SetReturn(0);
        }
        if (types[class_name].find(member_name) == types[class_name].end()) {
            context->StopExecution();
            return context->SetReturn(0);
        }

        context->StopExecution();
        context->SetReturn(types[class_name][member_name]);
    }, [](FunctionContext* context, ClassData* data) -> void {
        context->StopExecution();
        });
})