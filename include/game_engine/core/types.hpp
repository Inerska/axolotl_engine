#pragma once

#include <memory>

namespace game_engine::core {

    /**
     * @brief Alias for std::unique_ptr for consistent smart pointer usage.
     */
    template<typename T>
    using UniquePtr = std::unique_ptr<T>;

    /**
     * @brief Enumeration for function results.
     */
    enum class Result {
        Success,
        Error
    };

} // namespace game_engine::core