commands.Register("table", (playerid, args, argc, silent, prefix) => {
    let tbl = CreateTextTable([
        ["Admin", "Flag", "Group"],
        ["blu", "z", "root"],
        ["skuzzi", "b", "helper"],
        ["m3ntor", "a", "moderator"]
    ]);
    console.log(tbl);
});