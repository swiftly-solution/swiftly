#include "msgpack.h"
#include <public/tier0/platform.h>

namespace encoders {
    namespace msgpack {

        std::string emptyData = "";
        bool setEmptyData = false;

        std::string SerializeToString(std::vector<std::any> v)
        {
            if (v.size() <= 0) {
                if (!setEmptyData)
                {
                    setEmptyData = true;

                    std::stringstream ss;
                    std::vector<::msgpack::object> eventData;

                    ::msgpack::pack(ss, eventData);
                    emptyData = ss.str();
                }

                return emptyData;
            }

            std::stringstream ss;
            std::vector<::msgpack::object> data;

            for (auto& value : v)
            {
                if (value.type() == typeid(const char*))
                    data.push_back(::msgpack::object(std::any_cast<const char*>(value)));
                else if (value.type() == typeid(std::string))
                    data.push_back(::msgpack::object(std::any_cast<std::string>(value).c_str()));
                else if (value.type() == typeid(uint64))
                    data.push_back(::msgpack::object(std::any_cast<uint64>(value)));
                else if (value.type() == typeid(uint32))
                    data.push_back(::msgpack::object(std::any_cast<uint32>(value)));
                else if (value.type() == typeid(unsigned long))
                    data.push_back(::msgpack::object(std::any_cast<unsigned long>(value)));
                else if (value.type() == typeid(uint16))
                    data.push_back(::msgpack::object(std::any_cast<uint16>(value)));
                else if (value.type() == typeid(uint8))
                    data.push_back(::msgpack::object(std::any_cast<uint8>(value)));
                else if (value.type() == typeid(int64))
                    data.push_back(::msgpack::object(std::any_cast<int64>(value)));
                else if (value.type() == typeid(int32))
                    data.push_back(::msgpack::object(std::any_cast<int32>(value)));
                else if (value.type() == typeid(long))
                    data.push_back(::msgpack::object(std::any_cast<long>(value)));
                else if (value.type() == typeid(int16))
                    data.push_back(::msgpack::object(std::any_cast<int16>(value)));
                else if (value.type() == typeid(int8))
                    data.push_back(::msgpack::object(std::any_cast<int8>(value)));
                else if (value.type() == typeid(bool))
                    data.push_back(::msgpack::object(std::any_cast<bool>(value)));
                else if (value.type() == typeid(float))
                    data.push_back(::msgpack::object(std::any_cast<float>(value)));
                else if (value.type() == typeid(double))
                    data.push_back(::msgpack::object(std::any_cast<double>(value)));
            }

            ::msgpack::pack(ss, data);

            return ss.str();
        }

        std::vector<std::any> DeserializeFromString(std::string str) {
            std::vector<std::any> res;

            ::msgpack::object_handle result;

            try {
                ::msgpack::unpack(result, str.c_str(), str.length());
            } catch(std::exception &e) {
                return res;
            }

            ::msgpack::object obj = result.get();

            if (obj.type != ::msgpack::type::ARRAY) {
                return res;
            }
            std::vector<::msgpack::object> obj_vector;
            obj.convert(obj_vector);

            for (const auto& elem : obj_vector) {
                switch (elem.type) {
                    case ::msgpack::type::BOOLEAN:
                        res.push_back(elem.as<bool>());
                        break;
                    case ::msgpack::type::POSITIVE_INTEGER:
                    case ::msgpack::type::NEGATIVE_INTEGER:
                        res.push_back(elem.as<int64_t>());
                        break;
                    case ::msgpack::type::FLOAT32:
                    case ::msgpack::type::FLOAT64:
                        res.push_back(elem.as<double>());
                        break;
                    case ::msgpack::type::STR:
                        res.push_back(elem.as<std::string>());
                        break;
                    case ::msgpack::type::ARRAY: {
                        std::vector<std::any> nested = DeserializeFromString(elem.as<std::string>());
                        res.push_back(nested);
                        break;
                    }
                    case ::msgpack::type::MAP:
                    case ::msgpack::type::BIN:
                    case ::msgpack::type::EXT:
                    case ::msgpack::type::NIL:
                        res.push_back(nullptr);
                        break;
                    default:
                        throw std::runtime_error("Unsupported type in MessagePack data");
                }
            }

            return res;
        }
    };
};