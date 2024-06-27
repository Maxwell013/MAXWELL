workspace "MAXWELL"

	architecture "x64"
	startproject "Sandbox"

	configurations {

		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MAXWELL"
	
	location "MAXWELL"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {

		"%{prj.name}/src"
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"

		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {

			"MW_PLATFORM_WINDOWS",
			"MW_BUILD_DLL"
		}

		postbuildcommands {

			"copy /B /Y ..\\bin\\" .. outputdir .. "\\MAXWELL\\MAXWELL.dll ..\\bin\\" .. outputdir .. "\\Sandbox\\ > nul"
		}

	filter "configurations:Debug"
		
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		
		defines "HZ_DIST"
		optimize "On"

project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {

		"MAXWELL/vendor/spdlog/include",
		"MAXWELL/src"
	}

	links {
		
		"MAXWELL"
	}

	filter "system:windows"

		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {

			"MW_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		
		defines "HZ_DIST"
		optimize "On"