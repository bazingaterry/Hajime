//
//  HashMap_OA.cpp
//  HashTable
//
//  Created by terrychan on 15/12/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "HashMap_OA.hpp"
#include <cmath>

bool HashMap_OA::search(const std::string& key, unsigned int& _index) const
{
    PeformanceAnalyze pa(this);
    doExecution();
    unsigned int count = 0;
    unsigned int originalIndex = hash(key) % capacity;
    unsigned int add = 0;
    unsigned int index;
    while (count++ <= capacity)
    {
        index = (originalIndex + (unsigned int)pow(add++, increment)) % capacity;
        if (this->map[index].first == key)
        {
            _index = index;
            return true;
        }
        else if (this->map[index].first == "" && isInvalid[index] == false)
            return false;

        doCollision();
        doExecution();
    }
    return false;
}

bool HashMap_OA::findAddress(const std::string& key, unsigned int& _index) const
{
    PeformanceAnalyze pa(this);
    if (size >= capacity)
    {
        doCollision();
        doExecution();
        return false;
    }
    else
    {
        doExecution();
        unsigned int originalIndex = hash(key) % capacity;
        unsigned int add = 0;
        unsigned int index = originalIndex;
        while (this->map[index].first != "")
        {
            doCollision();
            doExecution();
            index = (originalIndex + (int)pow(++add, increment)) % capacity;
        }
        _index = index;
        return true;
    }
}

HashMap_OA::HashMap_OA(const unsigned int capacity, unsigned int (*hash) (const std::string&), const unsigned int increment)
             : HashMap(capacity, hash), increment(increment)
{
    map = new StringPair[capacity];
    isInvalid = new bool[capacity];
    std::memset(isInvalid, false, sizeof(bool) * capacity);
}

HashMap_OA::~HashMap_OA()
{
    delete[] map;
}

bool HashMap_OA::insert(const std::string& key, const std::string& value)
{
    PeformanceAnalyze pa(this);
    unsigned int index;
    if (findAddress(key, index))
    {
        map[index].first = key;
        map[index].second = value;
        isInvalid[index] = false;
        size++;
        return true;
    }    
    else
        return false;
}

bool HashMap_OA::erase(const std::string& key)
{
    PeformanceAnalyze pa(this);
    unsigned int index;
    if (search(key, index))
    {
        map[index].first = "";
        isInvalid[index] = true;
        size--;
        return true;
    }    
    else
        return false;
}

bool HashMap_OA::find(const std::string& key, std::string& value)
{
    PeformanceAnalyze pa(this);
    unsigned int index;
    if (search(key, index))
    {
        value = map[index].second;
        return true;
    }    
    else
        return false;
}
