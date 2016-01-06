//
//  Node.hpp
//  HashTable
//
//  Created by terrychan on 15/12/4.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

template <class keyType, class valueType>
class Node
{
public:
	Node();
    keyType key;
	valueType value;
	Node<keyType, valueType>* next;
};

#endif /* Node_hpp */
