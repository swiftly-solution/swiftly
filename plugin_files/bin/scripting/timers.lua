function SetTimeout(delay, callback)
    if type(delay) ~= "number" then
        return print("The delay needs to be a number.")
    end
    if type(callback) ~= "function" then
        return print("The callback needs to be a function.")
    end

    local call = GetTime() + delay

    local settimeoutEvent = nil
    settimeoutEvent = AddEventHandler("OnGameTick", function()
        if call - GetTime() <= 0 then
            if type(callback) == "function" then
                local status, err = pcall(callback)
                if not status then
                    print("An error has been occured while trying to execute SetTimeout.\nError: "..err)
                end
            end
            RemoveEventHandler(settimeoutEvent)
        end
    end)
end

local timerIds = 50
local timersTable = {}

function SetTimer(delay, callback)
    if type(delay) ~= "number" then
        return print("The delay needs to be a number.")
    end
    if type(callback) ~= "function" then
        return print("The callback needs to be a function.")
    end

    timerIds = timerIds + 1

    timersTable[timerIds] = {
        id = timerIds,
        callback = callback,
        timeoutFunction = function()
            if timersTable[timerIds] then
                timersTable[timerIds].callback()
                SetTimeout(delay, timersTable[timerIds].timeoutFunction)
            end
        end
    }

    SetTimeout(delay, timersTable[timerIds].timeoutFunction)

    return timerIds
end

function StopTimer(timerId)
    if type(timerId) ~= "number" then
        return print("The Timer ID needs to be a number.")
    end

    if not timersTable[timerId] then
        return print("Invalid Timer ID.")
    end

    timersTable[timerId] = nil
end

function NextTick(callback)
    if type(callback) ~= "function" then
        return print("The callback needs to be a function.")
    end

    local nexttickEvent = nil
    nexttickEvent = AddEventHandler("OnGameTick", function()
        if type(callback) == "function" then
            local status, err = pcall(callback)
            if not status then
                print("An error has been occured while trying to execute NextTick.\nError: "..err)
            end
        end

        RemoveEventHandler(nexttickEvent)
    end)
end