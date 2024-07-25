#include <catch2/catch_test_macros.hpp>
#include <../../include/game_engine/infrastructure/input_manager.hpp>

TEST_CASE("InputManager initialization", "[input]") {
    const game_engine::input::InputManager input_manager{};
    input_manager.initialize(nullptr);
    REQUIRE(true);
}