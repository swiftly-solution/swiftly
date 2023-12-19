#ifndef _swiftly_h
#define _swiftly_h

#include "swiftly_memory.h"
#include "playermanager.h"
#include "swiftly_utils.h"
#include "swiftly_scripting_utils.h"
#include <cstdarg>
#include <stdint.h>

#define NOT_SUPPORTED(func_name) print("[Swiftly] This version of Swiftly is not supporting %s.\n", func_name)

#define SITE_A 0
#define SITE_B 1
#define SITE_UNKNOWN 2

typedef void (*PrintFunction)(const char *);
typedef const char *(*FetchTranslationFunction)(const char *);

void print(const char *str, ...);
const char *FetchTranslation(const char *key);
void Swiftly_Setup(const char *pluginName, const char *mainFilePath);

#endif