#ifndef _swiftly_server_h
#define _swiftly_server_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "types.h"
#include "convar.h"
#include <stdlib.h>

class Server
{
public:
    Convars *cvars;

    Server()
    {
        this->cvars = new Convars();
    }
};

extern Server *server;

#endif