#ifndef _encoders_json_h
#define _encoders_json_h

#include <string>
#include <rapidjson/json.hpp>

namespace encoders {
    namespace json {
        std::string ToString(rapidjson::Value& j);
        rapidjson::Document FromString(std::string str, std::string path = "");
    }
}

#endif