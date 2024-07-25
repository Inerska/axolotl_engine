#include <game_engine/presentation/game_loop.hpp>
#include <game_engine/infrastructure/ecs_manager.hpp>
#include <game_engine/infrastructure/renderer.hpp>
#include <game_engine/infrastructure/input_manager.hpp>
#include <boost/di.hpp>

namespace di = boost::di;

int main() {
    const auto injector = make_injector(
        di::bind<game_engine::infrastructure::EcsManager>().to<game_engine::infrastructure::EcsManager>(),
        di::bind<game_engine::graphics::Renderer>().to<game_engine::graphics::Renderer>(),
        di::bind<game_engine::input::InputManager>().to<game_engine::input::InputManager>()
    );

    auto game_loop = injector.create<game_engine::presentation::GameLoop>();

    if (game_loop.initialize() == game_engine::core::Result::Success) {
        game_loop.run();
    }

    return 0;
}