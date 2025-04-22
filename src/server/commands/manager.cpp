#include "manager.h"

#include <server/configuration/configuration.h>
#include <server/player/manager.h>

#include <utils/utils.h>
#include <utils/common.h>
#include <public/tier1/strtools.h>

static void commandsCallback(const CCommandContext& context, const CCommand& args);
std::map<std::string, ConCommand*> conCommandCreated;

std::set<std::string> commandPrefixes;
std::set<std::string> silentCommandPrefixes;

SH_DECL_EXTERN3_void(ICvar, DispatchConCommand, SH_NOATTRIB, 0, ConCommandRef, const CCommandContext&, const CCommand&);

void CommandsManager::Initialize()
{
    SH_ADD_HOOK_MEMFUNC(ICvar, DispatchConCommand, g_pCVar, this, &CommandsManager::DispatchConCommand, false);
}

void CommandsManager::Shutdown()
{
    SH_REMOVE_HOOK_MEMFUNC(ICvar, DispatchConCommand, g_pCVar, this, &CommandsManager::DispatchConCommand, false);
}

bool OnClientCommand(int playerid, std::string command);
bool OnClientChat(int playerid, std::string text, bool teamonly);

void CommandsManager::DispatchConCommand(ConCommandRef cmd, const CCommandContext& ctx, const CCommand& args)
{
    CPlayerSlot slot = ctx.GetPlayerSlot();

    if (slot.Get() != -1)
    {
        if (!OnClientCommand(slot.Get(), args.GetCommandString())) RETURN_META(MRES_SUPERCEDE);

        std::string command = args.Arg(0);
        if (command == "say" || command == "say_team")
        {
            Player* player = g_playerManager.GetPlayer(slot);
            if (!player) return;

            void* controller = player->GetController();

            bool teamonly = (command == "say_team");

            auto text = args[1];
            if (strlen(text) == 0) RETURN_META(MRES_SUPERCEDE);

            if (controller)
            {
                IGameEvent* pEvent = g_gameEventManager->CreateEvent("player_chat");

                if (pEvent)
                {
                    pEvent->SetBool("teamonly", teamonly);
                    pEvent->SetInt("userid", slot.Get());
                    pEvent->SetString("text", text);

                    g_gameEventManager->FireEvent(pEvent, true);
                }
            }

            int handleCommandReturn = HandleCommand(slot.Get(), text);
            if (handleCommandReturn == 2 || !OnClientChat(slot.Get(), text, teamonly)) RETURN_META(MRES_SUPERCEDE);
        }
    }
}

// @returns 1 - command is not silent
// @returns 2 - command is silent
// @returns -1 - invalid controller
// @returns 0 - is not command
int CommandsManager::HandleCommand(int playerid, std::string text)
{
    if (text == "" || text.size() == 0)
        return -1;

    Player* player = g_playerManager.GetPlayer(playerid);
    if (player == nullptr)
        return -1;

    if (commandPrefixes.size() == 0) commandPrefixes = explodeToSet(g_Config.FetchValue<std::string>("core.commandPrefixes"), " ");
    if (silentCommandPrefixes.size() == 0) silentCommandPrefixes = explodeToSet(g_Config.FetchValue<std::string>("core.commandSilentPrefixes"), " ");

    bool isCommand = false;
    bool isSilentCommand = false;
    std::string selectedPrefix = "";

    if (commandPrefixes.size() > 0) {
        for (auto it = commandPrefixes.begin(); it != commandPrefixes.end(); ++it) {
            std::string prefix = *it;
            auto strPrefix = text.substr(0, prefix.size());

            if (prefix == strPrefix) {
                isCommand = true;
                selectedPrefix = prefix;
                break;
            }
        }
    }

    if (!isCommand && silentCommandPrefixes.size() > 0) {
        for (auto it = silentCommandPrefixes.begin(); it != silentCommandPrefixes.end(); ++it) {
            std::string prefix = *it;
            auto strPrefix = text.substr(0, prefix.size());

            if (prefix == strPrefix) {
                isSilentCommand = true;
                selectedPrefix = prefix;
                break;
            }
        }
    }

    if (isCommand || isSilentCommand)
    {
        CCommand tokenizedArgs;
        tokenizedArgs.Tokenize(text.c_str());

        std::vector<std::string> cmdString = TokenizeCommand(text);
        cmdString.erase(cmdString.begin());

        if (tokenizedArgs.ArgC() < 1)
            return 0;

        std::string commandName = tokenizedArgs[0];
        if (commandName.size() < 1)
            return 0;

        commandName.erase(0, selectedPrefix.size());

        if (player->menu_renderer->HasMenuShown() && g_Config.FetchValue<std::string>("core.menu.inputMode") == "chat") {
            if (commandName == "1" || commandName == "2" || commandName == "3" || commandName == "4" ||
                commandName == "5" || commandName == "6" || commandName == "7" || commandName == "8" || commandName == "9") {
                int value = V_StringToUint32(commandName.c_str(), 1);
                if (value > player->menu_renderer->GetMenu()->GetItemsOnPage(player->menu_renderer->GetPage())) return 2;

                while (player->menu_renderer->GetSelection() != value - 1) {
                    player->menu_renderer->MoveSelection();
                }

                player->menu_renderer->PerformMenuAction(g_Config.FetchValue<std::string>("core.menu.buttons.use"));
                return 2;
            }
        }

        Command* cmd = FetchCommand(commandName);
        if (cmd == nullptr)
            return 0;

        try {
            cmd->Execute(playerid, cmdString, isSilentCommand, selectedPrefix);
        }
        catch (std::exception& e) {
            PLUGIN_PRINTF("Commands Manager", "An error has occured while trying to execute command '%s'.\n", commandName.c_str());
            PLUGIN_PRINTF("Commands Manager", "%s\n", e.what());
        }
    }

    if (isCommand)
        return 1;
    else if (isSilentCommand)
        return 2;
    else
        return 0;
}

