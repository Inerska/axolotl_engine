#pragma once
#include <vector>
#include "entity.hpp"

namespace game_engine::domain {

    class System {
    public:
        virtual ~System() = default;
        virtual void update(const std::vector<Entity>& entities, float deltaTime) = 0;
    };

} // namespace game_engine::domain