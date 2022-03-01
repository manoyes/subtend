// Modifications copyright(C) 2022 Matthew Noyes
#pragma once

#include <memory>

namespace Subtend
{
    template<typename T>
    using SharedPtr = std::shared_ptr<T>;

    template<typename T>
    using UniquePtr = std::unique_ptr<T>;

    template <typename T, typename ... Args>
    constexpr SharedPtr<T> MakeSharedPtr(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template <typename T, typename ... Args>    
    constexpr UniquePtr<T> MakeUniquePtr(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
}
