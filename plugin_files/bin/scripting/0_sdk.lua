_G = setmetatable(_G, {
    __index = function(t, k)
        if IsSDKClass(k) then
            return function(ptr)
                return GenerateSDKFactory(k, ptr)
            end
        elseif IsTypeClass(k) then
            return GenerateTypeFactory(k)
        end
    end
})

sdk = setmetatable({}, {
    __index = function(t, k)
        if IsSDKClass(k) then
            return function(ptr)
                return GenerateSDKFactory(k, ptr)
            end
        elseif IsTypeClass(k) then
            return GenerateTypeFactory(k)
        end
    end
})