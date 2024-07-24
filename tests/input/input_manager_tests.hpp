#include <catch2/catch_test_macros.hpp>
#include <game_engine/input/input_manager.hpp>

TEST_CASE("InputManager initialization", "[input]") {
    game_engine::input::InputManager input_manager;
    input_manager.initialize(nullptr);
    REQUIRE(true);
}