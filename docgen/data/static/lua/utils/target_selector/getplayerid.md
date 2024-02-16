# GetPlayerId

Returns a player ID for a provided string.

### Syntax

```lua
@returns -1 => Player couldn't be found on server.
@returns number
GetPlayerId(str --[[ string ]], matchbots --[[ boolean ]])
```

:::note
GetPlayerId supports partial names, SteamID 64 and Player ID which can be found in `sw_status` command when you run it in client/server console.
:::

### Example

```lua
events:on("OnRoundStart", function(timelimit, fraglimit, objective)
    local playerid = GetPlayerId("76561199099354478");
    if playerid == -1 then return print("Player with SteamID64 '76561199099354478' couldn't be found on server to kill.") end

    local player = GetPlayer(playerid)
    if not player then return end
    player:Kill()
end)
```