Command* CommandsManager::FetchCommand(std::string cmd_name)
{
    if (commands.find(cmd_name) == commands.end()) return nullptr;
    return commands[cmd_name];
}

void CommandsManager::RegisterCommand(std::string plugin_name, std::string cmd, Command* command, bool registerRaw)
{
    if (!registerRaw)
    {
        if (commands.find(cmd) != commands.end())
            return;

        commands.insert({ cmd, command });
        commandAliases.insert({ cmd, {} });

        if (commandsByPlugin.find(plugin_name) == commandsByPlugin.end())
            commandsByPlugin.insert({ plugin_name, {} });

        commandsByPlugin[plugin_name].push_back(cmd);

        cmd = "sw_" + cmd;
    }

    if (conCommandCreated.find(cmd) == conCommandCreated.end())
        conCommandCreated.insert({ cmd, new ConCommand(cmd.c_str(), commandsCallback, "Swiftly Command", (1 << 25) | (1 << 0) | (1 << 24)) });
}

void CommandsManager::UnregisterCommand(std::string cmd)
{
    if (commands.find(cmd) == commands.end())
        return;

    Command* command = FetchCommand(cmd);
    std::string plugin = command->GetPluginName();

    delete command;
    commands.erase(cmd);

    std::vector<std::string> aliases = commandAliases.at(cmd);
    for (std::string alias : aliases)
        UnregisterCommand(alias);

    commandAliases.erase(cmd);

    auto cmdIterator = std::find(commandsByPlugin[plugin].begin(), commandsByPlugin[plugin].end(), cmd);
    if (cmdIterator != commandsByPlugin[plugin].end())
        commandsByPlugin[plugin].erase(cmdIterator);

    if (conCommandCreated.find(cmd) != conCommandCreated.end()) {
        delete conCommandCreated.at(cmd);
        conCommandCreated.erase(cmd);
    }
    if (conCommandCreated.find("sw_" + cmd) != conCommandCreated.end()) {
        delete conCommandCreated.at("sw_" + cmd);
        conCommandCreated.erase("sw_" + cmd);
    }
}

std::vector<std::string> CommandsManager::FetchCommandsByPlugin(std::string plugin_name)
{
    if (commandsByPlugin.find(plugin_name) == commandsByPlugin.end())
        return {};
    return commandsByPlugin.at(plugin_name);
}

std::map<std::string, Command*> CommandsManager::GetCommands()
{
    return commands;
}

static void commandsCallback(const CCommandContext& context, const CCommand& args)
{
    CCommand tokenizedArgs;
    tokenizedArgs.Tokenize(args.GetCommandString());

    std::string commandName = (starts_with(tokenizedArgs[0], "sw_") ? (tokenizedArgs[0] + 3) : tokenizedArgs[0]);

    std::vector<std::string> argsplit = TokenizeCommand(args.GetCommandString());
    argsplit.erase(argsplit.begin());

    if (g_commandsManager.FetchCommand(commandName) == nullptr) return;

    Command* command = g_commandsManager.FetchCommand(commandName);
    if (!command) return;

    command->Execute(context.GetPlayerSlot().Get(), argsplit, true, "sw_");
}

std::string GenerateCommandDefaultPrefix() {
    if (commandPrefixes.size() == 0 && silentCommandPrefixes.size() == 0) return "sw_";

    if (commandPrefixes.size() == 0) return (*silentCommandPrefixes.begin());
    else return (*commandPrefixes.begin());
}