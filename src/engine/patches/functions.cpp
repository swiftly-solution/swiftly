#include <memory/hooks/functions.h>
#include <tier1/generichash.h>

#define SOUNDEVENT_PARAM_MURMURHASH_SEED 0x31415926
const uint32_t OLD_VOLUME_HASH = MurmurHash2LowerCase("public.volume_atten", SOUNDEVENT_PARAM_MURMURHASH_SEED);
const uint32_t NEW_VOLUME_HASH = MurmurHash2LowerCase("public.volume", SOUNDEVENT_PARAM_MURMURHASH_SEED);

#ifdef _WIN32
#define SETSOUNDEVENTPARAM_HASH_INDEX 3
#else
#define SETSOUNDEVENTPARAM_HASH_INDEX 2
#endif

dyno::ReturnAction Hook_CSoundOpGameSystem_SetSoundEventParam(dyno::CallbackType cbType, dyno::IHook& hook)
{
    uint32_t hash = hook.getArgument<uint32_t>(SETSOUNDEVENTPARAM_HASH_INDEX);
    if (hash == OLD_VOLUME_HASH) {
        hook.setArgument<uint32_t>(SETSOUNDEVENTPARAM_HASH_INDEX, NEW_VOLUME_HASH);
    }
    return dyno::ReturnAction::Handled;
}

FunctionHook CSoundOpGameSystem_SetSoundEventParam("CSoundOpGameSystem_SetSoundEventParam", dyno::CallbackType::Pre, Hook_CSoundOpGameSystem_SetSoundEventParam, "pppupuu", 'p');
