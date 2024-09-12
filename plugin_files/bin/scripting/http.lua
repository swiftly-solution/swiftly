local httpRequestsQueue = {}
local json_encode = json.encode
local json_decode = json.decode

function PerformHTTPRequest(url, callback, method, data, headers, files)
    local sendData = {
        url = url,
        method = method or 'GET',
        data = data or '',
        headers = headers or {},
        files = files or {}
    }

    local httpRequestID = http:PerformHTTP(json_encode(sendData))

    if httpRequestID ~= "00000000-0000-0000-0000-000000000000" then
        httpRequestsQueue[httpRequestID] = callback
    else
        callback(0, nil, {}, 'Failed to create HTTP Request')
    end
end

AddEventHandler("OnHTTPActionPerformed", function(event, status, body, headers, err, httpRequestID)
    if not httpRequestsQueue[httpRequestID] then return EventResult.Continue end
    headers = json_decode(headers)

    httpRequestsQueue[httpRequestID](status, body, headers, err)
    httpRequestsQueue[httpRequestID] = nil

    return EventResult.Stop
end)