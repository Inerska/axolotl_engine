#include <catch2/catch_test_macros.hpp>
#include <../../include/game_engine/infrastructure/renderer.hpp>

TEST_CASE("Renderer initialization", "[graphics]") {
    const game_engine::graphics::Renderer renderer{};
    REQUIRE(renderer.initialize() == game_engine::core::Result::Success);
}