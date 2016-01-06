//
//  HashMap_Chaining.hpp
//  HashTable
//
//  Created by terrychan on 15/12/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef HashMap_Chaining_hpp
#define HashMap_Chaining_hpp

#include "HashMap.hpp"
#include "ListNode.cpp"

//  Derived class of a hash map with chaining method
//  key type : std::string
//  value type : std::string

class HashMap_Chaining : public HashMap
{
private:
    ListNode<std::string, std::string>* map;
    
public:
    HashMap_Chaining(const int capacity, unsigned int (*) (const std::string&));
    ~HashMap_Chaining();
    bool insert(const std::string& key, const std::string& value);
    bool erase(const std::string& key);
    bool find(const std::string& key, std::string& value);
    friend class ListNode<class keyType, class valueType>;
};

#endif /* HashMap__Chaining_hpp */
