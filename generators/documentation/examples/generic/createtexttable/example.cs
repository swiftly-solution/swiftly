using SwiftlyS2.API.Scripting;

Commands.Register("table", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    var tbl = new string[][]
    {
        new[] { "Admin",  "Flag", "Group" },
        new[] { "blu",    "z",    "root" },
        new[] { "skuzzi", "b",    "helper" },
        new[] { "m3ntor", "a",    "moderator" }
    };

    Console.WriteLine(tbl);
});