#ifndef _encoders_msgpack_h
#define _encoders_msgpack_h

#include <string>
#include <any>
#include <vector>
#include <msgpack.hpp>

namespace encoders {
    namespace msgpack {
        std::string SerializeToString(std::vector<std::any> v);
        std::vector<std::any> DeserializeFromString(std::string str);
    };
};

#endif