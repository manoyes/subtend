include "Dependencies.lua"

project "ImGui"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"imconfig.h",
		"imgui.cpp",
		"imgui.h",
		"imgui_demo.cpp",
		"imgui_draw.cpp",
		"imgui_internal.h",
        "imgui_tables.cpp",
		"imgui_widgets.cpp",
		"imstb_rectpack.h",
		"imstb_textedit.h",
		"imstb_truetype.h",
        "backends/imgui_impl_glfw.cpp",
        "backends/imgui_impl_glfw.h",
        "backends/imgui_impl_vulkan.cpp",
        "backends/imgui_impl_vulkan.h",
		"../imgui-plot/src/imgui_plot.cpp"
        -- "examples/libs/glfw/include/GLFW/glfw3.h",
        -- "examples/libs/glfw/include/GLFW/glfw3native.h"
	}

	includedirs
	{
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.ImGuiPlot}",
		"%{IncludeDir.ImGuiBackends}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.VulkanSDK}"
	}

	links
	{
		--"ImGui",
		"%{Library.GLFW}",
		"%{Library.GLFW}",
		"%{Library.Vulkan}"
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"