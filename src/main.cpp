#include <game_engine/core/game_loop.hpp>
#include <spdlog/spdlog.h>

int main() {
    spdlog::info("Starting Game Engine");

    game_engine::core::GameLoop game_loop{};

    if (game_loop.initialize() != game_engine::core::Result::Success) {
        spdlog::error("Failed to initialize GameLoop");
        return -1;
    }

    game_loop.run();

    spdlog::info("Game Engine shutdown complete");
    return 0;
}
