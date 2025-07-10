AddEventHandler("OnUserMessageSend", (event, um, isreliable) => {
    let msgid = um.GetMessageID()

    if (msgid == 418 || msgid == 411) {
        return EventResult.Stop
    }
})
