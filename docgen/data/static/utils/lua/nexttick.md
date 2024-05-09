# NextTick

Calls the specified function on the next server tick.

### Syntax

```lua
NextTick(cb --[[ function ]])
```

### Example

```lua
events:on("OnPluginStart", function()
    NextTick(function()
        print("Called on the first server tick!")
    end)
end)
```