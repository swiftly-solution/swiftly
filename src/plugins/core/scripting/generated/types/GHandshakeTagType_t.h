#ifndef _ghandshaketagtype_t_h
#define _ghandshaketagtype_t_h

enum class HandshakeTagType_t : uint64_t
{
    eInvalid = 0xffffffffffffffff,
    eTask = 0x0,
    eMovement = 0x1,
    eCount = 0x2,
};

#endif