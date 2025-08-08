using SwiftlyS2.API.Scripting;

Events.AddEventHandler("OnUserMessageSend", (Events.Event @e, UserMessages.UserMessage um, bool isreliable) => {
    var msgid = um.GetMessageID();

    if(msgid == 418 || msgid == 411) return EventResult.Stop;
});