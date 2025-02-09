_G = setmetatable(_G, {
    __index = function(t, k)
        if IsSDKClass(k) then
            return GenerateSDKFactory(k)
        end
    end
})