//
//  Node.cpp
//  HashTable
//
//  Created by terrychan on 15/12/4.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "Node.hpp"
#include <string>
#include <cstdlib>

template <class keyType, class valueType>
Node<keyType, valueType>::Node()
{
    next = NULL;
}