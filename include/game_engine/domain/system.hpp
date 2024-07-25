#pragma once
#include <game_engine/infrastructure/ecs_manager.hpp>

#include "component.hpp"

namespace game_engine::domain::systems {
    class MovementSystem {
    public:
        static void update(infrastructure::EcsManager &ecs, const float deltaTime) {
            auto &registry = ecs.getRegistry();

            for (const auto view = registry.view<components::Position, components::Velocity>(); auto &&entity: view) {
                auto &[position] = view.get<components::Position>(entity);
                const auto &[velocity] = view.get<components::Velocity>(entity);

                position += velocity * deltaTime;
            }
        }
    };
} // namespace game_engine::domain::systems
