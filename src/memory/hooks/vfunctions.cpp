#include "vfunctions.h"

#include <memory/gamedata/gamedata.h>
#include <dynlibutils/module.h>
#include <utils/common.h>
#include <embedder/src/Embedder.h>

#include <dyncall/dyncall.h>

DCCallVM* vfunctionCallVM = dcNewCallVM(4096);

DynLibUtils::CModule DetermineModuleByLibrary(std::string library);

VFunctionHook::VFunctionHook(std::string library, std::string vtable, std::string offsetName, dyno::CallbackType callbackType, dyno::CallbackHandler handler, std::string function_args, char function_return)
{
    m_library = library;
    m_vtable = vtable;
    m_offsetName = offsetName;
    m_pvtable = nullptr;
    m_ioffset = 0;
    m_callbackType = callbackType;
    m_handler = handler;
    m_function_args = function_args;
    m_function_return = function_return;
}

extern bool shuttingDown;

VFunctionHook::~VFunctionHook()
{
    Disable();
    if (!m_pvtable) return;

    if (shuttingDown) return;

    dyno::IHookManager& manager = dyno::IHookManager::Get();
    manager.unhookVirtual(m_pvtable, m_ioffset);
}

void VFunctionHook::Initialize()
{
    auto module = DetermineModuleByLibrary(m_library);
    auto vtable = module.GetVirtualTableByName(m_vtable);
    if (!vtable) return;

    int offset = g_GameData.GetOffset(m_offsetName);
    if (offset == -1) return;

    m_pvtable = vtable;
    m_ioffset = offset;

    dyno::IHookManager& manager = dyno::IHookManager::Get();
    hookFunc = manager.hookVirtual(m_pvtable, m_ioffset, [this] { return new DEFAULT_CALLCONV(GetDataObjectList(m_function_args), GetDataObject(m_function_return)); }).get();

    hookFunc->addCallback(m_callbackType, m_handler);
}

void VFunctionHook::Enable()
{
    if (enabled) return;
    if (!m_pvtable) return;

    enabled = true;
    hookFunc->addCallback(m_callbackType, m_handler);
}

void VFunctionHook::Disable()
{
    if (!enabled) return;
    if (!m_pvtable) return;

    enabled = false;
    hookFunc->removeCallback(m_callbackType, m_handler);
}

std::any VFunctionHook::Call(std::vector<std::any> arguments)
{
    if (!m_pvtable) return nullptr;

    void* m_pfn = reinterpret_cast<void**>(m_pvtable)[m_ioffset];

    dcReset(vfunctionCallVM);
    dcMode(vfunctionCallVM, DC_CALL_C_DEFAULT);

    for (int i = 0; i < arguments.size(); i++) {
        if (m_function_args.size() <= i)
            break;

        if (m_function_args.at(i) == 'p') {
            if (arguments[i].type() == typeid(std::string)) {
                dcArgPointer(vfunctionCallVM, (void*)strtol(std::any_cast<std::string>(arguments[i]).c_str(), nullptr, 16));
            }
            else if (arguments[i].type() == typeid(ClassData*)) {
                dcArgPointer(vfunctionCallVM, std::any_cast<ClassData*>(arguments[i])->GetDataOr<void*>("ptr", nullptr));
            }
        }
        else if (m_function_args.at(i) == 'f')
            dcArgFloat(vfunctionCallVM, std::any_cast<float>(arguments[i]));
        else if (m_function_args.at(i) == 'b')
            dcArgBool(vfunctionCallVM, std::any_cast<bool>(arguments[i]));
        else if (m_function_args.at(i) == 'd')
            dcArgDouble(vfunctionCallVM, std::any_cast<double>(arguments[i]));
        else if (m_function_args.at(i) == 'i')
            dcArgInt(vfunctionCallVM, std::any_cast<int>(arguments[i]));
        else if (m_function_args.at(i) == 'u')
            dcArgLong(vfunctionCallVM, std::any_cast<uint32_t>(arguments[i]));
        else if (m_function_args.at(i) == 's')
            dcArgPointer(vfunctionCallVM, (void*)std::any_cast<std::string>(arguments[i]).c_str());
        else if (m_function_args.at(i) == 'I')
            dcArgLongLong(vfunctionCallVM, std::any_cast<int64_t>(arguments[i]));
        else if (m_function_args.at(i) == 'U')
            dcArgLongLong(vfunctionCallVM, std::any_cast<uint64_t>(arguments[i]));
        else
        {
            PRINTF("Invalid Data Type: '%c'.\n", m_function_args.at(i));
            break;
        }
    }

    std::any retval = nullptr;
    if (m_function_return == 'p')
        retval = new ClassData({ { "ptr", (void*)dcCallPointer(vfunctionCallVM, m_pfn) }, { "should_mark_freeable", true } }, "Memory", nullptr);
    else if (m_function_return == 'f')
        retval = (float)dcCallFloat(vfunctionCallVM, m_pfn);
    else if (m_function_return == 'b')
        retval = (bool)dcCallBool(vfunctionCallVM, m_pfn);
    else if (m_function_return == 'd')
        retval = (double)dcCallDouble(vfunctionCallVM, m_pfn);
    else if (m_function_return == 'i')
        retval = (int)dcCallInt(vfunctionCallVM, m_pfn);
    else if (m_function_return == 'u')
        retval = (uint32_t)dcCallInt(vfunctionCallVM, m_pfn);
    else if (m_function_return == 's')
        retval = std::string((const char*)dcCallPointer(vfunctionCallVM, m_pfn));
    else if (m_function_return == 'I')
        retval = (int64_t)dcCallLongLong(vfunctionCallVM, m_pfn);
    else if (m_function_return == 'U')
        retval = (uint64_t)dcCallLongLong(vfunctionCallVM, m_pfn);
    else if (m_function_return == 'v')
    {
        dcCallVoid(vfunctionCallVM, m_pfn);
        retval = nullptr;
    }
    else
    {
        PRINTF("Invalid return type: '%c'.\n", m_function_return);
        retval = nullptr;
    }

    return retval;
}