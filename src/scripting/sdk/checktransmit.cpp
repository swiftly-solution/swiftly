#include <scripting/core.h>
#include <public/iservernetworkable.h>
#include <sdk/schema.h>

#include "ehandle.h"
#include <sdk/game.h>
#include <utils/utils.h>

#include <map>

LoadScriptingComponent(checktransmit, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("CCheckTransmitInfo");

    ADD_CLASS_FUNCTION("CCheckTransmitInfo", "CCheckTransmitInfo", [](FunctionContext* context, ClassData* data) -> void {
        auto classData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if(classData) {
            if(classData->HasData("transmit_ptr")) {
                data->SetData("transmit_ptr", classData->GetData<void*>("class_ptr"));
            } else if(classData->HasData("ptr")) {
                data->SetData("transmit_ptr", classData->GetData<void*>("ptr"));
            } else data->SetData("transmit_ptr", (void*)nullptr);
        } else {
            auto strptr = context->GetArgumentOr<std::string>(0, "");
            if(starts_with(strptr, "0x")) {
                data->SetData("transmit_ptr", (void*)StringToPtr(strptr));
            } else data->SetData("transmit_ptr", (void*)nullptr);
        }
    });

    ADD_CLASS_FUNCTION("CCheckTransmitInfo", "GetPlayers", [](FunctionContext* context, ClassData* data) -> void {
        std::map<int, int> player_entindex;

        for (int i = 0; i < GetMaxGameClients(); i++) {
            CEntityInstance* controller = g_pEntitySystem->GetEntityInstance(CEntityIndex(i + 1));
            if(!controller) continue;

            CHandle<CEntityInstance> pawnHandle = schema::GetProp<CHandle<CEntityInstance>>(controller, "CCSPlayerController", "m_hPlayerPawn");
            if (!pawnHandle) continue;
    
            player_entindex.insert({ i, pawnHandle->m_pEntity->m_EHandle.GetEntryIndex() });
        }

        context->SetReturn(player_entindex);
    });

    ADD_CLASS_FUNCTION("CCheckTransmitInfo", "GetEntities", [](FunctionContext* context, ClassData* data) -> void {
        std::vector<int> entities_list;
        CCheckTransmitInfo* m_ptr = (CCheckTransmitInfo*)data->GetData<void*>("transmit_ptr");

        for (int i = 0; i < MAX_EDICTS; i++)
            if (m_ptr->m_pTransmitEntity->IsBitSet(i))
                entities_list.push_back(i);
    
        context->SetReturn(entities_list);
    });

    ADD_CLASS_FUNCTION("CCheckTransmitInfo", "SetEntities", [](FunctionContext* context, ClassData* data) -> void {
        std::vector<int> entities_list = context->GetArgumentOr<std::vector<int>>(0, {});
        CCheckTransmitInfo* m_ptr = (CCheckTransmitInfo*)data->GetData<void*>("transmit_ptr");

        m_ptr->m_pTransmitEntity->ClearAll();
        for (int i = 0; i < entities_list.size(); i++)
            m_ptr->m_pTransmitEntity->Set(entities_list[i]);
    });

    ADD_CLASS_FUNCTION("CCheckTransmitInfo", "AddEntityIndex", [](FunctionContext* context, ClassData* data) -> void {
        int entindex = context->GetArgumentOr<int>(0, 0);
        CCheckTransmitInfo* m_ptr = (CCheckTransmitInfo*)data->GetData<void*>("transmit_ptr");

        if(!m_ptr->m_pTransmitEntity->IsBitSet(entindex))
            m_ptr->m_pTransmitEntity->Set(entindex);
    });

    ADD_CLASS_FUNCTION("CCheckTransmitInfo", "RemoveEntityIndex", [](FunctionContext* context, ClassData* data) -> void {
        int entindex = context->GetArgumentOr<int>(0, 0);
        CCheckTransmitInfo* m_ptr = (CCheckTransmitInfo*)data->GetData<void*>("transmit_ptr");

        if(m_ptr->m_pTransmitEntity->IsBitSet(entindex))
            m_ptr->m_pTransmitEntity->Clear(entindex);
    });

    ADD_CLASS_FUNCTION("CCheckTransmitInfo", "Clear", [](FunctionContext* context, ClassData* data) -> void {
        CCheckTransmitInfo* m_ptr = (CCheckTransmitInfo*)data->GetData<void*>("transmit_ptr");
        m_ptr->m_pTransmitEntity->ClearAll();
    });
})