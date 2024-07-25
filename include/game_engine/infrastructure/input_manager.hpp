#pragma once

#include <../core/types.hpp>
#include <memory>

struct GLFWwindow;

namespace game_engine::input {

    /**
     * @class InputManager
     * @brief Manages user input and input events.
     *
     * The InputManager class is responsible for processing user input,
     * managing input states, and dispatching input events to other systems.
     */
    class InputManager {
    public:
        /**
         * @brief Construct a new InputManager object.
         */
        InputManager();

        /**
         * @brief Destroy the InputManager object.
         */
        ~InputManager();

        /**
         * @brief Initialize the input manager with the given window.
         * @param window Pointer to the GLFW window.
         */
        void initialize(GLFWwindow* window) const;

        /**
         * @brief Process input events for the current frame.
         */
        void processInput() const;

    private:
        class Impl;
        core::UniquePtr<Impl> m_pImpl;
    };

} // namespace game_engine::input