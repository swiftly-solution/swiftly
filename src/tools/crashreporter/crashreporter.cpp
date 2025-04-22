#include "crashreporter.h"
#include "callstack.h"

#include <vector>
#include <string>

#include <filesystem/files/files.h>
#include <core/entrypoint.h>
#include <tier0/icommandline.h>
#include <plugins/manager.h>

#ifndef GITHUB_SHA
#define GITHUB_SHA "LOCAL"
#endif

void WriteCrashDump(std::vector<std::string> functionStack);

std::string startup_cmd = "None";

const char* ws = " \t\n\r\f\v";

inline std::string& rtrim(std::string& s, const char* t = ws)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

inline std::string& ltrim(std::string& s, const char* t = ws)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

inline std::string& trim(std::string& s, const char* t = ws)
{
    return ltrim(rtrim(s, t), t);
}

#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#include <dbghelp.h>

LONG WINAPI CustomUnhandledExceptionFilter(EXCEPTION_POINTERS* pExceptionPointers);

bool BeginCrashListener() {
    if (!Files::ExistsPath("addons/swiftly/dumps"))
    {
        if (!Files::CreateDirectory("addons/swiftly/dumps"))
        {
            PLUGIN_PRINTF("Crash Listener", "Couldn't create dumps folder.\n");
            return false;
        }
    }

    startup_cmd = CommandLine()->GetCmdLine();
    std::vector<std::string> exp = explode(startup_cmd, " ");
    std::vector<std::string> exp2;
    for (std::size_t i = 1; i < exp.size(); i++)
    {
        std::string str = trim(exp[i]);
        if (str.length() == 0)
            continue;
        if (exp2.size() > 0)
            if (ends_with(exp2[exp2.size() - 1], "sv_setsteamaccount") || ends_with(exp2[exp2.size() - 1], "authkey") || ends_with(exp2[exp2.size() - 1], "ip"))
                str = "REDACTED";

        exp2.push_back(str);
    }
    startup_cmd = implode(exp2, " ");

    SetUnhandledExceptionFilter(CustomUnhandledExceptionFilter);
    return true;
}

void EndCrashListener() {
    SetUnhandledExceptionFilter(NULL);
}

LONG WINAPI CustomUnhandledExceptionFilter(EXCEPTION_POINTERS* pExceptionPointers)
{
    std::vector<std::string> functionStack;

    HANDLE hProcess = GetCurrentProcess();
    HANDLE hThread = GetCurrentThread();

    SymInitialize(hProcess, NULL, TRUE);

    CONTEXT* context = pExceptionPointers->ContextRecord;

    STACKFRAME64 stackFrame = { 0 };
#ifdef _M_X64
    DWORD machineType = IMAGE_FILE_MACHINE_AMD64;
    stackFrame.AddrPC.Offset = context->Rip;
    stackFrame.AddrPC.Mode = AddrModeFlat;
    stackFrame.AddrFrame.Offset = context->Rbp;
    stackFrame.AddrFrame.Mode = AddrModeFlat;
    stackFrame.AddrStack.Offset = context->Rsp;
    stackFrame.AddrStack.Mode = AddrModeFlat;
#else
#error "Platform not supported!"
#endif

    for (int frame = 0; frame < 64; ++frame)
    {
        if (!StackWalk64(machineType, hProcess, hThread, &stackFrame, context,
            NULL, SymFunctionTableAccess64, SymGetModuleBase64, NULL))
        {
            break;
        }

        DWORD64 address = stackFrame.AddrPC.Offset;
        if (address == 0) break;

        char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME] = {};
        SYMBOL_INFO* symbol = reinterpret_cast<SYMBOL_INFO*>(buffer);
        symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        symbol->MaxNameLen = MAX_SYM_NAME;

        std::string constructFunctionStr = "";
        DWORD64 displacement = 0;
        if (SymFromAddr(hProcess, address, &displacement, symbol))
        {
            constructFunctionStr += symbol->Name;
        }

        IMAGEHLP_LINE64 line;
        DWORD lineDisplacement = 0;
        memset(&line, 0, sizeof(line));
        line.SizeOfStruct = sizeof(line);

        if (SymGetLineFromAddr64(hProcess, address, &lineDisplacement, &line))
        {
            constructFunctionStr += (std::string(" -> ") + line.FileName + ":" + std::to_string(line.LineNumber - 2));
        }

        if (constructFunctionStr != "") functionStack.push_back(constructFunctionStr);
    }

    SymCleanup(hProcess);

    WriteCrashDump(functionStack);

    return EXCEPTION_EXECUTE_HANDLER;
}

