# GetTime

Returns the UNIX Time in milliseconds.

### Syntax

```lua
@returns number
GetTime()
```

### Example

```lua
events:on("OnPluginStart", function()
    print("UNIX Time: " .. GetTime())
end)
```
