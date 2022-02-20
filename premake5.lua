include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Subtend"
	architecture "x86_64"
	startproject "Subtend"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Subtend/vendor/imgui"
group ""

include "Subtend"