#pragma once
#include <cstdint>

namespace game_engine::domain {

    class Entity {
    public:
        using Id = std::uint32_t;

        explicit Entity(const Id id) : m_id(id) {}
        [[nodiscard]] Id getId() const { return m_id; }

    private:
        Id m_id;
    };

} // namespace game_engine::domain