# IsLinux

Returns if the server is on Linux or not.

### Syntax

```lua
@returns boolean as number
IsLinux()
```

### Example

```lua
events:on("OnPluginStart", function()
    if IsLinux() == 1 then print("Server is currently running on Linux") end
end)
```
