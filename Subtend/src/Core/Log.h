// Modifications copyright(C) 2022 Matthew Noyes
#pragma once

#include "Core.h"

// Ignore external header warnings
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Subtend
{
    class Log
    {
    public:
        static void Init();

        static SharedPtr<spdlog::logger>& GetLogger() { return s_Logger; }

    private:
        static SharedPtr<spdlog::logger> s_Logger;
    };
}

// Log macros
#define LOG_TRACE(...)    ::Subtend::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)     ::Subtend::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)     ::Subtend::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)    ::Subtend::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::Subtend::Log::GetCoreLogger()->critical(__VA_ARGS__)
