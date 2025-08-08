using SwiftlyS2.API.Scripting;

Commands.Register("testcmd", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    console.WriteLine("Hello World!");
});