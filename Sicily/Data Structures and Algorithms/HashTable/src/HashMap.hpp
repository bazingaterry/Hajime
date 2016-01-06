//
//  HashMap.hpp
//  HashTable
//
//  Created by terrychan on 15/12/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef HashMap_hpp
#define HashMap_hpp

#include <string>
#include <ctime>

#include "PeformanceAnalyze.hpp"

//  Base class of a hash map
//  key type : std::string
//  value type : std::string

class HashMap
{
protected:
    const unsigned int capacity;
    unsigned int size;
    unsigned int (*hash) (const std::string&);
    //   do statistics
    mutable unsigned long long collisionTimes;
    mutable unsigned long long executionTimes;
    void doCollision() const;
    void doExecution() const;
    mutable clock_t count;
    
public:
    HashMap(const unsigned int capacity, unsigned int (*) (const std::string&));
    virtual ~HashMap() = 0;
    virtual bool insert(const std::string& key, const std::string& value) = 0;
    virtual bool erase(const std::string& key) = 0;
    virtual bool find(const std::string& key, std::string& value) = 0;
    unsigned int getSize() const;
    unsigned int getCapacity() const;
    double getLoadfactors() const;
    unsigned long long getCollisionTimes() const;
    unsigned long long getExecutionTimes() const;
    double getTime() const;
    void clearTime() const;
    friend class PeformanceAnalyze;
};

#endif /* HashMap_hpp */
