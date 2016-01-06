//
//  ListNode.hpp
//  HashTable
//
//  Created by terrychan on 15/12/4.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include "Node.cpp"

template <class keyType, class valueType>
class ListNode
{
private:
    Node<keyType, valueType>* head;
    int size;
    
public:
    ListNode();
    ~ListNode();
    int getSize() const;
    bool insert(const keyType&, const valueType&);
    bool find(const keyType&, valueType&);
    bool exist(const keyType&) const;
    bool remove(const keyType&);
};

#endif /* ListNode_hpp */
