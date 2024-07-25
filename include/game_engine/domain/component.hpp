#pragma once
#include <glm/glm.hpp>

namespace game_engine::domain::components {

    struct Position {
        glm::vec3 value;
    };

    struct Velocity {
        glm::vec3 value;
    };

} // namespace game_engine::domain::components