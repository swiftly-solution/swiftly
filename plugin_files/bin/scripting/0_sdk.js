globalThis.sdk = new Proxy({}, {
    get: (obj, key, receiver) => {
        if (IsTypeClass(key)) return GenerateTypeFactory(key);
        else if (IsSDKClass(key)) return (ptr) => {
            let f = GenerateSDKFactory(key, ptr)
            return f;
        }
        else return undefined;
    },
    set: (target, key, val, recv) => {
        throw SyntaxError("You cannot set values to SDK.");
    }
})