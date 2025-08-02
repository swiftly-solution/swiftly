AddEventHandler("OnUserMessageSend", function(event, um, isreliable)
    local msgid = um:GetMessageID()

    if msgid == 418 or msgid == 411 then
        return EventResult.Stop
    end
end)
