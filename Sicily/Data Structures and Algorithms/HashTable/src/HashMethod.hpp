//
//  HashMethod.hpp
//  HashTable
//
//  Created by terrychan on 15/12/24.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef HashMethod_hpp
#define HashMethod_hpp

#include <string>

unsigned int AsciiHash(const std::string& s);
unsigned int RSHash(const std::string& s);
unsigned int JSHash(const std::string& s);
unsigned int PJWHash(const std::string& s);
unsigned int ELFHash(const std::string& s);
unsigned int BKDRHash(const std::string& s);
unsigned int SDBMHash(const std::string& s);
unsigned int DJBHash(const std::string& s);
unsigned int APHash(const std::string& s);

#endif /* HashMethod_hpp */
