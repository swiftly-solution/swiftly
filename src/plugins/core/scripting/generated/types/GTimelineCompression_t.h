#ifndef _gtimelinecompression_t_h
#define _gtimelinecompression_t_h

enum class TimelineCompression_t : uint64_t
{
    TIMELINE_COMPRESSION_SUM = 0x0,
    TIMELINE_COMPRESSION_COUNT_PER_INTERVAL = 0x1,
    TIMELINE_COMPRESSION_AVERAGE = 0x2,
    TIMELINE_COMPRESSION_AVERAGE_BLEND = 0x3,
    TIMELINE_COMPRESSION_TOTAL = 0x4,
};

#endif