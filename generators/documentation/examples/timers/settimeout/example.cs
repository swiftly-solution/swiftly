using SwiftlyS2.API.Scripting;

Commands.Register("settimeout", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Generic.SetTimeout(3000, () => {
        Console.WriteLine("3 seconds elapsed!");
    });
});