#pragma once
#include <game_engine/domain/entity.hpp>
#include <game_engine/domain/component.hpp>
#include <game_engine/domain/system.hpp>
#include <unordered_map>
#include <memory>
#include <vector>

namespace game_engine::infrastructure {

    class EcsManager {
    public:
        domain::Entity::Id createEntity();
        void destroyEntity(domain::Entity::Id entityId);

        template<typename T, typename... Args>
        void addComponent(domain::Entity::Id entityId, Args&&... args);

        template<typename T>
        void removeComponent(domain::Entity::Id entityId);

        template<typename T>
        T* getComponent(domain::Entity::Id entityId);

        void addSystem(std::unique_ptr<domain::System> system);
        void update(float deltaTime);

    private:
        std::vector<domain::Entity> m_entities;
        std::unordered_map<domain::Entity::Id, std::vector<std::unique_ptr<domain::Component>>> m_components;
        std::vector<std::unique_ptr<domain::System>> m_systems;
    };

} // namespace game_engine::infrastructure