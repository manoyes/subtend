-- Subtend Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["ImGui"] = "%{wks.location}/Subtend/vendor/imgui"
IncludeDir["ImGuiPlot"] = "%{wks.location}/Subtend/vendor/imgui-plot/include"
IncludeDir["ImGuiBackends"] = "%{wks.location}/Subtend/vendor/imgui/backends"
IncludeDir["GLFW"] = "%{wks.location}/Subtend/vendor/imgui/examples/libs/glfw/include"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["GLFW"] = "%{wks.location}/Subtend/vendor/imgui/examples/libs/glfw/"
LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["VulkanSDK_Debug"] = "%{wks.location}/Subtend/vendor/VulkanSDK/Lib"
LibraryDir["VulkanSDK_DebugDLL"] = "%{wks.location}/Subtend/vendor/VulkanSDK/Bin"

Library = {}

Library["GLFW"] = "%{LibraryDir.GLFW}/lib-vc2010-64/glfw3.lib"
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"