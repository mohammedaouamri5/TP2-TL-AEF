workspace "TP"
    configurations { "Debug", "Release", "Dist" }
    platforms { "x86_64" ,"x86"  }

project "TP"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/%{cfg.platform}_%{cfg.buildcfg}")
    objdir ("bin/obj/%{cfg.platform}_%{cfg.buildcfg}")
 
    files { "Source/**" }
    includedirs {
        "Vendor/",
         "Vendor/spdlog/include",
        -- "Vendor/fmt/include",
    }
    links {
        "spdlog", 
        "fmt",
 
    }
    toolset "gcc"
    defines{"SPDLOG_COMPILED_LIB","SPDLOG_ACTIVE_LEVEL"}

    group "Dependencies"
        -- include "Vendor/fmt"
        include "Vendor/spdlog"
 

    -- buildoptions { "--std=gnu99" }  -- Enable GNU C extensions

    filter "system:windows"
        systemversion "latest"
        defines { "WINDOWS" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines { "DIST" }
        optimize "On"
        symbols "Off"

    filter "platforms:x86"
        architecture "x86"

    filter "platforms:x86_64"
        architecture "x86_64"
