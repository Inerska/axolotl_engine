#include <game_engine/core/game_loop.hpp>
#include <game_engine/graphics/renderer.hpp>
#include <game_engine/input/input_manager.hpp>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

namespace game_engine::core {
    class GameLoop::Impl {
    public:
        Impl()
            : m_window(nullptr)
              , m_renderer(std::make_unique<graphics::Renderer>())
              , m_inputManager(std::make_unique<input::InputManager>()) {
        }

        GLFWwindow *m_window;
        std::unique_ptr<graphics::Renderer> m_renderer;
        std::unique_ptr<input::InputManager> m_inputManager;
    };

    GameLoop::GameLoop() : m_pImpl(std::make_unique<Impl>()) {
    }

    GameLoop::~GameLoop() = default;

    Result GameLoop::initialize() const {
        spdlog::info("Initializing GameLoop");

        if (!glfwInit()) {
            spdlog::error("Failed to initialize GLFW");
            return Result::Error;
        }
        spdlog::info("GLFW initialized successfully");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        m_pImpl->m_window = glfwCreateWindow(800, 600, "Game Engine", nullptr, nullptr);
        if (!m_pImpl->m_window) {
            spdlog::error("Failed to create GLFW window");
            glfwTerminate();
            return Result::Error;
        }
        spdlog::info("GLFW window created successfully");

        glfwMakeContextCurrent(m_pImpl->m_window);

        if (m_pImpl->m_renderer->initialize() != Result::Success) {
            spdlog::error("Failed to initialize Renderer");
            return Result::Error;
        }

        m_pImpl->m_inputManager->initialize(m_pImpl->m_window);

        spdlog::info("GameLoop initialized successfully");
        return Result::Success;
    }

    void GameLoop::run() const {
        spdlog::info("Starting main game loop");

        while (!glfwWindowShouldClose(m_pImpl->m_window)) {
            m_pImpl->m_inputManager->processInput();
            m_pImpl->m_renderer->render();
            glfwSwapBuffers(m_pImpl->m_window);
            glfwPollEvents();
        }

        spdlog::info("Exiting main game loop");
        glfwTerminate();
    }
} // namespace game_engine::core
