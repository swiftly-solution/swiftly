local msgpack_pack = msgpack.pack

function AddHook(mem, args_list, return_type)
    if type(args_list) ~= "string" then
        print("AddHook: args_list must be a string.")
        return
    end
    if type(return_type) ~= "string" then
        print("AddHook: return_type must be a string.")
        return
    end

    local hookId = hooks:Add(mem, args_list, return_type)

    if hookId == "00000000-0000-0000-0000-000000000000" then
        return
    end

    return { hookId = hookId }
end

function AddPreHookListener(hookHandle, callback)
    if type(hookHandle) ~= "table" then
        print("Error: Invalid hook data passed to AddPreHookListener.")
        return
    end

    if type(hookHandle.hookId) ~= "string" then
        print("Error: Invalid hook data passed to AddPreHookListener.")
        return
    end

    return AddEventHandler("hook:Pre:"..hookHandle.hookId, callback)
end

function AddPostHookListener(hookHandle, callback)
    if type(hookHandle) ~= "table" then
        print("Error: Invalid hook data passed to AddPostHookListener.")
        return
    end

    if type(hookHandle.hookId) ~= "string" then
        print("Error: Invalid hook data passed to AddPostHookListener.")
        return
    end

    return AddEventHandler("hook:Post:"..hookHandle.hookId, callback)
end

function RemoveHookListener(hookListener)
    if type(hookListener) ~= "table" then
        print("Error: Invalid hook data passed to RemoveHookListener.")
        return
    end

    if not hookListener.key or not hookListener.name then
        print("Error: Invalid hook data passed to RemoveHookListener.")
        return
    end
    
    RemoveEventHandler(hookListener)
end

function CallHook(hookHandle, ...)
    if type(hookHandle) ~= "table" then
        print("Error: Invalid hook data passed to AddPostHookListener.")
        return
    end

    if type(hookHandle.hookId) ~= "string" then
        print("Error: Invalid hook data passed to AddPostHookListener.")
        return
    end

    return hooks:Call(hookHandle.hookId, msgpack_pack({...}))
end