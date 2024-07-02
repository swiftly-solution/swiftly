local hookEntityOutputHandles = {
    pre = {},
    post = {}
}

function AddHookEntityOutput(classname, output)
    if type(classname) ~= "string" then
        print("AddHookEntityOutput: classname must be a string.")
        return
    end
    if type(output) ~= "string" then
        print("AddHookEntityOutput: output must be a string.")
        return
    end

    local hookId = hooks:EntityOutputAdd(classname, output)

    if hookId == "00000000-0000-0000-0000-000000000000" then
        return
    end

    return { hookId = hookId }
end