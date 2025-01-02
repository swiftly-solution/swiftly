function SetTimeout(delay, callback)
    if type(delay) ~= "number" then
        return print("The delay needs to be a number.")
    end
    if type(callback) ~= "function" then
        return print("The callback needs to be a function.")
    end

    AddTimeout(delay, callback)
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

    local timerId = timerIds

    timersTable[timerId] = {
        id = timerId,
        callback = callback,
        timeoutFunction = function()
            if timersTable[timerId] then
                timersTable[timerId].callback()
                if timersTable[timerId] then
                    SetTimeout(delay, timersTable[timerId].timeoutFunction)
                end
            end
        end
    }

    SetTimeout(delay, timersTable[timerId].timeoutFunction)

    return timerId
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

    SetTimeout(1, callback)
end
