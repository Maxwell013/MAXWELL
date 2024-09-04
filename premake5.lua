workspace "MAXWELL"

	architecture "x64"
	startproject "Sandbox"

	configurations {

		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "MAXWELL/vendor/GLFW/include"
IncludeDir["Glad"] = "MAXWELL/vendor/Glad/include"
IncludeDir["ImGui"] = "MAXWELL/vendor/imgui"
IncludeDir["glm"] = "MAXWELL/vendor/glm"

include "MAXWELL/vendor/GLFW"
include "MAXWELL/vendor/Glad"
include "MAXWELL/vendor/imgui"

project "MAXWELL"
	
	location "MAXWELL"
	kind "SharedLib"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mwpch.h"
	pchsource "MAXWELL/src/mwpch.cpp"

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs {

		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {

		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"

		cppdialect "C++20"
		systemversion "latest"

		defines {

			"MW_PLATFORM_WINDOWS",
			"MW_BUILD_DLL"
		}

		postbuildcommands {

			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		
		defines "HZ_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {

		"MAXWELL/vendor/spdlog/include",
		"MAXWELL/src",
		"MAXWELL/vendor",
		"%{IncludeDir.glm}"
	}

	links {
		
		"MAXWELL"
	}

	filter "system:windows"

		cppdialect "C++20"
		systemversion "latest"

		defines {

			"MW_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		
		defines "HZ_DIST"
		runtime "Release"
		optimize "On"