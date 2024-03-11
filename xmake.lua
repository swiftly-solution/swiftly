add_rules("mode.debug", "mode.release")

includes("@builtin/xpack")
includes("core.base.option")
includes("platform.os")

local SDK_PATH = os.getenv("HL2SDKCS2")
local MM_PATH = os.getenv("MMSOURCE112")
local GITHUB_SHA = os.getenv("GITHUB_SHA") or "Local"
local PROJECT_NAME = "swiftly"
local PORJECT_NAME_ALIAS = "swift"

function GetDistDirName()
    if is_plat("windows") then
        return "win64"
    else
        return "linuxsteamrt64"
    end
end

target(PROJECT_NAME.."-Xmake")
    set_kind("shared")

    --[[ Source Files ]]
    add_files("src/**.cpp")
    add_files("vendor/luacpp/src/**.cpp")
    add_files("vendor/lua-rapidjson/src/**.cpp")
    add_files("prototemp/**.cc")

    add_files("vendor/lua/*.c")
    remove_files("vendor/lua/onelua.c")

    on_load(function(target)
        local protoc = is_plat("windows") and SDK_PATH.."/devtools/bin/protoc.exe" or SDK_PATH.."/devtools/bin/linux/protoc" 
        local args = "--proto_path="..SDK_PATH.."/thirdparty/protobuf-3.21.8/src --proto_path=./src/protos --proto_path="..SDK_PATH.."/public --proto_path="..SDK_PATH.."/public/engine --proto_path="..SDK_PATH.."/public/mathlib --proto_path="..SDK_PATH.."/public/vstdlib --proto_path="..SDK_PATH.."/public/tier0 --proto_path="..SDK_PATH.."/public/tier1 --proto_path="..SDK_PATH.."/public/entity2 --proto_path="..SDK_PATH.."/public/game/server --proto_path="..SDK_PATH.."/game/shared --proto_path="..SDK_PATH.."/game/server --proto_path="..SDK_PATH.."/common --cpp_out=prototemp"

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

        for _, sourcefile in ipairs(os.files("./src/protos/*.proto")) do
            local splitted = mysplit(sourcefile, "/")
            local filename = splitted[#splitted]

            os.iorun(protoc .. " "..args.." --dependency_out=prototemp/"..filename..".d "..sourcefile)
        end
    end)

    add_files({
        SDK_PATH.."/entity2/entitysystem.cpp",
        SDK_PATH.."/entity2/entityidentity.cpp",
        SDK_PATH.."/public/tier0/memoverride.cpp",
    })

    set_symbols("hidden")

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

    if is_plat("windows") then
        add_links({
            "psapi",
            "winmm",
            "vendor/mysql/win64/lib/mysqlclient.lib",
            "vendor/funchook/lib/funchook.lib",
            "vendor/funchook/lib/distorm.lib",
            "vendor/curl/win64/lib/libcurl_a.lib",
            "ws2_32",
            "wldap32",
            "advapi32",
            "kernel32",
            "comdlg32",
            "crypt32",
            "normaliz",
            "wsock32",
            "legacy_stdio_definitions",
            "legacy_stdio_wide_specifiers"
        })
    else
        add_links({
            "vendor/mysql/linuxsteamrt64/lib/libmysqlclient.a",
            "vendor/curl/linuxsteamrt64/lib/libcurl.a",
            "vendor/funchook/lib/libfunchook.a",
            "vendor/funchook/lib/libdistorm.a",
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

    add_includedirs({
        "src/inc",
        "src",
        "prototemp",
        "vendor/rapidjson/include",
        "vendor/funchook/include",
        "vendor/cpp-httplib",
        "vendor/luacpp/include",
        "vendor/mysql/"..GetDistDirName().."/include",
        "vendor/lua",
        "vendor/openssl/"..GetDistDirName().."/include",
        "vendor/curl/"..GetDistDirName().."/include",
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
            "META_IS_SOURCE2"
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
            "_GLIBCXX_USE_CXX11_ABI=0"
        })
    end

    add_defines({
        "GITHUB_SHA=\""..GITHUB_SHA.."\"",
        "HAVE_STRUCT_TIMESPEC",
        "LUA_USE_LINUX",
        "LUA_USE_READLINE",
        "BOOST_STACKTRACE_USE_BACKTRACE"
    })
    
    set_languages("cxx17")

    after_build(function(target)
        function GetDistDirName()
            if is_plat("windows") then
                return "win64"
            else
                return "linuxsteamrt64"
            end
        end

        print(GetDistDirName(), target:targetfile())
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
    
