# CreateThread

Creates a new thread.

### Syntax

```lua
CreateThread(callback --[[ function ]])
```

### Example

```lua
CreateThread(function()
    print("This message is sent from another world (thread)")
end)
```