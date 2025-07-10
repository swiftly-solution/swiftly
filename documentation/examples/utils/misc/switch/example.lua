local result = switch("hello", {
    hello = function() return "world" end,
    goodbye = "farewell",
    default = function() return "unknown" end
})

print(result)
