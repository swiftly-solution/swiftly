commands:Register("decompress", function(playerid, args, argsCount, silent, prefix)
    if files:Decompress("update.zip", "new_version/") then
        print("Decompression succeeded")
    else
        print("Decompression failed")
    end
end)
