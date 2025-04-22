/******************************************************************
 *
 * This feature is inspired from CounterStrikeSharp.
 * You can find the source code used by us in the following files:
 *
 * https://github.com/roflmuffin/CounterStrikeSharp/blob/a87bd25b48ff1407a71cfdce3222f5f55c8a2e0b/src/core/managers/voice_manager.h#L26
 * https://github.com/roflmuffin/CounterStrikeSharp/blob/a87bd25b48ff1407a71cfdce3222f5f55c8a2e0b/src/core/managers/voice_manager.cpp#L30
 *
 ******************************************************************/

#ifndef _voicemanager_h
#define _voicemanager_h

#include <core/entrypoint.h>

class VoiceManager
{
public:
    void OnAllInitialized();
    void OnShutdown();
    bool SetClientListening(CPlayerSlot iReceiver, CPlayerSlot iSender, bool bListen);
    void OnClientCommand(CPlayerSlot slot, const CCommand& args);
};

extern VoiceManager g_voiceManager;

#endif