#include <scripting/core.h>

#include <server/commands/manager.h>

LoadScriptingComponent(commands, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Commands");

    ADD_CLASS_FUNCTION("Commands", "Commands", [](FunctionContext* context, ClassData* data) -> void {});

    ADD_CLASS_FUNCTION("Commands", "Register", [](FunctionContext* context, ClassData* data) -> void {
        std::string commandName = context->GetArgumentOr<std::string>(0, "");
        if(commandName == "") return;

        EValue func = context->GetArgument<EValue>(1);
        if(!func.isFunction()) return;

        EValue* funcPtr = new EValue(func);
        if (funcPtr->m_ref == func.m_ref && func.getContext()->GetKind() == ContextKinds::Lua) func.MarkNoFree();

        Command* command = new Command(FetchPluginName(context->GetPluginContext()), funcPtr, commandName);
        g_commandsManager.RegisterCommand(command->GetPluginName(), commandName, command);
    });

    ADD_CLASS_FUNCTION("Commands", "Unregister", [](FunctionContext* context, ClassData* data) -> void {
        std::string commandName = context->GetArgumentOr<std::string>(0, "");
        if(commandName == "") return;
        
        g_commandsManager.UnregisterCommand(commandName);
    });

    ADD_CLASS_FUNCTION("Commands", "RegisterRawAlias", [](FunctionContext* context, ClassData* data) -> void {
        std::string commandName = context->GetArgumentOr<std::string>(0, "");
        if(commandName == "") return;

        std::string aliasName = context->GetArgumentOr<std::string>(1, "");
        if(aliasName == "") return;
        
        Command* command = g_commandsManager.FetchCommand(commandName);
        if (!command) return;

        g_commandsManager.RegisterCommand(command->GetPluginName(), aliasName, command, true);
    });

    ADD_CLASS_FUNCTION("Commands", "RegisterAlias", [](FunctionContext* context, ClassData* data) -> void {
        std::string commandName = context->GetArgumentOr<std::string>(0, "");
        if(commandName == "") return;

        std::string aliasName = context->GetArgumentOr<std::string>(1, "");
        if(aliasName == "") return;
        
        Command* command = g_commandsManager.FetchCommand(commandName);
        if (!command) return;

        g_commandsManager.RegisterCommand(command->GetPluginName(), aliasName, command);
    });

    ADD_CLASS_FUNCTION("Commands", "UnregisterAlias", [](FunctionContext* context, ClassData* data) -> void {
        std::string commandName = context->GetArgumentOr<std::string>(0, "");
        if(commandName == "") return;

        g_commandsManager.UnregisterCommand(commandName);
    });

    ADD_CLASS_FUNCTION("Commands", "GetAllCommands", [](FunctionContext* context, ClassData* data) -> void {
        std::vector<std::string> cmdsList;

        auto cmds = g_commandsManager.GetCommands();
        for (auto it = cmds.begin(); it != cmds.end(); ++it)
            cmdsList.push_back(it->first);

        context->SetReturn(cmdsList);
    });

    ADD_CLASS_FUNCTION("Commands", "GetCommands", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(g_commandsManager.FetchCommandsByPlugin(FetchPluginName(context->GetPluginContext())));
    });
})