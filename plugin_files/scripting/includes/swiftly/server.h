#ifndef _swiftly_server_h
#define _swiftly_server_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "types.h"
#include "player.h"
#include "convar.h"
#include <stdlib.h>

class Server
{
private:
    std::vector<Player *> players;

public:
    Convars *cvars;

    Server()
    {
        this->cvars = new Convars();
    }
};

extern Server *server;

#endif