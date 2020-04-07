workspace "PDFUtils"
	platforms { "x86", "x64" }
	startproject "PDFUtils"

	configurations
	{
		"Debug",
		"Release",
	}
	
	flags
	{
		"MultiProcessorCompile"
	}
	
	filter { "platforms:x86" }
		architecture "x86"

	filter { "platforms:x64" }
		architecture "x86_64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PDFUtils"
	location "PDFUtils"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"PDFUtils/vendor",
		"PDFUtils/vendor/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
