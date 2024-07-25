#pragma once

#include <game_engine/core/types.hpp>
#include <game_engine/infrastructure/ecs_manager.hpp>
#include <game_engine/infrastructure/renderer.hpp>
#include <game_engine/infrastructure/input_manager.hpp>
#include <memory>

namespace game_engine::presentation {

    class GameLoop {
    public:
        GameLoop(infrastructure::EcsManager& ecs,
                 graphics::Renderer& renderer,
                 input::InputManager& inputManager);

        ~GameLoop();

        GameLoop(const GameLoop&) = delete;
        GameLoop& operator=(const GameLoop&) = delete;
        GameLoop(GameLoop&&) = delete;
        GameLoop& operator=(GameLoop&&) = delete;

        core::Result initialize();
        void run();

    private:
        class Impl;
        core::UniquePtr<Impl> m_pImpl;

        void update(float deltaTime);
        void render();
    };

} // namespace game_engine::presentation