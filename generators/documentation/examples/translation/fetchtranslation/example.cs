Commands.Register("credits", (int playerid, string[] arguments, bool silent, int count, string prefix) => {
    var player = Generic.GetPlayer(playerid);
    if(!player || !player.IsValid()) then return;
    var credits = 50;
    player.SendMsg(MessageType.Chat, FetchTranslation("first_plugin.credits", playerid).replace("{credits}", $"{credits}"));
});

/*
File: addons/swiftly/translations/translation.first_plugin.json

{
    "credits": {
        "en": "Your current credits are {credits}!",
        "ro": "In momentul asta ai {credits} credite!"
    }
}
*/