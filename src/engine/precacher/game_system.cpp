/**
 * =============================================================================
 * CS2Fixes
 * Copyright (C) 2023-2024 Source2ZE
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "game_system.h"
#include "precacher.h"

CBaseGameSystemFactory** CBaseGameSystemFactory::sm_pFirst = nullptr;

CGameSystem g_GameSystem;
IGameSystemFactory* CGameSystem::sm_Factory = nullptr;

bool InitGameSystem()
{
    uint8_t* ptr = ((uint8_t*)g_GameData.FetchRawSignature("IGameSystem_InitAllSystems_pFirst")) + 3;
    if(!ptr) return false;

    uint32_t offset = *(uint32*)ptr;

    ptr += 4;

    CBaseGameSystemFactory::sm_pFirst = (CBaseGameSystemFactory**)(ptr + offset);

    CGameSystem::sm_Factory = new CGameSystemStaticFactory<CGameSystem>("Swiftly_GameSystem", &g_GameSystem);

    return true;
}

GS_EVENT_MEMBER(CGameSystem, BuildGameSessionManifest)
{
    IEntityResourceManifest* pResManifest = msg->m_pResourceManifest;

    g_precacher.CacheItems(pResManifest);
}