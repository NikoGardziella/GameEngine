workspace "GameEngine"
	architechture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architechture}"

project "GameEngine"
	location "GameEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/".. outputdir .. "/%{prj.name}")
	objdir ("bin-int/".. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	include
	{
		"%{prj.name}/vendor/spdlog/include;"
	}

	GE_PLATFORM_WINDOWS;GE_BUILD_DLL;_DEBUG;GAMEENGINE_EXPORTS;_WINDOWS;_USRDLL;