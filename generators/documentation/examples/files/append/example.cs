using SwiftlyS2.API.Scripting;

Commands.Register("append", (int playerid, string[] arguments, bool silent, int count, string prefix) => {
    Files.Append("test/test.log", "Test!", true);
});