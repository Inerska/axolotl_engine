#pragma once

#include <memory>
#include <entt/entity/fwd.hpp>

namespace game_engine::core {

    /**
     * @brief Alias for std::unique_ptr for consistent smart pointer usage.
     */
    template<typename T>
    using UniquePtr = std::unique_ptr<T>;

    /**
     * @brief Alias for entt::entity to represent game entities.
     */
    using Entity = entt::entity;

    /**
     * @brief Enumeration for function results.
     */
    enum class Result {
        Success,
        Error
    };

} // namespace game_engine::core