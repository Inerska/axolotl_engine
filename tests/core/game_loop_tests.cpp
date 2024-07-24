#include <catch2/catch_test_macros.hpp>

#include "game_engine/core/game_loop.hpp"

TEST_CASE("GameLoop initialization", "[core]") {
    const game_engine::core::GameLoop game_loop{};
    REQUIRE(game_loop.initialize() == game_engine::core::Result::Success);
}