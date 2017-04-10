includeexternal ("premake-vs-include.lua")

workspace "cpp-head-only"
    language "C++"
    location "build/%{_ACTION}/%{wks.name}"    
    if _ACTION == "vs2015" then
        toolset "v140_xp"
    end

    function include_win32_common()
        files { 
            "api/win32_common.h",
            "api/win32_common.cpp"
        }
        filter "files:api/win32_common.cpp"
            flags { "NoPCH" }    
    end

    

    group "ahk-invoke-dll"    
        create_dll_project("ahk-utils", "src")
            defines { "BUILDING_DLL", "_WIN32_WINNT=0x600" }
       