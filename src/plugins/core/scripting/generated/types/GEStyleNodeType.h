#ifndef _gestylenodetype_h
#define _gestylenodetype_h

enum class EStyleNodeType : uint64_t
{
    ROOT = 0x0,
    EXPRESSION = 0x1,
    PROPERTY = 0x2,
    DEFINE = 0x3,
    IMPORT = 0x4,
    KEYFRAMES = 0x5,
    KEYFRAME_SELECTOR = 0x6,
    STYLE_SELECTOR = 0x7,
    WHITESPACE = 0x8,
    EXPRESSION_TEXT = 0x9,
    EXPRESSION_URL = 0xa,
    EXPRESSION_CONCAT = 0xb,
    REFERENCE_CONTENT = 0xc,
    REFERENCE_COMPILED = 0xd,
    REFERENCE_PASSTHROUGH = 0xe,
    COMPILER_CONDITIONAL = 0xf,
};

#endif