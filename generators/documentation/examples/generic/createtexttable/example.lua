commands:Register("table", function(playerid, args, argsCount, silent, prefix)
    local tbl = CreateTextTable({
        { "Admin",  "Flag", "Group" },
        { "blu",    "z",    "root" },
        { "skuzzi", "b",    "helper" },
        { "m3ntor", "a",    "moderator" }
    })
    print(tbl)
end)
