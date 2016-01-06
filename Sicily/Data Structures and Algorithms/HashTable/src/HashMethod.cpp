//
//  HashMethod.cpp
//  HashTable
//
//  Created by terrychan on 15/12/24.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "HashMethod.hpp"

//  different hash methods

unsigned int AsciiHash(const std::string& s)
{
    int hash = 0;
    for (int i = 0; i < s.size(); ++i)
        hash += s[i];
    return hash;
}

unsigned int RSHash(const std::string& s)
{
    unsigned int b = 378551 ;
    unsigned int a = 63689 ;
    unsigned int hash = 0 ;
    for (int i = 0; i < s.size(); ++i)
    {
        hash = hash * a + s[i];
        a *= b ;
    }
    return hash;
}

unsigned int JSHash(const std::string& s) 
{ 
    unsigned int hash = 1315423911;    
    for (int i = 0; i < s.size(); ++i)
    { 
        hash ^= ((hash << 5) + s[i] + ( hash >> 2 )); 
    }      
    return hash;
}

unsigned int PJWHash(const std::string& s) 
{ 
    unsigned int BitsInUnignedInt = (unsigned int)(sizeof(unsigned int) * 8); 
    unsigned int ThreeQuarters = (unsigned int)((BitsInUnignedInt * 3) / 4); 
    unsigned int OneEighth = (unsigned int)(BitsInUnignedInt / 8); 
    unsigned int HighBits = (unsigned int)(0xFFFFFFFF) << (BitsInUnignedInt - OneEighth); 
    unsigned int hash = 0;
    unsigned int test = 0;    
    for (int i = 0; i < s.size(); ++i)
    { 
        hash = (hash << OneEighth) + s[i]; 
        if((test = hash&HighBits) != 0) 
        { 
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits)); 
        } 
    }      
    return hash; 
}

unsigned int ELFHash(const std::string& s) 
{ 
    unsigned int hash = 0 ; 
    unsigned int x = 0 ;    
    for (int i = 0; i < s.size(); ++i)
    { 
        hash = (hash << 4) + s[i]; 
        if((x = hash & 0xF0000000L) != 0)
        { 
            hash ^= (x >> 24); 
            hash &= ~x; 
        } 
    }     
    return hash; 
}

unsigned int BKDRHash(const std::string& s) 
{ 
    unsigned int seed = 131;//  31 131 1313 13131 131313 etc..  
    unsigned int hash = 0;     
    for (int i = 0; i < s.size(); ++i)
    { 
        hash = hash * seed + s[i]; 
    }     
    return hash; 
}

unsigned int SDBMHash(const std::string& s) 
{ 
    unsigned int hash = 0 ;     
    for (int i = 0; i < s.size(); ++i)
    { 
        hash = s[i] + (hash << 6) + (hash << 16) - hash; 
    }     
    return hash;
}

unsigned int DJBHash(const std::string& s) 
{ 
    unsigned int hash = 5381;    
    for (int i = 0; i < s.size(); ++i)
    { 
        hash += (hash << 5) + s[i]; 
    }      
    return hash; 
}

unsigned int APHash(const std::string& s) 
{ 
    unsigned int hash = 0;     
    for (int i = 0; i < s.size(); ++i)
    { 
        if (i & 1) 
            hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
        else  
            hash ^= ((hash << 7) ^ s[i] ^ (hash>>3)); 
    }      
    return hash; 
}