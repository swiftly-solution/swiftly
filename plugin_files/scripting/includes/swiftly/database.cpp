#include "database.h"

DB_Result DeserializeData(const char *jsonData)
{
    DB_Result result;

    rapidjson::Document document;
    document.Parse(jsonData);

    if (document.IsArray())
    {
        for (const auto &entry : document.GetArray())
        {
            std::map<std::string, BaseValue *> mp;

            for (auto it = entry.MemberBegin(); it != entry.MemberEnd(); ++it)
            {
                const char *key = it->name.GetString();

                if (it->value.IsString())
                    mp.insert(std::make_pair(key, new TypedValue<const char *>(it->value.GetString())));
                else if (it->value.IsInt())
                    mp.insert(std::make_pair(key, new TypedValue<int>(it->value.GetInt())));
                else if (it->value.IsInt64())
                    mp.insert(std::make_pair(key, new TypedValue<int64_t>(it->value.GetInt64())));
                else if (it->value.IsUint())
                    mp.insert(std::make_pair(key, new TypedValue<uint32_t>(it->value.GetUint())));
                else if (it->value.IsUint64())
                    mp.insert(std::make_pair(key, new TypedValue<uint64_t>(it->value.GetUint64())));
                else if (it->value.IsBool())
                    mp.insert(std::make_pair(key, new TypedValue<bool>(it->value.GetBool())));
                else if (it->value.IsFloat())
                    mp.insert(std::make_pair(key, new TypedValue<float>(it->value.GetFloat())));
                else if (it->value.IsDouble())
                    mp.insert(std::make_pair(key, new TypedValue<double>(it->value.GetDouble())));
            }

            result.push_back(mp);
        }
    }

    return result;
}