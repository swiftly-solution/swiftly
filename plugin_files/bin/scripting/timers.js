function LoadTimers(global) {
    let timerIds = 50
    let timersList = {}

    global.SetTimeout = (delay, callback) => {
        if(typeof delay != "number") return console.log("The delay needs to be a number.")
        if(typeof callback != "function") return console.log("The callback needs to be a function.")

        AddTimeout(delay, callback)
    }

    global.NextTick = (callback) => {
        if(typeof callback != "function") return console.log("The callback needs to be a function.")

        global.SetTimeout(1, callback)
    }

    global.StopTimer = (timerId) => {
        if (typeof timerId !== "number") {
            console.log("The Timer ID needs to be a number.");
            return;
        }
    
        if (!timersList[timerId]) {
            console.log("Invalid Timer ID.");
            return;
        }
    
        delete timersList[timerId];
    }

    global.SetTimer = (delay, callback) => {
        if(typeof delay != "number") return console.log("The delay needs to be a number.")
        if(typeof callback != "function") return console.log("The callback needs to be a function.")

        timerIds ++
        const timerId = timerIds

        timersList[timerId] = {
            id: timerId,
            callback,
            timeoutFunc: () => {
                if(timersList[timerId]) {
                    timersList[timerId].callback()
                    if(timersList[timerId]) {
                        SetTimeout(delay, timersList[timerId].timeoutFunc)
                    }
                }
            }
        }

        SetTimeout(delay, timersList[timerId].timeoutFunc)

        return timerId
    }

    global.setInterval = (callback, timeout) => {
        return SetTimer(timeout, callback)
    }
    
    global.setTimeout = (callback, timeout) => {
        return SetTimeout(timeout, callback)
    }
}

LoadTimers(globalThis)