#pragma once

#include <game_engine/core/types.hpp>
#include <memory>

namespace game_engine::graphics {

    /**
     * @class Renderer
     * @brief Manages the rendering of game objects and scenes.
     *
     * The Renderer class is responsible for initializing the graphics context,
     * managing shaders, and rendering game objects to the screen.
     */
    class Renderer {
    public:
        /**
         * @brief Construct a new Renderer object.
         */
        Renderer();

        /**
         * @brief Destroy the Renderer object.
         */
        ~Renderer();

        /**
         * @brief Initialize the renderer.
         * @return Result indicating success or failure of initialization.
         */
        [[nodiscard]] core::Result initialize() const;

        /**
         * @brief Render the current frame.
         */
        void render() const;

    private:
        class Impl;
        core::UniquePtr<Impl> m_pImpl;
    };

} // namespace game_engine::graphics