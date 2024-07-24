#include <catch2/catch_test_macros.hpp>
#include <game_engine/graphics/renderer.hpp>

TEST_CASE("Renderer initialization", "[graphics]") {
    game_engine::graphics::Renderer renderer;
    REQUIRE(renderer.initialize() == game_engine::core::Result::Success);
}