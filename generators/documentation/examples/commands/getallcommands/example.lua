local list = commands:GetAllCommands()
for i = 1, #list do
    print(string.format("Command %d is %s", i, list[i]))
end
