# GetOS

Returns a string with the OS name.

### Syntax

```lua
@returns string
GetOS() -- "Windows" / "Linux"
```

### Example

```lua
events:on("OnPluginStart", function()
    print(GetOS())
end)
```
