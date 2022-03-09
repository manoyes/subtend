project "Subtend"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
	debugdir ("%{cfg.targetdir}")

	pchheader "sbtpch.h"
	pchsource "src/sbtpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.ImGuiPlot}",
		"%{IncludeDir.ImGuiBackends}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.VulkanSDK}"
	}

	links
	{
		"ImGui",
		"%{Library.GLFW}",
		"%{Library.Vulkan}"
	}

	postbuildcommands 
	{
		"{COPY} imgui.ini %{cfg.targetdir}"
	}

	--flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "SBT_DEBUG"
		runtime "Debug"
		symbols "on"

		links
		{
		}

	filter "configurations:Release"
		defines "SBT_RELEASE"
		kind "WindowedApp"
		runtime "Release"
		optimize "on"

		links
		{
		}

	filter "configurations:Dist"
		defines "SBT_DIST"
		kind "WindowedApp"
		runtime "Release"
		optimize "on"

		links
		{
		}