#pragma once
#include <game_engine/infrastructure/ecs_manager.hpp>
#include <game_engine/core/types.hpp>
#include <memory>

namespace game_engine::presentation {

    class GameLoop {
    public:
        GameLoop();
        ~GameLoop();

        core::Result initialize();
        void run();

    private:
        class Impl;
        std::unique_ptr<Impl> m_pImpl;
        std::unique_ptr<infrastructure::EcsManager> m_ecsManager;
    };

} // namespace game_engine::presentation