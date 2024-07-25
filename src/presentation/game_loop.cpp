#include <game_engine/presentation/game_loop.hpp>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include "game_engine/domain/system.hpp"

namespace game_engine::presentation {
    class GameLoop::Impl {
    public:
        Impl(infrastructure::EcsManager &ecs,
             graphics::Renderer &renderer,
             input::InputManager &inputManager)
            : m_ecs(ecs)
              , m_renderer(renderer)
              , m_inputManager(inputManager)
              , m_movementSystem()
              , m_window(nullptr) {
        }

        core::Result initialize() {
            spdlog::info("Initializing GameLoop");

            if (!glfwInit()) {
                spdlog::error("Failed to initialize GLFW");
                return core::Result::Error;
            }

            m_window = glfwCreateWindow(800, 600, "Game Engine", nullptr, nullptr);
            if (!m_window) {
                spdlog::error("Failed to create GLFW window");
                glfwTerminate();
                return core::Result::Error;
            }

            glfwMakeContextCurrent(m_window);

            if (m_renderer.initialize() != core::Result::Success) {
                spdlog::error("Failed to initialize Renderer");
                return core::Result::Error;
            }

            m_inputManager.initialize(m_window);

            auto entity = m_ecs.createEntity();
            m_ecs.addComponent<domain::components::Position>(entity, glm::vec3(0.0f));
            m_ecs.addComponent<domain::components::Velocity>(entity, glm::vec3(1.0f, 0.0f, 0.0f));

            spdlog::info("GameLoop initialized successfully");
            return core::Result::Success;
        }

        void run() {
            spdlog::info("Starting main game loop");

            float lastFrame = 0.0f;
            while (!glfwWindowShouldClose(m_window)) {
                float currentFrame = static_cast<float>(glfwGetTime());
                float deltaTime = currentFrame - lastFrame;
                lastFrame = currentFrame;

                m_inputManager.processInput();
                update(deltaTime);
                render();

                glfwSwapBuffers(m_window);
                glfwPollEvents();
            }

            spdlog::info("Exiting main game loop");
            glfwTerminate();
        }

    private:
        void update(float deltaTime) {
            m_movementSystem.update(m_ecs, deltaTime);
        }

        void render() {
            m_renderer.render();
        }

        infrastructure::EcsManager &m_ecs;
        graphics::Renderer &m_renderer;
        input::InputManager &m_inputManager;
        domain::systems::MovementSystem m_movementSystem;
        GLFWwindow *m_window;
    };

    GameLoop::GameLoop(infrastructure::EcsManager &ecs,
                       graphics::Renderer &renderer,
                       input::InputManager &inputManager)
        : m_pImpl(std::make_unique<Impl>(ecs, renderer, inputManager)) {
    }

    GameLoop::~GameLoop() = default;

    core::Result GameLoop::initialize() {
        return m_pImpl->initialize();
    }

    void GameLoop::run() {
        m_pImpl->run();
    }
} // namespace game_engine::presentation
