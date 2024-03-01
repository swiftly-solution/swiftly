#ifndef _swiftly_scripting_utils_h
#define _swiftly_scripting_utils_h

#include "swiftly_utils.h"
#include "playermanager.h"

#include <functional>
#include <thread>
#include <string>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/error/en.h>

int GetPlayerId(const char *str, bool matchbots = false);
void CreateThread(std::function<void()> fn);

class JSONObject
{
public:
    rapidjson::Document document;

    JSONObject() {}
    ~JSONObject()
    {
        document.Clear();
    }

    bool Parse(std::string str);
    const char *GetParseError();
    const char *Encode();
};

class JSON
{
private:
public:
    JSON() {}

    JSONObject *Create()
    {
        return (new JSONObject());
    }

    JSONObject *Parse(std::string jsonstr)
    {
        JSONObject *obj = new JSONObject();
        if (obj->Parse(jsonstr))
            print("[Swiftly] An error has occured while trying to parse JSON.\n[Swiftly] Error: %s\n", obj->GetParseError());

        return obj;
    }
};

extern JSON *json;

#endif