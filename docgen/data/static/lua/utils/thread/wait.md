# Wait

Waits for a specified amount of time

### Syntax

```lua
Wait(ms --[[ number ]])
```

### Example

```lua
CreateThread(function()
    print("Message #1: "..GetTime())
    Wait(1000)
    print("Message #2: "..GetTime())
end)
```