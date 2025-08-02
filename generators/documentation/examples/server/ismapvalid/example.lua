commands:Register("isvalid", function(playerid, args, argsCount, silent, prefix)
    if server:IsMapValid("de_nuke") then
        print("The map de_nuke is valid!")
    else
        print("The map de_nuke is not valid!")
    end
end)
