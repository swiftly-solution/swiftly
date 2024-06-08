#ifndef _gvmixsubgraphswitchinterpolationtype_t_h
#define _gvmixsubgraphswitchinterpolationtype_t_h

enum class VMixSubgraphSwitchInterpolationType_t : uint64_t
{
    SUBGRAPH_INTERPOLATION_TEMPORAL_CROSSFADE = 0x0,
    SUBGRAPH_INTERPOLATION_TEMPORAL_FADE_OUT = 0x1,
    SUBGRAPH_INTERPOLATION_KEEP_LAST_SUBGRAPH_RUNNING = 0x2,
};

#endif