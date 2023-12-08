#ifndef _swiftly_h
#define _swiftly_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "playermanager.h"
#include <cstdarg>
#include <stdint.h>

#define SITE_A 0
#define SITE_B 1
#define SITE_UNKNOWN 2

typedef void (*PrintFunction)(const char *);
typedef const char *(*FetchTranslationFunction)(const char *);

void print(const char *str, ...);
const char *FetchTranslation(const char *key);
void Swiftly_Setup(const char *pluginName, const char *mainFilePath);

#endif