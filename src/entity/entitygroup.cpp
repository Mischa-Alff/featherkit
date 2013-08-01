#include <featherkit/entity/entitygroup.h>
#include <algorithm>

namespace fea
{
    void EntityGroup::add(const WeakEntityPtr entity)
    {
        entities.insert(entity);
    }

    void EntityGroup::add(const EntityGroup& other)
    {
        entities.insert(other.entities.begin(), other.entities.end());
    }

    void EntityGroup::remove(const WeakEntityPtr entity)
    {
        entities.erase(entity);
    }

    void EntityGroup::remove(const EntityGroup& other)
    {
        entities.erase(other.entities.begin(), other.entities.end());
    }

    void EntityGroup::clear()
    {
        entities.clear();
    }

    EntityGroup EntityGroup::operator+(const EntityGroup& other) const
    {
        EntityGroup newGroup;
        newGroup.entities.insert(entities.begin(), entities.end());
        newGroup.entities.insert(other.entities.begin(), other.entities.end());
        return newGroup;
    }
    
    EntityGroup EntityGroup::operator+(const WeakEntityPtr& entity) const
    {
        EntityGroup newGroup;
        newGroup.entities = entities;
        newGroup.entities.insert(entity);
        return newGroup;
    }

    EntityGroup EntityGroup::operator-(const EntityGroup& other) const
    {
        EntityGroup newGroup;
        std::set_difference(entities.begin(), entities.end(), other.entities.begin(), other.entities.end(), std::inserter(newGroup.entities, newGroup.entities.end()), std::owner_less<WeakEntityPtr>());
        return newGroup;
    }
    
    EntityGroup EntityGroup::operator-(const WeakEntityPtr& entity) const
    {
        EntityGroup newGroup;
        newGroup.entities = entities;
        newGroup.entities.erase(entity);
        return newGroup;
    }
    
    EntitySet::iterator EntityGroup::begin() const
    {
        return entities.begin();
    }

    EntitySet::iterator EntityGroup::end() const
    {
        return entities.end();
    }

    size_t EntityGroup::size()
    {
        return entities.size();
    }

    EntityGroup EntityGroup::filterOutGroup(std::function<bool(EntityPtr)> filterFunc)
    {
        EntityGroup newGroup;

        for(auto entity : entities)
        {
            if(filterFunc(entity.lock()))
                newGroup.add(entity);
        }

        return newGroup;
    }

    WeakEntityPtr EntityGroup::filterOutEntity(std::function<bool(EntityPtr)> filterFunc)
    {
        EntityGroup newGroup;

        for(auto entity : entities)
        {
            if(filterFunc(entity.lock()))
                return entity;
        }
        return WeakEntityPtr();
    }

    void EntityGroup::removeInvalid()
    {
        auto iter = entities.begin();
        while(iter != entities.end())
        {
            if(iter->expired())
                iter = entities.erase(iter);
            else
                iter++;
        }
    }
}
