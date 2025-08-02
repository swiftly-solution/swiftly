commands.Register("credits", (playerid, args, argc, silent, prefix) => {
    let player = GetPlayer(playerid)
    if (!player || !player.IsValid()) return;
    let credits = 50
    player.SendMsg(MessageType.Chat, FetchTranslation("first_plugin.credits", playerid).replace("{credits}", String(credits)))
});

/*
Translation File: addons/swiftly/translations/translation.first_plugin.json

{
    "credits": {
        "en": "Your current credits are {credits}!",
        "ro": "In momentul asta ai {credits} credite!"
    }
}
*/
