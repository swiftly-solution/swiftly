using SwiftlyS2.API.Scripting;

var list = commands.GetAllCommands();
for (int i = 0; i < list.Length; i++)
{
    Console.WriteLine($"Command {i + 1} is {list[i]}");
}