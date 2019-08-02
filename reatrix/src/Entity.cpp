//
//  Entity.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/11.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Entity.h"
#include "Reatrix.h"
#include "Pool.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

SharedPtr<Entity> Entity::create(const String& name)
{
    SharedPtr<Entity> entity = Reatrix::instance()->getPool()->createEntity();
    entity->setName(name);
    
    return entity;
}

Entity::Entity()
{
    
}

Entity::~Entity()
{
    
}

void Entity::destroy(SharedPtr<Entity>& entity)
{
    entity.reset();
}

bool Entity::operator ==(const SharedPtr<Entity>& right) const
{
    return this->getUUID() == right->getUUID();
}

bool Entity::operator ==(const Entity right) const
{
    return this->getUUID() == right.getUUID();
}

NAMESPACE_REATRIX_ENGINE_END

namespace std
{
    bool operator ==(WeakPtr<rtx::Entity> left, WeakPtr<rtx::Entity> right)
    {
        return left.lock().get() == right.lock().get();
    }
}
