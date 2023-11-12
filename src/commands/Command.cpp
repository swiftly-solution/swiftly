#include "Command.h"
#include "../common.h"

typedef void (*Command_Main)(int, const char **, uint32, bool);

void Command::Exec(int slot, std::vector<std::string> args, bool silent)
{
    if (this->m_funcPtr == nullptr)
        return;

    const char *toSendArgs[512] = {};
    for (uint32_t i = 0; i < args.size(); i++)
        toSendArgs[i] = args[i].c_str();

    reinterpret_cast<Command_Main>(this->m_funcPtr)(slot, reinterpret_cast<const char **>(toSendArgs), args.size(), silent);
}