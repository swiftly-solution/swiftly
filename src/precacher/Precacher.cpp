#include "Precacher.h"
#include "../sig/Signatures.h"
#include "../common.h"

void Precacher::CacheModel(const char *model)
{
    g_Signatures->FetchSignature<PrecacheResource>("PrecacheResource")(model, this->precacheContext);
}