#else
#include <backtrace.h>

static int full_callback(void* data, uintptr_t pc, const char* filename, int lineno, const char* function) {
    std::vector<std::string>& arr = *reinterpret_cast<std::vector<std::string>*>(data);
    std::string constructFunctionStr = "";
    if (filename && function) {
        constructFunctionStr += std::string(function) + " -> " + filename + ":" + std::to_string(lineno);
    }
    arr.push_back(constructFunctionStr);
    return 0;
}

static void error_callback(void*, const char* msg, int) {
    std::cerr << "libbacktrace error: " << msg << std::endl;
}

void signal_handler(int signumber)
{
    std::vector<std::string> functionStack;

    auto state = backtrace_create_state(nullptr, 1, error_callback, nullptr);
    backtrace_full(state, 0, full_callback, error_callback, &functionStack);

    WriteCrashDump(functionStack);
}

bool BeginCrashListener() {
    if (!Files::ExistsPath("addons/swiftly/dumps"))
    {
        if (!Files::CreateDirectory("addons/swiftly/dumps"))
        {
            PLUGIN_PRINTF("Crash Listener", "Couldn't create dumps folder.\n");
            return false;
        }
    }

    startup_cmd = CommandLine()->GetCmdLine();
    std::vector<std::string> exp = explode(startup_cmd, " ");
    std::vector<std::string> exp2;
    for (std::size_t i = 1; i < exp.size(); i++)
    {
        std::string str = trim(exp[i]);
        if (str.length() == 0)
            continue;
        if (exp2.size() > 0)
            if (ends_with(exp2[exp2.size() - 1], "sv_setsteamaccount") || ends_with(exp2[exp2.size() - 1], "authkey") || ends_with(exp2[exp2.size() - 1], "ip"))
                str = "REDACTED";

        exp2.push_back(str);
    }
    startup_cmd = implode(exp2, " ");

    ::signal(SIGSEGV, &signal_handler);

    return true;
}

void EndCrashListener() {
    ::signal(SIGSEGV, SIG_DFL);
}
#endif

std::string WritePluginsCallStack()
{
    std::string callstacks = "";
    for (auto plugin : g_pluginManager.GetPluginsList()) {
        auto callstack = g_callStack.GetPluginCallstack(plugin->GetName());
        if (callstack.size() > 0) {
            callstacks += string_format("Plugin %s:\n", plugin->GetName().c_str());
            for (auto it = callstack.begin(); it != callstack.end(); ++it)
                callstacks += string_format("    - %s\n", it->second.c_str());

            callstacks += "\n";
        }
    }
    return callstacks;
}

bool crashed = false;

void WriteCrashDump(std::vector<std::string> functionStack)
{
    if (crashed) return;

    crashed = true;
    PLUGIN_PRINTF("Crash Reporter", "A crash has occured and a dump has been created:\n");

    std::string file_path = string_format("addons/swiftly/dumps/crash.%s.log", get_uuid().c_str());
    if (Files::ExistsPath(file_path)) Files::Delete(file_path);

    TextTable backtraceTable('-', '|', '+');

    backtraceTable.add(" ID ");
    backtraceTable.add(" Data ");
    backtraceTable.endOfRow();

    for (int i = 0; i < functionStack.size(); i++) {
        backtraceTable.add(string_format(" %02d. ", i + 1));
        backtraceTable.add(string_format(" %s ", functionStack[i].c_str()));
        backtraceTable.endOfRow();

        functionStack[i] = string_format("%02d. %s", i + 1, functionStack[i].c_str());
    }

    PrintTextTable("Crash Reporter", backtraceTable);

    Files::Append(file_path, string_format("================================\nCommand: %s\nMap: %s\nVersion: %s (%s)\n================================\n\n%s\n\n%s", startup_cmd.c_str(), engine->GetServerGlobals() ? engine->GetServerGlobals()->mapname.ToCStr() : "None", g_Plugin.GetVersion(), GITHUB_SHA, implode(functionStack, "\n").c_str(), WritePluginsCallStack().c_str()), false);
    PLUGIN_PRINTF("Crash Reporter", "A dump log file has been created at: %s\n", file_path.c_str());
}