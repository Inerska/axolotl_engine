#pragma once

#include <game_engine/core/types.hpp>
#include <memory>

namespace game_engine::core {

    /**
     * @class GameLoop
     * @brief Manages the main game loop and coordinates all game systems.
     *
     * The GameLoop class is responsible for initializing the game systems,
     * running the main loop, and coordinating updates and rendering.
     */
    class GameLoop {
    public:
        /**
         * @brief Construct a new GameLoop object.
         */
        GameLoop();

        /**
         * @brief Destroy the GameLoop object.
         */
        ~GameLoop();

        /**
         * @brief Initialize the game systems.
         * @return Result indicating success or failure of initialization.
         */
        [[nodiscard]] Result initialize() const;

        /**
         * @brief Run the main game loop.
         */
        void run() const;

    private:
        class Impl;
        UniquePtr<Impl> m_pImpl;
    };

} // namespace game_engine::core