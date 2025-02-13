function LoadHooks(global) {
    global.AddHook = (mem, argsList, returnType) => {
        if (typeof argsList !== "string") {
            console.log("AddHook: argsList must be a string.");
            return;
        }
        if (typeof returnType !== "string") {
            console.log("AddHook: returnType must be a string.");
            return;
        }
    
        let hookId = hooks.Add(mem, argsList, returnType);
    
        if (hookId === "00000000-0000-0000-0000-000000000000") {
            return;
        }
    
        return { hookId };
    };
    
    global.AddPreHookListener = (hookHandle, callback) => {
        if (typeof hookHandle !== "object" || hookHandle === null) {
            console.log("Error: Invalid hook data passed to AddPreHookListener.");
            return;
        }
    
        if (typeof hookHandle.hookId !== "string") {
            console.log("Error: Invalid hook data passed to AddPreHookListener.");
            return;
        }
    
        return AddEventHandler(`hook:Pre:${hookHandle.hookId}`, callback);
    };
    
    global.AddPostHookListener = (hookHandle, callback) => {
        if (typeof hookHandle !== "object" || hookHandle === null) {
            console.log("Error: Invalid hook data passed to AddPostHookListener.");
            return;
        }
    
        if (typeof hookHandle.hookId !== "string") {
            console.log("Error: Invalid hook data passed to AddPostHookListener.");
            return;
        }
    
        return AddEventHandler(`hook:Post:${hookHandle.hookId}`, callback);
    };
    
    global.RemoveHookListener = (hookListener) => {
        if (typeof hookListener !== "object" || hookListener === null) {
            console.log("Error: Invalid hook data passed to RemoveHookListener.");
            return;
        }
    
        if (!hookListener.key || !hookListener.name) {
            console.log("Error: Invalid hook data passed to RemoveHookListener.");
            return;
        }
    
        RemoveEventHandler(hookListener);
    };

    global.CallHook = (hookHandle, ...args) => {
        if (typeof hookHandle !== "object" || hookHandle === null) {
            console.log("Error: Invalid hook data passed to CallHook.");
            return;
        }

        if (typeof hookHandle.hookId !== "string") {
            console.log("Error: Invalid hook data passed to CallHook.");
            return;
        }

        return hooks.Call(hookHandle.hookId, global.msgpack_pack(args));
    };
}

LoadHooks(globalThis)