/**
 * =============================================================================
 * CS2Fixes
 * Copyright (C) 2023 Source2ZE
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

#pragma once
#include <tier0/dbg.h>
#include <tier0/interface.h>
#include <tier1/strtools.h>
#include <tier0/platform.h>
#include "plat.h"

#ifdef _WIN32
#include <Psapi.h>
#endif

class CModule
{
public:
    CModule(const char *path, const char *module) : m_pszModule(module), m_pszPath(path)
    {
        V_snprintf(this->szModule, MAX_PATH, "%s%s%s%s%s", Plat_GetGameDirectory(), path, MODULE_PREFIX, m_pszModule, MODULE_EXT);

        m_hModule = dlmount(this->szModule);

        if (!m_hModule)
            failed = true;

#ifdef _WIN32
        MODULEINFO m_hModuleInfo;
        GetModuleInformation(GetCurrentProcess(), m_hModule, &m_hModuleInfo, sizeof(m_hModuleInfo));

        m_base = (void *)m_hModuleInfo.lpBaseOfDll;
        m_size = m_hModuleInfo.SizeOfImage;
#else
        if (int e = GetModuleInformation(m_hModule, &m_base, &m_size))
            failed = true;
#endif
    }

    void *FindSignature(const byte *pData, size_t iSigLength)
    {
        unsigned char *pMemory;
        void *return_addr = nullptr;

        pMemory = (byte *)m_base;

        for (size_t i = 0; i < m_size; i++)
        {
            size_t Matches = 0;
            while (*(pMemory + i + Matches) == pData[Matches] || pData[Matches] == '\x2A')
            {
                Matches++;
                if (Matches == iSigLength)
                    return_addr = (void *)(pMemory + i);
            }
        }

        return return_addr;
    }

    const char *m_pszModule;
    const char *m_pszPath;
    HINSTANCE m_hModule;
    void *m_base;
    size_t m_size;
    bool failed = false;
    char szModule[MAX_PATH];
};