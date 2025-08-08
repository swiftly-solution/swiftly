using SwiftlyS2.API.Scripting;

Commands.Register("nexttick", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Generic.NextTick(() => {
        Console.WriteLine("This runs at next server tick!");
    });
});