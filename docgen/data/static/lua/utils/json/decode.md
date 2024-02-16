# Decode

Decodes the json string into a lua table.

### Syntax

```lua
@returns table
json.decode(str --[[ string ]])
```

### Example

```lua
events:on("OnPluginStart", function()
    local tbl = json.decode("{\"test\": 46235235234, \"test2\": \"hello\"}")
    print(tbl.test2)
end)
```
