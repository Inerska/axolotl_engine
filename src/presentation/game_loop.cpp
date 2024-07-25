#include <game_engine/presentation/game_loop.hpp>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <stdexcept>

namespace game_engine::presentation {
    GameLoop::GameLoop(
        std::shared_ptr<infrastructure::EcsManager> ecs,
        std::shared_ptr<graphics::Renderer> renderer,
        std::shared_ptr<input::InputManager> inputManager
    ) : m_ecs(std::move(ecs))
        , m_renderer(std::move(renderer))
        , m_inputManager(std::move(inputManager)) {
        if (!m_ecs || !m_renderer || !m_inputManager) {
            throw std::invalid_argument("GameLoop dependencies cannot be null");
        }
        spdlog::info("GameLoop constructed");
    }

    core::Result GameLoop::initialize() {
        spdlog::info("Initializing GameLoop");

        if (!glfwInit()) {
            spdlog::error("Failed to initialize GLFW");
            return core::Result::Error;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        GLFWwindow *window = glfwCreateWindow(800, 600, "Game Engine", nullptr, nullptr);
        if (!window) {
            spdlog::error("Failed to create GLFW window");
            glfwTerminate();
            return core::Result::Error;
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            spdlog::error("Failed to initialize GLAD");
            return core::Result::Error;
        }

        if (m_renderer->initialize() != core::Result::Success) {
            spdlog::error("Failed to initialize Renderer");
            return core::Result::Error;
        }

        m_inputManager->initialize(window);

        spdlog::info("GameLoop initialized successfully");
        return core::Result::Success;
    }

    void GameLoop::run() {
        spdlog::info("Starting main game loop");

        GLFWwindow *window = glfwGetCurrentContext();
        if (!window) {
            spdlog::error("No GLFW context found");
            return;
        }

        while (!glfwWindowShouldClose(window)) {
            float currentFrame = static_cast<float>(glfwGetTime());
            float deltaTime = currentFrame - m_lastFrame;
            m_lastFrame = currentFrame;

            m_inputManager->processInput();
            update(deltaTime);
            render();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        spdlog::info("Exiting main game loop");
        glfwTerminate();
    }

    void GameLoop::update(float deltaTime) {
    }

    void GameLoop::render() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_renderer->render();
    }
} // namespace game_engine::presentation
