#include "CrashDump.h"

#ifdef _WIN32
bool BeginCrashListener() { return true; }
#else

#include <boost/stacktrace.hpp>
#include <boost/exception/all.hpp>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <random>

#include <tier0/icommandline.h>

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

void signal_handler(int signumber)
{
    try
    {
        auto boostStackTrace = boost::stacktrace::stacktrace();

        std::string stacktrace = boost::to_string(boost::stacktrace::stacktrace());
        std::string coredumpdata = stacktrace;
        std::vector<std::string> splitted_dump = explode(coredumpdata, "\n");
        PRINTF("Crash Reporter", "A crash has occured and a dump has been created:\n");
        for (int i = 0; i < splitted_dump.size() - 1; i++)
            PRINTF("Crash Reporter", "%s\n", splitted_dump[i].c_str());

        std::string file_path = string_format("addons/swiftly/dumps/crash.%s.log", get_uuid().c_str());
        if (Files::ExistsPath(file_path))
            Files::Delete(file_path);

        Files::Append(file_path, string_format("================================\nCommand: %s\nMap: %s\n================================\n\n%s", startup_cmd.c_str(), g_Plugin.GetMap().c_str(), coredumpdata.c_str()), false);
        PRINTF("Crash Reporter", "A dump log file has been created at: %s\n", file_path.c_str());
        PRINTF("Crash Reporter", "A crash report has been sent to Swiftly Crash Reporter Server.\n");

        rapidjson::Document document(rapidjson::kObjectType);

        document.AddMember(rapidjson::Value().SetString("coredumpdata", document.GetAllocator()), rapidjson::Value().SetString(coredumpdata.c_str(), document.GetAllocator()), document.GetAllocator());
        document.AddMember(rapidjson::Value().SetString("startup_cmd", document.GetAllocator()), rapidjson::Value().SetString(startup_cmd.c_str(), document.GetAllocator()), document.GetAllocator());
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

    ::signal(SIGSEGV, &signal_handler);

    return true;
}

#endif