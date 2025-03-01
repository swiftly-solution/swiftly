#ifndef _encoders_json_h
#define _encoders_json_h

#include <string>
#include <any>
#include <vector>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

namespace encoders {
    namespace json {
        std::string SerializeArrayToString(std::vector<std::any> v);
    };
};

#endif