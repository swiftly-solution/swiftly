add_rules("mode.debug", "mode.release")

includes("@builtin/xpack")
includes("core.base.option")
includes("platform.os")

local SDK_PATH = os.getenv("HL2SDK")
local MM_PATH = os.getenv("MMSOURCE")
local GITHUB_SHA = os.getenv("GITHUB_SHA") or "Local"
local SWIFTLY_VERSION = os.getenv("SWIFTLY_VERSION") or "Local"
local PROJECT_NAME = "swiftly"
local PORJECT_NAME_ALIAS = "swiftly"

function GetDistDirName()
    if is_plat("windows") then
        return "win64"
    else
        return "linuxsteamrt64"
    end
end

target(PROJECT_NAME.."-CS2")
    set_kind("shared")
    set_optimize("fastest")
    set_strip("none")

    add_files("build/proto/**.cc")

    --[[ Vendor Section ]]

    add_files("vendor/lua-rapidjson/src/**.cpp")
    add_files("vendor/asmjit/src/asmjit/**.cpp")
    add_files("vendor/asmtk/src/asmtk/**.cpp")
    add_files("vendor/embedder/src/**.cpp", { cxxflags = "-rdynamic -g1" })

    --[[ Embedder Section ]]

    before_build(function(target)
        import("core.base.json")

        function GetDistDirName()
            if is_plat("windows") then
                return "windows"
            else
                return "linux"
            end
        end

        local config_path = path.join(os.scriptdir(), "vendor/embedder/libs/links.json")
        local config_data = json.loadfile(config_path)

        for i=1,#config_data.includes do
            target:add("includedirs", "vendor/embedder/libs/"..config_data.includes[i])
        end

        local libs = config_data.libraries[GetDistDirName()]
        for i=1,#libs do
            target:add("links", "vendor/embedder/libs/"..libs[i])
        end
    end)

    --[[ Plugin Section ]]

    add_files({
        'src/core/entrypoint.cpp',
        "src/core/commands/chat.cpp",
        "src/core/commands/cmds.cpp",
        "src/core/commands/config.cpp",
        "src/core/commands/core.cpp",
        "src/core/commands/credits.cpp",
        "src/core/commands/cvars.cpp",
        "src/core/commands/exts.cpp",
        "src/core/commands/help.cpp",
        "src/core/commands/list.cpp",
        "src/core/commands/plugins.cpp",
        "src/core/commands/resmon.cpp",
        "src/core/commands/status.cpp",
        "src/core/commands/translations.cpp",
        "src/core/commands/utils.cpp",
        "src/core/commands/version.cpp",
        'src/core/configuration/setup.cpp',
        'src/core/console/console.cpp',

        'src/engine/convars/manager.cpp',
        'src/engine/convars/query.cpp',

        'src/engine/gameevents/gameevents.cpp',

        'src/engine/precacher/game_system.cpp',
        'src/engine/precacher/precacher.cpp',

        'src/engine/vgui/screentext.cpp',
        'src/engine/vgui/vgui.cpp',
        
        'src/engine/voicemanager/manager.cpp',

        'src/entities/system.cpp',
        'src/entities/listener.cpp',

        'src/extensions/manager.cpp',
        'src/extensions/extension.cpp',

        'src/filesystem/files/files.cpp',
        'src/filesystem/logs/logger.cpp',
        'src/filesystem/logs/log.cpp',

        'src/memory/encoders/json.cpp',
        'src/memory/gamedata/gamedata.cpp',
        'src/memory/hooks/manager.cpp',
        'src/memory/hooks/functions.cpp',
        'src/memory/hooks/vfunctions.cpp',

        'src/network/database/DatabaseManager.cpp',
        'src/network/usermessages/usermessage.cpp',
        'src/network/usermessages/usermessages.cpp',

        'src/plugins/manager.cpp',
        'src/plugins/object.cpp',

        'src/scripting/engine/convars.cpp',
        'src/scripting/engine/entities.cpp',
        'src/scripting/engine/events.cpp',
        'src/scripting/engine/gameevents.cpp',
        'src/scripting/engine/precacher.cpp',
        'src/scripting/engine/server.cpp',
        'src/scripting/engine/vgui.cpp',

        'src/scripting/entities/weapons.cpp',

        'src/scripting/memory/memory.cpp',
        'src/scripting/memory/hooks.cpp',
        'src/scripting/memory/keyvalues/centitykeyvalues.cpp',

        'src/scripting/network/database.cpp',
        'src/scripting/network/usermessage.cpp',

        'src/scripting/player/manager.cpp',
        'src/scripting/player/player.cpp',

        'src/scripting/filesystem/files.cpp',
        'src/scripting/filesystem/logger.cpp',

        'src/scripting/sdk/baseclasses.cpp',
        'src/scripting/sdk/chandle.cpp',
        'src/scripting/sdk/checktransmit.cpp',
        'src/scripting/sdk/coretypes.cpp',
        'src/scripting/sdk/schema_access.cpp',
        'src/scripting/sdk/schema.cpp',
        'src/scripting/sdk/types.cpp',

        'src/scripting/server/commands.cpp',
        'src/scripting/server/configuration.cpp',
        'src/scripting/server/menus.cpp',
        'src/scripting/server/translations.cpp',
        'src/scripting/server/utils.cpp',

        'src/scripting/core.cpp',
        'src/scripting/stack.cpp',
        
        'src/sdk/access.cpp',
        'src/sdk/schema.cpp',
        'src/sdk/game.cpp',

        'src/server/chat/chat.cpp',

        'src/server/commands/command.cpp',
        'src/server/commands/manager.cpp',

        'src/server/configuration/configuration.cpp',

        'src/server/menus/kinds/CenterMenu.cpp',
        'src/server/menus/kinds/ScreenMenu.cpp',
        'src/server/menus/MenuManager.cpp',
        'src/server/menus/MenuRenderer.cpp',

        'src/server/player/manager.cpp',
        'src/server/player/player.cpp',

        'src/server/translations/translation.cpp',
        'src/server/translations/translations.cpp',

        'src/tools/crashreporter/callstack.cpp',
        'src/tools/crashreporter/crashreporter.cpp',
        'src/tools/resourcemonitor/monitor.cpp',
        
        'src/utils/utils.cpp',
        'src/utils/memory_win.cpp',
        'src/utils/memory_linux.cpp',
        'src/utils/platform/platform_win.cpp',
        'src/utils/platform/platform_linux.cpp',

        "vendor/dynlibutils/module.cpp",

        SDK_PATH.."/tier1/keyvalues3.cpp",
        SDK_PATH.."/entity2/entitysystem.cpp",
        SDK_PATH.."/entity2/entityidentity.cpp",
        SDK_PATH.."/tier1/convar.cpp",
        SDK_PATH.."/entity2/entitykeyvalues.cpp",
    }, { cxxflags = "-rdynamic -g1" })

    --[[ Protobuf Section ]]

    on_load(function(target)
        local protoc = is_plat("windows") and SDK_PATH.."/devtools/bin/protoc.exe" or SDK_PATH.."/devtools/bin/linux/protoc" 
        local args = "--proto_path="..SDK_PATH.."/thirdparty/protobuf-3.21.8/src --proto_path=./protobufs/cs2 --proto_path="..SDK_PATH.."/public --proto_path="..SDK_PATH.."/public/engine --proto_path="..SDK_PATH.."/public/mathlib --proto_path="..SDK_PATH.."/public/vstdlib --proto_path="..SDK_PATH.."/public/tier0 --proto_path="..SDK_PATH.."/public/tier1 --proto_path="..SDK_PATH.."/public/entity2 --proto_path="..SDK_PATH.."/public/game/server --proto_path="..SDK_PATH.."/game/shared --proto_path="..SDK_PATH.."/game/server --proto_path="..SDK_PATH.."/common --cpp_out=build/proto"

        function mysplit (inputstr, sep)
            if sep == nil then sep = "%s" end
            local t={}
            for str in string.gmatch(inputstr, "([^"..sep.."]+)") do table.insert(t, str) end
            return t
        end
    
        if os.exists("build/proto") then
            os.rmdir("build/proto")
        end
        os.mkdir("build/proto")

        for _, sourcefile in ipairs(os.files("./protobufs/cs2/*.proto")) do
            local splitted = mysplit(sourcefile, "/")
            local filename = splitted[#splitted]

            os.iorun(protoc .. " "..args.." --dependency_out=build/proto/"..filename..".d "..sourcefile)
        end
    end)

    --[[ Flags Section ]]

    add_cxxflags("gcc::-Wno-invalid-offsetof")
    add_cxxflags("gcc::-Wno-return-local-addr")
    add_cxxflags("gcc::-Wno-overloaded-virtual")
    add_cxxflags("gcc::-Wno-unknown-pragmas")
    add_cxxflags("gcc::-Wno-non-virtual-dtor")
    add_cxxflags("gcc::-Wno-attributes")
    add_cxxflags("gcc::-Wno-array-bounds")
    add_cxxflags("gcc::-Wno-int-to-pointer-cast")
    add_cxxflags("gcc::-Wno-sign-compare")
    add_cxxflags("gcc::-Wno-write-strings")
    add_cxxflags("gcc::-Wno-class-memaccess")
    add_cxxflags("gcc::-fexceptions")
    add_cxxflags("gcc::-fPIC")
    
    add_cflags("gcc::-Wno-return-local-addr")
    add_cflags("gcc::-Wno-unknown-pragmas")
    add_cflags("gcc::-Wno-attributes")
    add_cflags("gcc::-Wno-array-bounds")
    add_cflags("gcc::-Wno-int-to-pointer-cast")
    add_cflags("gcc::-Wno-sign-compare")
    add_cflags("gcc::-Wno-write-strings")
    add_cflags("gcc::-fexceptions")
    add_cflags("gcc::-fPIC")
    add_cflags("gcc::-pipe")
    add_cflags("gcc::-fno-strict-aliasing")
    add_cflags("gcc::-Wall")
    add_cflags("gcc::-Wno-uninitialized")
    add_cflags("gcc::-Wno-unused")
    add_cflags("gcc::-Wno-switch")
    add_cflags("gcc::-msse")
    add_cflags("gcc::-fvisibility=hidden")
    add_cflags("gcc::-mfpmath=sse")
    add_cflags("gcc::-fno-omit-frame-pointer")
    add_cflags("gcc::-fvisibility-inlines-hidden")
    add_cflags("gcc::-fno-exceptions")
    add_cflags("gcc::-fno-threadsafe-statics")
    add_cflags("gcc::-Wno-register")
    add_cflags("gcc::-Wno-delete-non-virtual-dtor")

    add_cxxflags("cl::/Zc:__cplusplus")
    add_cxxflags("cl::/Ox")
    add_cxxflags("cl::/Zo")
    add_cxxflags("cl::/Oy-")
    add_cxxflags("cl::/Z7")
    add_cxxflags("cl::/TP")
    add_cxxflags("cl::/MT")
    add_cxxflags("cl::/W3")
    add_cxxflags("cl::/Z7")
    add_cxxflags("cl::/EHsc")
    add_cxxflags("cl::/IGNORE:4101,4267,4244,4005,4003,4530")

    --[[ HL2SDK Mandatory Libs ]]
    if is_plat("windows") then
        add_links({
            SDK_PATH.."/lib/public/win64/tier0.lib",
            SDK_PATH.."/lib/public/win64/tier1.lib",
            SDK_PATH.."/lib/public/win64/interfaces.lib",
            SDK_PATH.."/lib/public/win64/mathlib.lib",
            SDK_PATH.."/lib/public/win64/2015/libprotobuf.lib",
        })
    else
        add_links({
            SDK_PATH.."/lib/linux64/libtier0.so",
            SDK_PATH.."/lib/linux64/tier1.a",
            SDK_PATH.."/lib/linux64/interfaces.a",
            SDK_PATH.."/lib/linux64/mathlib.a",
            SDK_PATH.."/lib/linux64/release/libprotobuf.a",
        })
    end

    --[[ Includes Section ]]

    add_includedirs({
        SDK_PATH,
        SDK_PATH.."/public",
        SDK_PATH.."/public/entity2",
        SDK_PATH.."/game/server",
        SDK_PATH.."/thirdparty/protobuf-3.21.8/src",
        SDK_PATH.."/common",
        SDK_PATH.."/game/shared",
        SDK_PATH.."/public/engine",
        SDK_PATH.."/public/mathlib",
        SDK_PATH.."/public/tier0",
        SDK_PATH.."/public/tier1",
        SDK_PATH.."/public/game/server",
        SDK_PATH.."/public/mathlib",
        MM_PATH.."/core",
        MM_PATH.."/core/sourcehook"
    })

    add_includedirs({
        "vendor",
        "vendor/lua-rapidjson/rapidjson/include",
        "vendor/bzip2/"..GetDistDirName().."/include",
        "vendor/dynohook/"..GetDistDirName().."/include",
        "vendor/dynohook/"..GetDistDirName().."/include/dynohook",
        "vendor/dyncall/"..GetDistDirName().."/include",
        "vendor/asmjit/src",
        "vendor/asmtk/src",
        "src",
        "build/proto",
        SDK_PATH
    })

    --[[ Defines Section ]]

    if(is_plat("windows")) then
        add_defines({
            "COMPILER_MSVC",
            "COMPILER_MSVC64",
            "WIN32",
            "WINDOWS",
            "CRT_SECURE_NO_WARNINGS",
            "CRT_SECURE_NO_DEPRECATE",
            "CRT_NONSTDC_NO_DEPRECATE",
            "_MBCS",
            "META_IS_SOURCE2",
            "COMPILER_MSVC",
            "COMPILER_MSVC64",
            "WIN32",
            "_WIN32",
            "WINDOWS",
            "_WINDOWS",
            "CRT_SECURE_NO_WARNINGS",
            "_CRT_SECURE_NO_WARNINGS",
            "CRT_SECURE_NO_DEPRECATE",
            "_CRT_SECURE_NO_DEPRECATE",
            "CRT_NONSTDC_NO_DEPRECATE",
            "_CRT_NONSTDC_NO_DEPRECATE",
            "_MBCS",
            "META_IS_SOURCE2",
            "X64BITS",
            "PLATFORM_64BITS",
            "NDEBUG",
            "JSON_HAS_CPP_14",
            "JSON_HAS_CPP_11"
        })
    else
        add_defines({
            "_LINUX",
            "LINUX",
            "POSIX",
            "GNUC",
            "COMPILER_GCC",
            "PLATFORM_64BITS",
            "META_IS_SOURCE2",
            "_GLIBCXX_USE_CXX11_ABI=0",

            "_vsnprintf=vsnprintf",
            "_alloca=alloca",
            "strcmpi=strcasecmp",
            "strnicmp=strncasecmp",
            "_snprintf=snprintf",
            "_stricmp=strcasecmp",
            "_strnicmp=strncasecmp",
            "stricmp=strcasecmp",
        })
    end

    add_defines({
        "GITHUB_SHA=\""..GITHUB_SHA.."\"",
        "SWIFTLY_VERSION=\""..SWIFTLY_VERSION.."\"",
        "ASMJIT_STATIC",
        "HAVE_STRUCT_TIMESPEC",
        "LUA_USE_LINUX",
        "LUA_USE_READLINE",
    })

    --[[ Vendor Libraries ]]

    if is_plat("windows") then
        add_links({
            "psapi",
            "winmm",
            "ws2_32",
            "wldap32",
            "advapi32",
            "kernel32",
            "comdlg32",
            "crypt32",
            "normaliz",
            "wsock32",
            "legacy_stdio_definitions",
            "legacy_stdio_wide_specifiers",
            "user32",
            "gdi32",
            "winspool",
            "shell32",
            "ole32",
            "oleaut32",
            "uuid",
            "odbc32",
            "odbccp32",
            "msvcrt",
            "dbghelp",
            SDK_PATH.."/lib/public/win64/steam_api64.lib",
            
            "vendor/dyncall/win64/lib/dyncall_s.lib",
            "vendor/dynohook/win64/lib/dynohook.lib",
            "vendor/dynohook/win64/lib/Zydis.lib",
            "vendor/bzip2/win64/lib/bz2.lib",
        })
    else
        add_links({
            "gnutls",
            "z",
            "pthread",
            "ssl",
            "crypto",
            "m",
            "dl",
            "readline",
            "rt",
            "idn2",
            "psl",
            "brotlidec",
            "backtrace",
            "stdc++",

            SDK_PATH.."/lib/linux64/libsteam_api.so",
            "vendor/dyncall/linuxsteamrt64/lib/libdyncall_s.a",
            "vendor/dynohook/linuxsteamrt64/lib/libdynohook.a",
            "vendor/dynohook/linuxsteamrt64/lib/libZydis.a",
            "vendor/bzip2/linuxsteamrt64/lib/libbz2.a",
        })
    end

    --[[ Misc Section ]]

    set_languages("cxx17")

    after_build(function(target)
        import("core.base.json")
        
        function GetDistDirName()
            if is_plat("windows") then
                return "win64"
            else
                return "linuxsteamrt64"
            end
        end

        local config_path = path.join(os.scriptdir(), "vendor/embedder/libs/links.json")
        local config_data = json.loadfile(config_path)
        
        if os.exists("build/package") then
            os.rmdir("build/package")
        end
        
        os.mkdir('build/package/addons/metamod')
        os.cp("plugin_files/", 'build/package/addons/'..PROJECT_NAME)
        os.mkdir('build/package/addons/'..PROJECT_NAME.."/bin/"..GetDistDirName())
        os.cp(target:targetfile(), 'build/package/addons/'..PROJECT_NAME.."/bin/"..GetDistDirName().."/"..PROJECT_NAME.."."..(is_plat("windows") and "dll" or "so"))
        io.writefile("build/package/addons/metamod/"..PROJECT_NAME..".vdf", [["Metamod Plugin"
        {
            "alias"	"]]..PORJECT_NAME_ALIAS..[["
            "file"	"addons/]]..PROJECT_NAME..[[/bin/]]..GetDistDirName()..[[/]]..PROJECT_NAME..[["
            }
]])

        local shared = config_data.shared[GetDistDirName() == "win64" and "windows" or "linux"]
        for i=1,#shared do
            os.cp("vendor/embedder/libs/"..shared[i], 'build/package/addons/'..PROJECT_NAME..'/bin/'..GetDistDirName())
        end
    end)