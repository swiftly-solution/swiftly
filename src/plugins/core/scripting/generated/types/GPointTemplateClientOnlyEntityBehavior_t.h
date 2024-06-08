#ifndef _gpointtemplateclientonlyentitybehavior_t_h
#define _gpointtemplateclientonlyentitybehavior_t_h

enum class PointTemplateClientOnlyEntityBehavior_t : uint64_t
{
    CREATE_FOR_CURRENTLY_CONNECTED_CLIENTS_ONLY = 0x0,
    CREATE_FOR_CLIENTS_WHO_CONNECT_LATER = 0x1,
};

#endif