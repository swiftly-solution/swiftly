#ifndef _gsolveikchainanimnodedebugsetting_h
#define _gsolveikchainanimnodedebugsetting_h

enum class SolveIKChainAnimNodeDebugSetting : uint64_t
{
    SOLVEIKCHAINANIMNODEDEBUGSETTING_None = 0x0,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_X_Axis_Circle = 0x1,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_Y_Axis_Circle = 0x2,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_Z_Axis_Circle = 0x3,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_Forward = 0x4,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_Up = 0x5,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_Left = 0x6,
};

#endif