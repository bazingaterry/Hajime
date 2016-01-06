//
//  HashMap_Chaining.cpp
//  HashTable
//
//  Created by terrychan on 15/12/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "HashMap_Chaining.hpp"

HashMap_Chaining::HashMap_Chaining(const int capacity, unsigned int (*hash) (const std::string&)) : HashMap(capacity, hash)
{
    map = new ListNode<std::string, std::string>[capacity];
}

HashMap_Chaining::~HashMap_Chaining()
{
    delete[] map;
}

bool HashMap_Chaining::insert(const std::string& key, const std::string& value)
{
    PeformanceAnalyze pa(this);
    unsigned int index = hash(key) % capacity;
    if (map[index].exist(key))
        return false;
    else
    {
        size++;
        return map[index].insert(key, value);
    }
}

bool HashMap_Chaining::erase(const std::string& key)
{
    PeformanceAnalyze pa(this);
    unsigned int index = hash(key) % capacity;
    if (map[index].remove(key))
    {
        size--;
        return true;
    }
    else
        return false;
}

bool HashMap_Chaining::find(const std::string& key, std::string& value)
{
    PeformanceAnalyze pa(this);
    unsigned int index = hash(key) % capacity;
    return map[index].find(key, value);
}
