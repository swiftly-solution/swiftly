commands:Register("getbase", function(playerid, args, argsCount, silent, prefix)
    local name = files:GetBase("cfg/autoexec.cfg")
    print("Base filename: " .. name)
end)
