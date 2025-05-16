#include "core.h"
#include "stack.h"

#include <utils/common.h>
#include <utils/utils.h>

std::vector<EValue> emptyTable;

EValue SerializeData(std::any data, EContext* state)
{
    std::any value = data;

    if (!value.has_value())
        return EValue(state, nullptr);

    try
    {
        if (value.type() == typeid(const char*)) {
            auto val = std::any_cast<const char*>(value);
            if (val == nullptr) return EValue(state, std::string(""));
            return EValue(state, std::string(val));
        }
        else if (value.type() == typeid(char*)) {
            auto val = std::any_cast<char*>(value);
            if (val == nullptr) return EValue(state, std::string(""));
            return EValue(state, std::string(val));
        }
        else if (value.type() == typeid(std::string)) {
            std::string val = std::any_cast<std::string>(value);
            if (starts_with(val, "JSON⇚") && ends_with(val, "⇛")) {
                std::string json = explode(explode(val, "⇚")[1], "⇛")[0];

                if (state->GetKind() == ContextKinds::Lua) {
                    EValue rapidJsonTable = EValue::getGlobal(state, "json");
                    if (!rapidJsonTable["decode"].isFunction())
                        return EValue(state, emptyTable);

                    EValue decodedResult(state);
                    try
                    {
                        decodedResult = rapidJsonTable["decode"](json);
                    }
                    catch (EException& e)
                    {
                        PLUGIN_PRINTF("SerializeData", "An error has occured: %s\n", e.what());
                        return EValue(state, emptyTable);
                    }

                    if (decodedResult.isNull())
                        return EValue(state, emptyTable);

                    return decodedResult;
                }
                else if (state->GetKind() == ContextKinds::JavaScript) {
                    return EValue(state, JS_ParseJSON((JSContext*)state->GetState(), json.c_str(), json.length(), "SerializeData"));
                }
                else return EValue(state, nullptr);
            }
            else return EValue(state, val);
        }
        else if (value.type() == typeid(std::any))
            return SerializeData(std::any_cast<std::any>(value), state);
        else if (value.type() == typeid(uint64_t))
            return EValue(state, std::any_cast<uint64_t>(value));
        else if (value.type() == typeid(uint32_t))
            return EValue(state, std::any_cast<uint32_t>(value));
        else if (value.type() == typeid(uint16_t))
            return EValue(state, std::any_cast<uint16_t>(value));
        else if (value.type() == typeid(uint8_t))
            return EValue(state, std::any_cast<uint8_t>(value));
        else if (value.type() == typeid(int64_t))
            return EValue(state, std::any_cast<int64_t>(value));
        else if (value.type() == typeid(int32_t))
            return EValue(state, std::any_cast<int32_t>(value));
        else if (value.type() == typeid(int16_t))
            return EValue(state, std::any_cast<int16_t>(value));
        else if (value.type() == typeid(int8_t))
            return EValue(state, std::any_cast<int8_t>(value));
        else if (value.type() == typeid(bool))
            return EValue(state, std::any_cast<bool>(value));
        else if (value.type() == typeid(float))
            return EValue(state, std::any_cast<float>(value));
        else if (value.type() == typeid(double))
            return EValue(state, std::any_cast<double>(value));
        else if (value.type() == typeid(std::nullptr_t))
            return EValue(state, nullptr);
        else if (value.type() == typeid(EValue))
            return std::any_cast<EValue>(value);
        else if (value.type() == typeid(Vector))
            return EValue(state, std::any_cast<Vector>(value));
        else if (value.type() == typeid(Vector2D))
            return EValue(state, std::any_cast<Vector2D>(value));
        else if (value.type() == typeid(Vector4D))
            return EValue(state, std::any_cast<Vector4D>(value));
        else if (value.type() == typeid(Color))
            return EValue(state, std::any_cast<Color>(value));
        else if (value.type() == typeid(QAngle))
            return EValue(state, std::any_cast<QAngle>(value));
        else if (value.type() == typeid(ClassData*)) {
            ClassData* data = std::any_cast<ClassData*>(value);
            EValue val(state, data);
            if (data->HasData("should_mark_freeable")) MarkDeleteOnGC(data);
            return val;
        }
        else if (value.type() == typeid(std::vector<std::string>))
        {
            if (state->GetKind() == ContextKinds::Lua) {
                std::vector<std::string> tmpval = std::any_cast<std::vector<std::string>>(value);
                std::string tbl = tmpval[0];

                EValue load = EValue::getGlobal(state, "load");
                try
                {
                    EValue loadReturnValue = load(tbl);
                    if (!loadReturnValue.isFunction())
                        return EValue(state, emptyTable);

                    EValue loadFuncRetVal = loadReturnValue();
                    if (!loadFuncRetVal.isTable())
                        return EValue(state, emptyTable);

                    return loadFuncRetVal;
                }
                catch (EException& e)
                {
                    PRINTF("Exception: %s\n", e.what());
                    return EValue(state, emptyTable);
                }
            }
            else {
                PRINT("Cannot convert Lua table to JS object.\n");
                return EValue(state);
            }
        }
        else if (value.type() == typeid(std::vector<std::any>))
        {
            return EValue(state, std::any_cast<std::vector<std::any>>(value));
        }
        else
        {
            PRINTF("Unknown Data Type: %s\n", value.type().name());
            return EValue(state, nullptr);
        }
    }
    catch (std::bad_any_cast& err)
    {
        PRINTF("Invalid casting: %s\n", err.what());
        return EValue(state, nullptr);
    }

    return EValue(state, nullptr);
}

std::any DeserializeSerpent(EValue ref, EContext* state)
{
    EValue serpentDump = EValue::getGlobal(state, "serpent")["dump"];
    EValue serpentDumpReturnValue = serpentDump(ref);

    std::vector<std::string> tmptbl;
    tmptbl.push_back(serpentDumpReturnValue.cast<std::string>());

    return tmptbl;
}

std::any DeserializeData(EValue ref, EContext* state)
{
    if (ref.isBool())
        return ref.cast<bool>();
    else if (ref.isNull())
        return nullptr;
    else if (ref.isNumber()) {
        if (ref.cast<float>() == (float)(ref.cast<int64_t>())) return ref.cast<float>();
        else return ref.cast<int64_t>();
    }
    else if (ref.isString())
        return ref.cast<std::string>();
    else if (ref.isInstance<ClassData*>())
        return ref.cast<ClassData*>();
    else if (ref.isTable())
    {
        if (state->GetKind() == ContextKinds::Lua) {
            EValue rapidJsonTable = EValue::getGlobal(state, "json");
            if (!rapidJsonTable["encode"].isFunction())
                return DeserializeSerpent(ref, state);

            EValue encodedResult(state);
            try
            {
                encodedResult = rapidJsonTable["encode"](ref);
            }
            catch (EException& e)
            {
                return DeserializeSerpent(ref, state);
            }

            if (encodedResult.isNull())
                return DeserializeSerpent(ref, state);

            return string_format("JSON⇚%s⇛", encodedResult.cast<std::string>().c_str());
        }
        else if (state->GetKind() == ContextKinds::JavaScript) {
            auto retval = JS_JSONStringify(state->GetJSState(), ref.pushJS(), JS_NULL, JS_NULL);
            if (JS_IsException(retval)) {
                return std::vector<std::string>{};
            }

            return string_format("JSON⇚%s⇛", EValue(state, retval).cast<std::string>().c_str());
        }
        else return nullptr;
    }
    else
        return nullptr;
}