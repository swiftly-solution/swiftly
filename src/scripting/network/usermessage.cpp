#include <scripting/core.h>

#include <network/usermessages/usermessage.h>

LoadScriptingComponent(usermessage, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("UserMessage");

    ADD_CLASS_FUNCTION("UserMessage", "UserMessage", [](FunctionContext* context, ClassData* data) -> void {
        auto classData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if(classData) {
            if(classData->HasData("um_ptr")) {
                data->SetData("um_ptr", classData->GetData<UserMessage*>("um_ptr"));
            }
        } else {
            auto strptr = context->GetArgumentOr<std::string>(0, "");
            if(strptr == "") return;
            data->SetData("um_ptr", new UserMessage(strptr));
        }
    });

    ADD_CLASS_FUNCTION("UserMessage", "~UserMessage", [](FunctionContext* context, ClassData* data) -> void {
        if(data->HasData("um_ptr")) {
            delete data->GetData<UserMessage*>("um_ptr");
        }
    });

    ADD_CLASS_FUNCTION("UserMessage", "IsValidMessage", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->IsValidMessage());
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetMessageName", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetMessageName());
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetMessageID", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetMessageID());
    });

    ADD_CLASS_FUNCTION("UserMessage", "HasField", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->HasField(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;

        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetInt32(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;

        int32_t value = context->GetArgumentOr<int>(1, 0);

        data->GetData<UserMessage*>("um_ptr")->SetInt32(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;

        int index = context->GetArgumentOr<int>(1, 0);

        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedInt32(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;

        int32_t index = context->GetArgumentOr<int>(1, 0);
        int32_t value = context->GetArgumentOr<int>(2, 0);

        data->GetData<UserMessage*>("um_ptr")->SetRepeatedInt32(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;

        int32_t value = context->GetArgumentOr<int>(1, 0);

        data->GetData<UserMessage*>("um_ptr")->AddInt32(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetInt64(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int64_t value = context->GetArgumentOr<int>(1, (int)0);
        data->GetData<UserMessage*>("um_ptr")->SetInt64(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedInt64(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        int64_t value = context->GetArgumentOr<int>(2, (int)0);
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedInt64(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int64_t value = context->GetArgumentOr<int>(1, (int)0);
        data->GetData<UserMessage*>("um_ptr")->AddInt64(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetUInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetUInt32(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetUInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        uint32_t value = context->GetArgumentOr<int>(1, (int)0);
        data->GetData<UserMessage*>("um_ptr")->SetUInt32(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedUInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedUInt32(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedUInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        uint32_t value = context->GetArgumentOr<int>(2, (int)0);
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedUInt32(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddUInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        uint32_t value = context->GetArgumentOr<int>(1, (int)0);
        data->GetData<UserMessage*>("um_ptr")->AddUInt32(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetUInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetUInt64(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetUInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        uint64_t value = context->GetArgumentOr<uint64_t>(1, (uint64_t)0);
        data->GetData<UserMessage*>("um_ptr")->SetUInt64(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedUInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedUInt64(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedUInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        uint64_t value = context->GetArgumentOr<uint64_t>(2, (uint64_t)0);
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedUInt64(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddUInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        uint64_t value = context->GetArgumentOr<uint64_t>(1, (uint64_t)0);
        data->GetData<UserMessage*>("um_ptr")->AddUInt64(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetInt64OrUnsigned", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetInt64OrUnsigned(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetInt64OrUnsigned", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int64_t value = context->GetArgumentOr<int>(1, (int)0);
        data->GetData<UserMessage*>("um_ptr")->SetInt64OrUnsigned(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedInt64OrUnsigned", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedInt64OrUnsigned(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedInt64OrUnsigned", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        int64_t value = context->GetArgumentOr<int>(2, (int)0);
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedInt64OrUnsigned(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddInt64OrUnsigned", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int64_t value = context->GetArgumentOr<int>(1, (int)0);
        data->GetData<UserMessage*>("um_ptr")->AddInt64OrUnsigned(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetBool", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetBool(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetBool", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        bool value = context->GetArgumentOr<bool>(1, (bool)0);
        data->GetData<UserMessage*>("um_ptr")->SetBool(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedBool", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedBool(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedBool", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        bool value = context->GetArgumentOr<bool>(2, (bool)0);
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedBool(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddBool", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        bool value = context->GetArgumentOr<bool>(1, (bool)0);
        data->GetData<UserMessage*>("um_ptr")->AddBool(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetFloat", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetFloat(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetFloat", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        float value = context->GetArgumentOr<float>(1, (float)0);
        data->GetData<UserMessage*>("um_ptr")->SetFloat(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedFloat", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedFloat(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedFloat", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        float value = context->GetArgumentOr<float>(2, (float)0);
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedFloat(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddFloat", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        float value = context->GetArgumentOr<float>(1, (float)0);
        data->GetData<UserMessage*>("um_ptr")->AddFloat(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetDouble(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        double value = context->GetArgumentOr<double>(1, (double)0);
        data->GetData<UserMessage*>("um_ptr")->SetDouble(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedDouble(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        double value = context->GetArgumentOr<double>(2, (double)0);
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedDouble(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        double value = context->GetArgumentOr<double>(1, (double)0);
        data->GetData<UserMessage*>("um_ptr")->AddDouble(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetFloatOrDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetFloatOrDouble(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetFloatOrDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        float value = context->GetArgumentOr<float>(1, (float)0);
        data->GetData<UserMessage*>("um_ptr")->SetFloatOrDouble(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedFloatOrDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedFloatOrDouble(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedFloatOrDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        float value = context->GetArgumentOr<float>(2, (float)0);
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedFloatOrDouble(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddFloatOrDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        float value = context->GetArgumentOr<float>(1, (float)0);
        data->GetData<UserMessage*>("um_ptr")->AddFloatOrDouble(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetString", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetString(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetString", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        std::string value = context->GetArgumentOr<std::string>(1, "");
        data->GetData<UserMessage*>("um_ptr")->SetString(field_name, value.c_str());
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedString", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedString(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedString", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        std::string value = context->GetArgumentOr<std::string>(2, "");
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedString(field_name, index, value.c_str());
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddString", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        std::string value = context->GetArgumentOr<std::string>(1, "");
        data->GetData<UserMessage*>("um_ptr")->AddString(field_name, value.c_str());
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetColor", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetColor(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetColor", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        Color value = context->GetArgumentOr<Color>(1, Color(255,255,255,255));
        data->GetData<UserMessage*>("um_ptr")->SetColor(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedColor", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedColor(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedColor", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        Color value = context->GetArgumentOr<Color>(2, Color(255,255,255,255));
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedColor(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddColor", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        Color value = context->GetArgumentOr<Color>(1, Color(255,255,255,255));
        data->GetData<UserMessage*>("um_ptr")->AddColor(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetVector2D", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetVector2D(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetVector2D", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        Vector2D value = context->GetArgumentOr<Vector2D>(1, Vector2D(0.0,0.0));
        data->GetData<UserMessage*>("um_ptr")->SetVector2D(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedVector2D", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedVector2D(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedVector2D", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        Vector2D value = context->GetArgumentOr<Vector2D>(2, Vector2D(0.0,0.0));
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedVector2D(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddVector2D", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        Vector2D value = context->GetArgumentOr<Vector2D>(1, Vector2D(0.0,0.0));
        data->GetData<UserMessage*>("um_ptr")->AddVector2D(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetVector", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetVector(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetVector", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        Vector value = context->GetArgumentOr<Vector>(1, Vector(0.0,0.0,0.0));
        data->GetData<UserMessage*>("um_ptr")->SetVector(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedVector", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedVector(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedVector", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        Vector value = context->GetArgumentOr<Vector>(2, Vector(0.0,0.0,0.0));
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedVector(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddVector", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        Vector value = context->GetArgumentOr<Vector>(1, Vector(0.0,0.0,0.0));
        data->GetData<UserMessage*>("um_ptr")->AddVector(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetQAngle", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetQAngle(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetQAngle", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        QAngle value = context->GetArgumentOr<QAngle>(1, QAngle(0.0,0.0,0.0));
        data->GetData<UserMessage*>("um_ptr")->SetQAngle(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedQAngle", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedQAngle(field_name, index));
    });

    ADD_CLASS_FUNCTION("UserMessage", "SetRepeatedQAngle", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);
        QAngle value = context->GetArgumentOr<QAngle>(2, QAngle(0.0,0.0,0.0));
        data->GetData<UserMessage*>("um_ptr")->SetRepeatedQAngle(field_name, index, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddQAngle", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        QAngle value = context->GetArgumentOr<QAngle>(1, QAngle(0.0,0.0,0.0));
        data->GetData<UserMessage*>("um_ptr")->AddQAngle(field_name, value);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetUMessage", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;

        context->SetReturn(MAKE_CLASS_INSTANCE("UserMessage", { { "um_ptr", new UserMessage(data->GetData<UserMessage*>("um_ptr")->GetUMessage(field_name)) } }));
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedMessage", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;

        int index = context->GetArgumentOr<int>(1, 0);

        context->SetReturn(MAKE_CLASS_INSTANCE("UserMessage", { { "um_ptr", new UserMessage(data->GetData<UserMessage*>("um_ptr")->GetRepeatedMessage(field_name, index)) } }));
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddMessage", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;

        context->SetReturn(MAKE_CLASS_INSTANCE("UserMessage", { { "um_ptr", new UserMessage(data->GetData<UserMessage*>("um_ptr")->AddMessage(field_name)) } }));
    });

    ADD_CLASS_FUNCTION("UserMessage", "RemoveRepeatedFieldValue", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;
        int index = context->GetArgumentOr<int>(1, 0);

        data->GetData<UserMessage*>("um_ptr")->RemoveRepeatedFieldValue(field_name, index);
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetRepeatedFieldCount", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        if(field_name == "") return;

        context->SetReturn(data->GetData<UserMessage*>("um_ptr")->GetRepeatedFieldCount(field_name));
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddClient", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = context->GetArgumentOr<int>(0, -1);
        if(playerid == -1) return;

        data->GetData<UserMessage*>("um_ptr")->AddClient(playerid);
    });

    ADD_CLASS_FUNCTION("UserMessage", "RemoveClient", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = context->GetArgumentOr<int>(0, -1);
        if(playerid == -1) return;

        data->GetData<UserMessage*>("um_ptr")->RemoveClient(playerid);
    });

    ADD_CLASS_FUNCTION("UserMessage", "ClearClients", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<UserMessage*>("um_ptr")->ClearClients();
    });

    ADD_CLASS_FUNCTION("UserMessage", "AddClients", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<UserMessage*>("um_ptr")->AddClients();
    });

    ADD_CLASS_FUNCTION("UserMessage", "GetClients", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<UserMessage*>("um_ptr")->GetClients();
    });

    ADD_CLASS_FUNCTION("UserMessage", "SendToPlayer", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = context->GetArgumentOr<int>(0, -1);
        if(playerid == -1) return;

        data->GetData<UserMessage*>("um_ptr")->SendToPlayer(playerid);
    });

    ADD_CLASS_FUNCTION("UserMessage", "SendToAllPlayers", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<UserMessage*>("um_ptr")->SendToAllPlayers();
    });

})