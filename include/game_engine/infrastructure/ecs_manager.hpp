#pragma once
#include <entt/entity/registry.hpp>

namespace game_engine::infrastructure {
    class EcsManager {
    public:
        EcsManager() = default;

        ~EcsManager() = default;

        entt::entity createEntity() {
            return m_registry.create();
        }

        void destroyEntity(const entt::entity &entity) {
            m_registry.destroy(entity);
        }

        template<typename T, typename... Args>
        T &addComponent(entt::entity entity, Args &&... args) {
            return m_registry.emplace<T>(entity, std::forward<Args>(args)...);
        }

        template<typename T>
        void removeComponent(const entt::entity &entity) {
            m_registry.remove<T>(entity);
        }

        template<typename T>
        T &getComponent(const entt::entity &entity) {
            return m_registry.get<T>(entity);
        }

        entt::registry &getRegistry() {
            return m_registry;
        }

    private:
        entt::registry m_registry;
    };
} // namespace game_engine::infrastructure
