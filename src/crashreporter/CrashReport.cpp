#include "CrashReport.h"

#ifdef _WIN32
bool BeginCrashListener() { return true; }
void CrashReporterListener() {}
#else

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <execinfo.h>
#include <dlfcn.h>
#include <cxxabi.h>
#include <signal.h>

#include <tier0/icommandline.h>

#include <TextTable.h>
#include <sstream>

#include <random>
#include <atomic>

#include "../files/Files.h"
#include "../common.h"
#include "../entrypoint.h"

std::string startup_cmd = "None";

const char *ws = " \t\n\r\f\v";

std::atomic<bool> exitProgram(false);

// trim from end of string (right)
inline std::string &rtrim(std::string &s, const char *t = ws)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from beginning of string (left)
inline std::string &ltrim(std::string &s, const char *t = ws)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from both ends of string (right then left)
inline std::string &trim(std::string &s, const char *t = ws)
{
    return ltrim(rtrim(s, t), t);
}

std::string BacktraceRaw(int skip = 1)
{
    void *callstack[128];
    const int nMaxFrames = sizeof(callstack) / sizeof(callstack[0]);
    char buf[1024];
    int nFrames = backtrace(callstack, nMaxFrames);
    char **symbols = backtrace_symbols(callstack, nFrames);

    std::ostringstream trace_buf;
    for (int i = skip; i < nFrames; i++)
    {
        Dl_info info;
        if (dladdr(callstack[i], &info) && info.dli_sname)
        {
            char *demangled = NULL;
            int status = -1;
            if (info.dli_sname[0] == '_')
                demangled = abi::__cxa_demangle(info.dli_sname, NULL, 0, &status);
            snprintf(buf, sizeof(buf), "%02d. %p %s + %zd\n",
                     i - 1, callstack[i],
                     status == 0 ? demangled : info.dli_sname == 0 ? symbols[i]
                                                                   : info.dli_sname,
                     (char *)callstack[i] - (char *)info.dli_saddr);
            free(demangled);
        }
        else
        {
            snprintf(buf, sizeof(buf), "%02d. %p %s\n",
                     i - 1, callstack[i], symbols[i]);
        }
        trace_buf << buf;
    }
    free(symbols);
    if (nFrames == nMaxFrames)
        trace_buf << "[truncated]\n";
    return trace_buf.str();
}

TextTable GetBacktrace()
{
    TextTable backtraceTable('-', '|', '+');

    backtraceTable.add(" ID ");
    backtraceTable.add(" File ");
    backtraceTable.add(" Function ");
    backtraceTable.add(" Offset ");
    backtraceTable.add(" Address ");
    backtraceTable.endOfRow();

    void *callstack[128];
    const int nMaxFrames = sizeof(callstack) / sizeof(callstack[0]);
    char buf[1024];
    int nFrames = backtrace(callstack, nMaxFrames);
    char **symbols = backtrace_symbols(callstack, nFrames);

    for (int i = 2; i < nFrames; i++)
    {
        backtraceTable.add(string_format(" %02d. ", i - 1));

        std::vector<std::string> symbolExploded = explode(symbols[i], "/");
        backtraceTable.add(string_format(" %s ", explode(symbolExploded[symbolExploded.size() - 1], "(")[0].c_str()));

        Dl_info info;
        if (dladdr(callstack[i], &info) && info.dli_sname)
        {
            char *demangled = NULL;
            int status = -1;
            if (info.dli_sname[0] == '_')
                demangled = abi::__cxa_demangle(info.dli_sname, NULL, 0, &status);

            std::string funcName = (status == 0 ? demangled : info.dli_sname == 0 ? "-"
                                                                                  : info.dli_sname);

            backtraceTable.add(string_format(" %s ", (funcName.size() > 36 ? (funcName.substr(0, 33) + "...") : funcName).c_str()));
            free(demangled);
        }
        else
            backtraceTable.add(" - ");

        backtraceTable.add(string_format(" %s ", explode(explode(symbolExploded[symbolExploded.size() - 1], "+")[1], ")")[0].c_str()));
        backtraceTable.add(string_format(" %p ", callstack[i]));
        backtraceTable.endOfRow();
    }
    free(symbols);

    return backtraceTable;
}

void signal_handler(int signumber)
{
    try
    {
        void *tracePointers[20];
        size_t count = backtrace(tracePointers, 20);

        PLUGIN_PRINTF("Crash Reporter", "A crash has occured and a dump has been created:\n");
        std::string backtraceData = BacktraceRaw();

        TextTable traceTable = GetBacktrace();
        PrintTextTable("Crash Reporter", traceTable);

        std::string file_path = string_format("addons/swiftly/dumps/crash.%s.log", get_uuid().c_str());
        if (Files::ExistsPath(file_path))
            Files::Delete(file_path);

        Files::Append(file_path, string_format("================================\nCommand: %s\nMap: %s\n================================\n\n%s", startup_cmd.c_str(), engine->GetServerGlobals() ? engine->GetServerGlobals()->mapname.ToCStr() : "None", backtraceData.c_str()), false);
        PLUGIN_PRINTF("Crash Reporter", "A dump log file has been created at: %s\n", file_path.c_str());
    }
    catch (const std::runtime_error &e)
    {
        PLUGIN_PRINTF("Crash Reporter", "Error crash handling: %s\n", e.what());
    }

    exitProgram = true;
}

bool BeginCrashListener()
{
    if (!Files::ExistsPath("addons/swiftly/dumps"))
    {
        if (!Files::CreateDirectory("addons/swiftly/dumps"))
        {
            PLUGIN_PRINTF("Crash Listener", "Couldn't create dumps folder.\n");
            return false;
        }
    }

    ::signal(SIGSEGV, &signal_handler);
    ::signal(SIGABRT, &signal_handler);

    startup_cmd = CommandLine()->GetCmdLine();
    std::vector<std::string> exp = explode(startup_cmd, " ");
    std::vector<std::string> exp2;
    for (std::size_t i = 1; i < exp.size(); i++)
    {
        std::string str = trim(exp[i]);
        if (str.length() == 0)
            continue;
        if (exp2.size() > 0)
            if (ends_with(exp2[exp2.size() - 1], "sv_setsteamaccount") || ends_with(exp2[exp2.size() - 1], "authkey"))
                str = "REDACTED";

        exp2.push_back(str);
    }
    startup_cmd = implode(exp2, " ");

    return true;
}

void CrashReporterListener()
{
    if (exitProgram.load())
        exit(EXIT_FAILURE);
}

#endif