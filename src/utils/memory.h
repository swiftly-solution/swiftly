#ifndef _utils_memory_h
#define _utils_memory_h

#include <dynlibutils/module.h>

DynLibUtils::CMemory FindVirtTable(DynLibUtils::CModule *_this, const std::string_view svTableName, int32_t offset = 0, bool bDecorated = false);

#endif