# GetPlayer

Returns the player object from playerid

### Syntax

```lua
@returns Player Object
GetPlayer(playerid --[[ number ]])
```

### Example

```lua
events:on("OnRoundStart", function(timelimit, fraglimit, objective)
    local player = GetPlayer(5)
    if not player then return end
    player:Kill()
end)
```
