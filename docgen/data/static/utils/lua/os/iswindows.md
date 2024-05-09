# IsWindows

Returns if the server is on Windows or not.

### Syntax

```lua
@returns boolean as number
IsWindows()
```

### Example

```lua
events:on("OnPluginStart", function()
    if IsWindows() == 1 then print("Server is currently running on Windows") end
end)
```
