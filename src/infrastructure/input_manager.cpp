#include "game_engine/infrastructure/input_manager.hpp"

#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

namespace game_engine::input {

    class InputManager::Impl {
    public:
        GLFWwindow* m_window{};
    };

    InputManager::InputManager() : m_pImpl(std::make_unique<Impl>()) {}

    InputManager::~InputManager() = default;

    void InputManager::initialize(GLFWwindow* window) const {
        spdlog::info("Initializing InputManager");
        m_pImpl->m_window = window;
    }

    void InputManager::processInput() const {
        if (glfwGetKey(m_pImpl->m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            spdlog::info("Escape key pressed, closing window");
            glfwSetWindowShouldClose(m_pImpl->m_window, true);
        }
    }

} // namespace game_engine::input