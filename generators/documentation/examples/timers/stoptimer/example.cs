using SwiftlyS2.API.Scripting;

Commands.Register("startstop", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    var timer = Generic.SetTimer(1000, () => {});
    Generic.SetTimeout(5000, () => {
        Generic.StopTimer(timer);
    });
});