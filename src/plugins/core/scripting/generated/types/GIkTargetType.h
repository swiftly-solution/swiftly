#ifndef _giktargettype_h
#define _giktargettype_h

enum class IkTargetType : uint64_t
{
    IkTarget_Attachment = 0x0,
    IkTarget_Bone = 0x1,
    IkTarget_Parameter_ModelSpace = 0x2,
    IkTarget_Parameter_WorldSpace = 0x3,
};

#endif