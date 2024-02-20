# SetTimeout

Calls the specified function after the set delay

### Syntax

```lua
SetTimeout(delay --[[ number ]], cb --[[ function ]])
```

### Example

```lua
events:on("OnPluginStart", function()
    SetTimeout(5000, function()
        print("This was called after 5 seconds from the plugin start :D")
    end)
end)
```