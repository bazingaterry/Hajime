//
//  HashMap_OA.hpp
//  HashTable
//
//  Created by terrychan on 15/12/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef HashMap_OA_hpp
#define HashMap_OA_hpp

#include "HashMap.hpp"

struct StringPair
{
    std::string first, second;
};

//  Derived class of a hash map with open address method
//  key type : std::string
//  value type : std::string

class HashMap_OA : public HashMap
{
protected:
    const unsigned int increment;
    bool search(const std::string& key, unsigned int& _index) const;
    bool findAddress(const std::string& key, unsigned int& _index) const;
    StringPair* map;
    bool* isInvalid;
    
public:
    HashMap_OA(const unsigned int capacity, unsigned int (*) (const std::string&), const unsigned int increment);
    ~HashMap_OA();
    bool insert(const std::string& key, const std::string& value);
    bool erase(const std::string& key);
    bool find(const std::string& key, std::string& value);
};

#endif /* HashMap_OA_hpp */
