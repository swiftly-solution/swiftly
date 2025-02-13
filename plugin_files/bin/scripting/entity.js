const LoadEntities = (global) => {
    global.AddHookEntityOutput = (classname, output) => {
        if(typeof classname != "string") return console.log("AddHookEntityOutput: classname must be a string.");
        if(typeof output != "string") return console.log("AddHookEntityOutput: output must be a string.");
    
        let hookId = hooks.AddEntityOutputHook(classname, output)
    
        if (hookId == "00000000-0000-0000-0000-000000000000") return
    
        return { hookId }
    }
}

LoadEntities(globalThis)