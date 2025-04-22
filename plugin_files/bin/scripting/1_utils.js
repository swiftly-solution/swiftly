function LoadUtils(global) {
    const teamSelector = {
        "@ct": Team.CT,
        "@t": Team.T,
        "@spec": Team.Spectator
    }

    const lifeStateSelector = {
        "@alive": sdk.LifeState_t.LIFE_ALIVE,
        "@dying": sdk.LifeState_t.LIFE_DYING,
        "@dead": sdk.LifeState_t.LIFE_DEAD
    }

    const weaponlist = [
        "weapon_ak47",
        "weapon_aug",
        "weapon_awp",
        "weapon_bizon",
        "weapon_c4",
        "weapon_cz75a",
        "weapon_deagle",
        "weapon_decoy",
        "weapon_elite",
        "weapon_famas",
        "weapon_fiveseven",
        "weapon_flashbang",
        "weapon_g3sg1",
        "weapon_galilar",
        "weapon_glock",
        "weapon_healthshot",
        "weapon_hegrenade",
        "weapon_incgrenade",
        "weapon_knife",
        "weapon_m249",
        "weapon_m4a1",
        "weapon_mac10",
        "weapon_mag7",
        "weapon_molotov",
        "weapon_mp5sd",
        "weapon_mp7",
        "weapon_mp9",
        "weapon_negev",
        "weapon_nova",
        "weapon_p2000",
        "weapon_p250",
        "weapon_p90",
        "weapon_sawedoff",
        "weapon_scar20",
        "weapon_sg556",
        "weapon_smokegrenade",
        "weapon_ssg08",
        "weapon_tec9",
        "weapon_ump45",
        "weapon_usp_silencer",
        "weapon_xm1014"
    ]

    const itemlist = [
        "item_assaultsuit",
        "item_defuser",
        "item_kevlar",
    ]

    global.IsValidWeapon = (weapon) => {
        return weaponlist.includes(weapon)
    }

    global.IsValidItem = (item) => {
        return itemlist.includes(item)
    }

    global.ComputePrettyTime = (seconds) => {
        if (seconds == 0) return FetchTranslation("core.forever")
        else if (seconds < 60) return FetchTranslation("core.seconds").replace(new RegExp("{TIME}", "g"), String(seconds))
        else if (seconds < 3600) return FetchTranslation("core.minutes").replace(new RegExp("{TIME}", "g"), String(Math.floor(seconds / 60)))
        else if (seconds < 86400) return FetchTranslation("core.hours").replace(new RegExp("{TIME}", "g"), String(Math.floor(seconds / 3600)))
        else return FetchTranslation("core.days").replace(new RegExp("{TIME}", "g"), String(Math.floor(seconds / 86400)))
    }

    global.uuid = () => {
        const uuid = new Array(36);
        for (let i = 0; i < 36; i++) {
            uuid[i] = Math.floor(Math.random() * 16);
        }
        uuid[14] = 4;
        uuid[19] = uuid[19] &= ~(1 << 2);
        uuid[19] = uuid[19] |= (1 << 3);
        uuid[8] = uuid[13] = uuid[18] = uuid[23] = '-';
        return uuid.map((x) => x.toString(16)).join('');
    }

    global.ReplyToCommand = (playerid, prefix, str) => {
        if (playerid == -1) {
            console.log(str)
        } else {
            const player = GetPlayer(playerid)
            if (!player) return;
            if (player.IsFakeClient()) return;
            player.SendMsg(MessageType.Chat, `${prefix} ${str}`)
        }
    }

    global.FindPlayersByTarget = (target, matchbots) => {
        if (matchbots == null || matchbots == undefined) matchbots = true;

        let matchedPlayers = []

        for (let i = 0; i < playermanager.GetPlayerCap(); i++) {
            const player = GetPlayer(i)
            if (!player) continue;

            if (target == "@all") {
                matchedPlayers.push(player)
                continue;
            }

            if (target.startsWith("#")) {
                const pid = target.split("#").pop()
                if (pid == undefined) continue;

                if (String(i) == String(pid)) {
                    matchedPlayers.push(player)
                    continue
                }
            }

            if (teamSelector[target]) {
                const cbaseentity = sdk.CBaseEntity(player.CCSPlayerPawn())
                if (cbaseentity) {
                    if (cbaseentity.IsValid()) {
                        if (cbaseentity.TeamNum == teamSelector[target]) {
                            matchedPlayers.push(player)
                            continue
                        }
                    }
                }
            }

            if (lifeStateSelector[target]) {
                const cbaseentity = sdk.CBaseEntity(player.CCSPlayerPawn())
                if (cbaseentity) {
                    if (cbaseentity.IsValid()) {
                        if (cbaseentity.LifeState == lifeStateSelector[target]) {
                            matchedPlayers.push(player)
                            continue
                        }
                    }
                }
            }

            if (String(player.GetSteamID()) == target || player.GetSteamID2() == target) {
                matchedPlayers.push(player)
                continue;
            }

            const controller = player.CBasePlayerController()
            if (controller) {
                if (controller.IsValid()) {
                    if (controller.PlayerName.includes(target)) {
                        matchedPlayers.push(player)
                        continue;
                    }
                }
            }

            const [result, eventRet] = TriggerEvent("FindPlayerByTarget", i, target)
            const returnValue = eventRet.GetReturn()
            if (returnValue == true) {
                matchedPlayers.push(player)
                continue
            }
        }

        return matchedPlayers
    }
}

LoadUtils(globalThis)