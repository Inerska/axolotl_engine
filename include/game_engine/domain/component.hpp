#pragma once
#include <cstdint>

namespace game_engine::domain {

    class Component {
    public:
        using Id = std::uint32_t;

        virtual ~Component() = default;
        virtual Id getTypeId() const = 0;
    };

} // namespace game_engine::domain