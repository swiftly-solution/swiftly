#include "CrashDump.h"

#ifdef _WIN32
bool BeginCrashListener() { return true; }
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

#include "../files/Files.h"
#include "../http/HTTPManager.h"
#include "../common.h"

std::string get_uuid()
{
    static std::random_device dev;
    static std::mt19937 rng(dev());

    std::uniform_int_distribution<int> dist(0, 15);

    const char *v = "0123456789abcdef";
    const bool dash[] = {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0};

    std::string res;
    for (int i = 0; i < 16; i++)
    {
        if (dash[i])
            res += "-";
        res += v[dist(rng)];
        res += v[dist(rng)];
    }
    return res;
}

std::string startup_cmd = "None";

const char *ws = " \t\n\r\f\v";

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
                     i, int(2 + sizeof(void *) * 2), callstack[i],
                     status == 0 ? demangled : info.dli_sname == 0 ? symbols[i]
                                                                   : info.dli_sname,
                     (char *)callstack[i] - (char *)info.dli_saddr);
            free(demangled);
        }
        else
        {
            snprintf(buf, sizeof(buf), "%02d. %p %s\n",
                     i, callstack[i], symbols[i]);
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
        backtraceTable.add(string_format(" %02d. ", i));

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

        PRINTF("Crash Reporter", "A crash has occured and a dump has been created:\n");
        std::string backtraceData = BacktraceRaw();

        auto PrintTable = [](TextTable tbl) -> void
        {
            std::stringstream outputTable;
            outputTable << tbl;
            std::vector<std::string> rows = explode(outputTable.str(), "\n");
            for (int i = 0; i < rows.size(); i++)
                PRINTF("Crash Reporter", "%s\n", rows[i].c_str());
        };

        TextTable traceTable = GetBacktrace();
        PrintTable(traceTable);

        std::string file_path = string_format("addons/swiftly/dumps/crash.%s.log", get_uuid().c_str());
        if (Files::ExistsPath(file_path))
            Files::Delete(file_path);

        Files::Append(file_path, string_format("================================\nCommand: %s\nMap: %s\n================================\n\n%s", startup_cmd.c_str(), g_Plugin.GetMap().c_str(), backtraceData.c_str()), false);
        PRINTF("Crash Reporter", "A dump log file has been created at: %s\n", file_path.c_str());
        PRINTF("Crash Reporter", "A crash report has been sent to Swiftly Crash Reporter Server.\n");

        rapidjson::Document document(rapidjson::kObjectType);

        std::string empty_string = "";

        document.AddMember(rapidjson::Value().SetString("coredumpdata", document.GetAllocator()), rapidjson::Value().SetString(backtraceData.c_str(), document.GetAllocator()), document.GetAllocator());
        document.AddMember(rapidjson::Value().SetString("startup_cmd", document.GetAllocator()), rapidjson::Value().SetString(empty_string.c_str(), document.GetAllocator()), document.GetAllocator());
        document.AddMember(rapidjson::Value().SetString("map", document.GetAllocator()), rapidjson::Value().SetString(g_Plugin.GetMap().c_str(), document.GetAllocator()), document.GetAllocator());

        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);

        std::string json = std::string(buffer.GetString());

        uint64_t requestid = g_httpManager->CreateRequest("https://crashreporter.swiftlycs2.net");
        HTTPRequest *req = g_httpManager->FetchRequest(requestid);
        req->SetBody(json);
        req->SetContentType(ContentType::APPLICATION_JSON);
        req->Post("/");
        g_httpManager->DeleteRequest(requestid);
    }
    catch (const std::runtime_error &e)
    {
        PRINTF("Crash Reporter", "Error crash handling: %s\n", e.what());
    }

    exit(EXIT_FAILURE);
}

bool BeginCrashListener()
{
    if (!Files::ExistsPath("addons/swiftly/dumps"))
    {
        if (!Files::CreateDirectory("addons/swiftly/dumps"))
        {
            PRINTF("Crash Listener", "Couldn't create dumps folder.\n");
            return false;
        }
    }

    ::signal(SIGSEGV, &signal_handler);

    startup_cmd = CommandLine()->GetCmdLine();
    std::vector<std::string> exp = explode(startup_cmd, " ");
    std::vector<std::string> exp2;
    for (int i = 1; i < exp.size(); i++)
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

#endif