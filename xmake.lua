add_rules("mode.debug", "mode.release")

includes("@builtin/xpack")
includes("core.base.option")
includes("platform.os")

set_policy("build.ccache", true)

local SDK_PATH = os.getenv("HL2SDKCS2")
local MM_PATH = os.getenv("MMSOURCE112")
local GITHUB_SHA = os.getenv("GITHUB_SHA") or "Local"
local PROJECT_NAME = "swiftly"
local PORJECT_NAME_ALIAS = "swiftly"

function GetDistDirName()
    if is_plat("windows") then
        return "win64"
    else
        return "linuxsteamrt64"
    end
end

target(PROJECT_NAME.."-XMake")
    set_kind("shared")

    -- Source Code Section
    add_files("src/**.cpp")
    add_files("prototemp/**.cc")

    -- Vendor Source Code Section
    add_files("vendor/lua/*.c")
    remove_files("vendor/lua/onelua.c")

    set_policy("build.cache", true)

    -- Protobuf Generation
    on_load(function(target)
        local protoc = is_plat("windows") and SDK_PATH.."/devtools/bin/protoc.exe" or SDK_PATH.."/devtools/bin/linux/protoc" 
        local args = "--proto_path="..SDK_PATH.."/thirdparty/protobuf-3.21.8/src --proto_path=./src/protobufs --proto_path="..SDK_PATH.."/public --proto_path="..SDK_PATH.."/public/engine --proto_path="..SDK_PATH.."/public/mathlib --proto_path="..SDK_PATH.."/public/vstdlib --proto_path="..SDK_PATH.."/public/tier0 --proto_path="..SDK_PATH.."/public/tier1 --proto_path="..SDK_PATH.."/public/entity2 --proto_path="..SDK_PATH.."/public/game/server --proto_path="..SDK_PATH.."/game/shared --proto_path="..SDK_PATH.."/game/server --proto_path="..SDK_PATH.."/common --cpp_out=prototemp"

        function mysplit (inputstr, sep)
            if sep == nil then sep = "%s" end
            local t={}
            for str in string.gmatch(inputstr, "([^"..sep.."]+)") do table.insert(t, str) end
            return t
        end
    
        if os.exists("prototemp") then
            os.rmdir("prototemp")
        end
        os.mkdir("prototemp")

        if os.exists("src/protobufs") then
            for _, sourcefile in ipairs(os.files("./src/protobufs/*.proto")) do
                local splitted = mysplit(sourcefile, is_plat("windows") and "\\" or "/")
                local filename = splitted[#splitted]
    
                os.iorun(protoc .. " "..args.." --dependency_out=prototemp/"..filename..".d "..sourcefile)
            end
        end
    end)

    add_files({
        SDK_PATH.."/entity2/entitysystem.cpp",
        SDK_PATH.."/entity2/entityidentity.cpp",
        SDK_PATH.."/tier1/convar.cpp",
    })

    if not is_plat("windows") then
        add_files({
            SDK_PATH.."/public/tier0/memoverride.cpp",
        })
    end

    if is_plat("windows") then
        add_links({
            SDK_PATH.."/lib/public/win64/tier0.lib",
            SDK_PATH.."/lib/public/win64/tier1.lib",
            SDK_PATH.."/lib/public/win64/interfaces.lib",
            SDK_PATH.."/lib/public/win64/mathlib.lib",
            SDK_PATH.."/lib/public/win64/steam_api64.lib",
            SDK_PATH.."/lib/public/win64/2015/libprotobuf.lib",
        })
    else
        add_links({
            SDK_PATH.."/lib/linux64/libtier0.so",
            SDK_PATH.."/lib/linux64/tier1.a",
            SDK_PATH.."/lib/linux64/interfaces.a",
            SDK_PATH.."/lib/linux64/mathlib.a",
            SDK_PATH.."/lib/linux64/libsteam_api.so",
            SDK_PATH.."/lib/linux64/release/libprotobuf.a",
        })
    end

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
            "msvcrt.lib"
        })
    else
        add_links({
            "z",
            "pthread",
            "m",
            "dl",
            "readline",
            "rt",
            "ssl",
            "crypto",
            "idn2",
            "psl",
            "brotlidec",
            "backtrace",
            "stdc++"
        })
    end

    add_cxxflags("gcc::-Wno-invalid-offsetof")
    add_cxxflags("gcc::-Wno-return-local-addr")
    add_cxxflags("gcc::-Wno-overloaded-virtual")
    add_cxxflags("gcc::-Wno-non-virtual-dtor")
    add_cxxflags("gcc::-Wno-attributes")
    add_cxxflags("gcc::-Wno-int-to-pointer-cast")
    add_cxxflags("gcc::-ffexceptions")
    add_cxxflags("gcc::-fPIC")
    add_cxxflags("cl::/Zc:__cplusplus")
    add_cxxflags("cl::/Ox")
    add_cxxflags("cl::/Zo")
    add_cxxflags("cl::/Oy-")
    add_cxxflags("cl::/Z7")
    add_cxxflags("cl::/TP")
    add_cxxflags("cl::/MT")
    add_cxxflags("cl::/W3")
    add_cxxflags("cl::/Z7")

    add_includedirs({
        "prototemp",
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

    if is_plat("windows") then
        add_defines({
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
            "NDEBUG"
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
            "LUA_USE_LINUX",
            "LUA_USE_READLINE",
            "BOOST_STACKTRACE_USE_BACKTRACE"
        })
    end

    add_defines({
        "GITHUB_SHA=\""..GITHUB_SHA.."\"",
        "HAVE_STRUCT_TIMESPEC",
        "BUILDING",
        "CURL_STATICLIB"
    })

    set_languages("cxx17")

    -- Custom Includes
    add_includedirs({
        "vendor/lua",
        "vendor/LuaBridge/Source"
    })

    after_build(function(target)
        function GetDistDirName()
            if is_plat("windows") then
                return "win64"
            else
                return "linuxsteamrt64"
            end
        end

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
    end)