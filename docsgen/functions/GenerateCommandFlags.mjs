import { markdownTable } from "../utils/markdownTable.mjs"

const flagDesc = {
    "linked_concommand": "Linked concommand",
    "developmentonly": "Development only",
    "gamedll": "Game DLL",
    "clientdll": "Client DLL",
    "hidden": "Hidden",
    "protected": "Protected",
    "sponly": "Singleplayer only",
    "archive": "Archive",
    "notify": "Notify",
    "userinfo": "User info",
    "reference": "Reference",
    "unlogged": "Unlogged",
    "initial_setvalue": "Initial setvalue",
    "replicated": "Replicated",
    "cheat": "Cheat",
    "per_user": "Per user",
    "demo": "Demo",
    "dontrecord": "Don't record",
    "release": "Release",
    "menubar_item": "Menubar item",
    "commandline_enforced": "CLI enforced",
    "notconnected": "Not connected",
    "vconsole_fuzzy_matching": "VConsole fuzzy matching",
    "server_can_execute": "Server can execute",
    "client_can_execute": "Client can execute",
    "server_cannot_query": "Server cannot query",
    "vconsole_set_focus": "VConsole set focus",
    "clientcmd_can_execute": "Clientcmd can execute",
    "execute_per_tick": "Execute per tick",
    "missing1": "Missing 1",
    "missing2": "Missing 2",
    "defensive": "Defensive",
}

export default function GenerateCommandFlags(pageData) {
    const flags = pageData.flags

    const commandFlags = [
        ["Flag", "Description"]
    ]

    for (const flag of flags) {
        if (!flagDesc[flag]) continue;
        commandFlags.push([
            `\`${flag}\``,
            `\`${flagDesc[flag]}\``
        ])
    }

    return markdownTable(commandFlags, {
        align: ['c', 'c'],
    })
}