#ifndef _commands_h
#define _commands_h

#include "../player/Player.h"

class Command
{
private:
    void *m_funcPtr = nullptr;

public:
    Command(void *funcPtr) : m_funcPtr(funcPtr) {}
    void Exec(Player *player, std::vector<std::string> args, bool silent);
};

#endif