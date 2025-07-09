#include "functions.h"
#include "manager.h"

#include <utils/common.h>
#include <embedder/src/Embedder.h>
#include <memory/gamedata/gamedata.h>

#include <dyncall/dyncall.h>

DCCallVM* functionCallVM = dcNewCallVM(4096);

FunctionHook::FunctionHook(std::string signature_name, dyno::CallbackType callbackType, dyno::CallbackHandler handler, std::string function_args, char function_return)
{
    void* signature = g_GameData.FetchRawSignature(signature_name);
    if (!signature) return;

    m_callbackType = callbackType;
    m_handler = handler;
    m_pfn = nullptr;
    m_signature_name = signature_name;
    m_function_args = function_args;
    m_function_return = function_return;

    g_hookManager.AddToQueue(this);
}

FunctionHook::FunctionHook(const char* signature_name, dyno::CallbackType callbackType, dyno::CallbackHandler handler, std::string function_args, char function_return)
{
    m_callbackType = callbackType;
    m_handler = handler;
    m_pfn = nullptr;
    m_signature_name = signature_name;
    m_function_args = function_args;
    m_function_return = function_return;

    g_hookManager.AddToQueue(this);
}

FunctionHook::FunctionHook(void* signature_name, dyno::CallbackType callbackType, dyno::CallbackHandler handler, std::string function_args, char function_return)
{
    m_callbackType = callbackType;
    m_handler = handler;
    m_pfn = signature_name;
    m_signature_name = "";
    m_function_args = function_args;
    m_function_return = function_return;

    g_hookManager.AddToQueue(this);
}

void FunctionHook::Initialize()
{
    if (m_pfn == nullptr && m_signature_name != "") {
        m_pfn = g_GameData.FetchRawSignature(m_signature_name);
    }
    if (!m_pfn) return;

    dyno::IHookManager& manager = dyno::IHookManager::Get();
    hookFunc = manager.hookDetour(m_pfn, [this] { return new DEFAULT_CALLCONV(GetDataObjectList(m_function_args), GetDataObject(m_function_return)); }).get();

    hookFunc->addCallback(m_callbackType, m_handler);
}

dyno::IHook* FunctionHook::GetHookFunction()
{
    if (!m_pfn) return nullptr;

    dyno::IHookManager& manager = dyno::IHookManager::Get();
    return manager.findDetour(m_pfn).get();
}

extern bool shuttingDown;

FunctionHook::~FunctionHook()
{
    Disable();
    if (!m_pfn) return;

    if (shuttingDown) return;

    dyno::IHookManager& manager = dyno::IHookManager::Get();
    manager.unhookDetour(m_pfn);
}

void FunctionHook::Enable()
{
    if (!m_pfn) return;
    if (enabled) return;

    enabled = true;
    hookFunc->addCallback(m_callbackType, m_handler);
}

void FunctionHook::Disable()
{
    if (!m_pfn) return;
    if (!enabled) return;

    enabled = false;
    hookFunc->removeCallback(m_callbackType, m_handler);
}

std::any FunctionHook::Call(std::vector<std::any> arguments)
{
    if (!m_pfn) return nullptr;

    dcReset(functionCallVM);
    dcMode(functionCallVM, DC_CALL_C_DEFAULT);

    for (int i = 0; i < arguments.size(); i++) {
        if (m_function_args.size() <= i)
            break;

        if (m_function_args.at(i) == 'p') {
            if (arguments[i].type() == typeid(std::string)) {
                dcArgPointer(functionCallVM, (void*)strtol(std::any_cast<std::string>(arguments[i]).c_str(), nullptr, 16));
            }
            else if (arguments[i].type() == typeid(ClassData*)) {
                auto cdata = std::any_cast<ClassData*>(arguments[i]);
                if (cdata->HasData("ptr")) {
                    dcArgPointer(functionCallVM, cdata->GetDataOr<void*>("ptr", nullptr));
                }
                else if (cdata->HasData("class_ptr")) {
                    dcArgPointer(functionCallVM, cdata->GetDataOr<void*>("class_ptr", nullptr));
                }
                else {
                    dcArgPointer(functionCallVM, (void*)nullptr);
                }
            }
        }
        else if (m_function_args.at(i) == 'f')
            dcArgFloat(functionCallVM, std::any_cast<float>(arguments[i]));
        else if (m_function_args.at(i) == 'b')
            dcArgBool(functionCallVM, std::any_cast<bool>(arguments[i]));
        else if (m_function_args.at(i) == 'd')
            dcArgDouble(functionCallVM, std::any_cast<double>(arguments[i]));
        else if (m_function_args.at(i) == 'i')
            dcArgInt(functionCallVM, std::any_cast<int>(arguments[i]));
        else if (m_function_args.at(i) == 'u')
            dcArgLong(functionCallVM, std::any_cast<uint32_t>(arguments[i]));
        else if (m_function_args.at(i) == 's')
            dcArgPointer(functionCallVM, (void*)std::any_cast<std::string>(arguments[i]).c_str());
        else if (m_function_args.at(i) == 'I')
            dcArgLongLong(functionCallVM, std::any_cast<int64_t>(arguments[i]));
        else if (m_function_args.at(i) == 'U')
            dcArgLongLong(functionCallVM, std::any_cast<uint64_t>(arguments[i]));
        else
        {
            PRINTF("Invalid Data Type: '%c'.\n", m_function_args.at(i));
            break;
        }
    }

    std::any retval = nullptr;
    if (m_function_return == 'p')
        retval = new ClassData({ { "ptr", (void*)dcCallPointer(functionCallVM, m_pfn) }, { "should_mark_freeable", true } }, "Memory", nullptr);
    else if (m_function_return == 'f')
        retval = (float)dcCallFloat(functionCallVM, m_pfn);
    else if (m_function_return == 'b')
        retval = (bool)dcCallBool(functionCallVM, m_pfn);
    else if (m_function_return == 'd')
        retval = (double)dcCallDouble(functionCallVM, m_pfn);
    else if (m_function_return == 'i')
        retval = (int)dcCallInt(functionCallVM, m_pfn);
    else if (m_function_return == 'u')
        retval = (uint32_t)dcCallInt(functionCallVM, m_pfn);
    else if (m_function_return == 's')
        retval = std::string((const char*)dcCallPointer(functionCallVM, m_pfn));
    else if (m_function_return == 'I')
        retval = (int64_t)dcCallLongLong(functionCallVM, m_pfn);
    else if (m_function_return == 'U')
        retval = (uint64_t)dcCallLongLong(functionCallVM, m_pfn);
    else if (m_function_return == 'v')
    {
        dcCallVoid(functionCallVM, m_pfn);
        retval = nullptr;
    }
    else
    {
        PRINTF("Invalid return type: '%c'.\n", m_function_return);
        retval = nullptr;
    }

    return retval;
}