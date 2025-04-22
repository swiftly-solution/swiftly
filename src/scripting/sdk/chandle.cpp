#include <scripting/core.h>
#include "ehandle.h"

#include <utils/utils.h>

LoadScriptingComponent(chandle, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("CHandle");

    ADD_CLASS_FUNCTION("CHandle", "CHandle", [](FunctionContext* context, ClassData* data) -> void {
        auto classData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if(classData) {
            if(classData->HasData("chandle_ptr")) {
                data->SetData("chandle_ptr", classData->GetData<void*>("chandle_ptr"));
            } else if(classData->HasData("ptr")) {
                data->SetData("chandle_ptr", classData->GetData<void*>("ptr"));
            } else data->SetData("chandle_ptr", (void*)nullptr);
        } else {
            auto strptr = context->GetArgumentOr<std::string>(0, "");
            if(starts_with(strptr, "0x")) {
                data->SetData("chandle_ptr", (void*)StringToPtr(strptr));
            } else data->SetData("chandle_ptr", (void*)nullptr);
        }
    });

    ADD_CLASS_FUNCTION("CHandle", "GetPtr", [](FunctionContext* context, ClassData* data) -> void {
        CHandle<CEntityInstance>* m_Handle = (CHandle<CEntityInstance>*)data->GetData<void*>("chandle_ptr");
        context->SetReturn(PtrToString(m_Handle->Get()));
    });

    ADD_CLASS_FUNCTION("CHandle", "SetPtr", [](FunctionContext* context, ClassData* data) -> void {
        std::string ptr = context->GetArgumentOr<std::string>(0, "");
        if (!starts_with(ptr, "0x")) return;

        CHandle<CEntityInstance>* m_Handle = (CHandle<CEntityInstance>*)data->GetData<void*>("chandle_ptr");
        m_Handle->Set((CEntityInstance*)strtol(ptr.c_str(), nullptr, 16));
    });

    ADD_CLASS_FUNCTION("CHandle", "GetHandlePtr", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(PtrToString(data->GetData<void*>("chandle_ptr")));
    });

    ADD_CLASS_FUNCTION("CHandle", "IsValid", [](FunctionContext* context, ClassData* data) -> void {
        CHandle<CEntityInstance>* m_Handle = (CHandle<CEntityInstance>*)data->GetDataOr<void*>("chandle_ptr", nullptr);
        if(!m_Handle) return context->SetReturn(false);

        context->SetReturn(m_Handle->IsValid());
    });

    ADD_CLASS_FUNCTION("CHandle", "GetEntryIndex", [](FunctionContext* context, ClassData* data) -> void {
        CHandle<CEntityInstance>* m_Handle = (CHandle<CEntityInstance>*)data->GetDataOr<void*>("chandle_ptr", nullptr);
        if(!m_Handle) return context->SetReturn(0);

        context->SetReturn(m_Handle->GetEntryIndex());
    });

    ADD_CLASS_FUNCTION("CHandle", "GetSerialNumber", [](FunctionContext* context, ClassData* data) -> void {
        CHandle<CEntityInstance>* m_Handle = (CHandle<CEntityInstance>*)data->GetDataOr<void*>("chandle_ptr", nullptr);
        if(!m_Handle) return context->SetReturn(0);

        context->SetReturn(m_Handle->GetSerialNumber());
    });
})