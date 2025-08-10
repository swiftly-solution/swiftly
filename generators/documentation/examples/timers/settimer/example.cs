using SwiftlyS2.API.Scripting;

Commands.Register("settimer", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Generic.SetTimer(1000, () => {
        Console.WriteLine("This runs every second!");
    });
});