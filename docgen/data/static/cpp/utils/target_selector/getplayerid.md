# GetPlayerId

Returns a player ID for a provided string.

### Syntax

```cpp
@returns -1 => Player couldn't be found on server.
@returns int
GetPlayerId(const char *str, bool matchbots = false);
```

:::note
GetPlayerId supports partial names, SteamID 64 and Player ID which can be found in `sw_status` command when you run it in client/server console. 
:::

### Example

```cpp
void OnRoundStart(long timelimit, long fraglimit, const char *objective)
{
    int playerID = GetPlayerId("76561199099354478");
    if(playerID == -1) print("Player with SteamID64 '76561199099354478' couldn't be found on server to kill.\n");

    Player* player = g_playerManager->GetPlayer(playerID);
    if(player == nullptr) return;
    player->Kill();
}
```