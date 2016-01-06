//
//  HashMap.cpp
//  HashTable
//
//  Created by terrychan on 15/12/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "HashMap.hpp"

void HashMap::doCollision() const
{
    collisionTimes++;
}

void HashMap::doExecution() const
{
    executionTimes++;
}

HashMap::HashMap(const unsigned int capacity, unsigned int (*hash) (const std::string&)) : capacity(capacity)
{
    size = 0;
    collisionTimes = 0;
    executionTimes = 0;
    count = 0;
    this->hash = hash;
}

HashMap::~HashMap()
{
}

unsigned int HashMap::getSize() const
{
    return size;
}

unsigned int HashMap::getCapacity() const
{
    return capacity;
}

double HashMap::getLoadfactors() const
{
    return (double) size / (double) capacity * 1000;    //  convert to ms
}

unsigned long long HashMap::getCollisionTimes() const
{
    return collisionTimes;
}

unsigned long long HashMap::getExecutionTimes() const
{
    return executionTimes;
}

double HashMap::getTime() const
{
    return (double)count / CLOCKS_PER_SEC;
}

void HashMap::clearTime() const
{
    count = 0;
}