//
//  main.cpp
//  HashTable
//
//  Created by terrychan on 15/12/4.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include <iostream>
#include <string>
#include "HashMap_OA.hpp"
#include "HashMap_Chaining.hpp"
#include "HashMethod.hpp"

void hashFunc()
{
    HashMap_OA h1(2000000, AsciiHash, 2);
    HashMap_OA h2(2000000, RSHash, 2);
    HashMap_OA h3(2000000, JSHash,2);
    HashMap_OA h4(2000000, ELFHash,2);
    HashMap_OA h5(2000000, DJBHash,2);
    HashMap_OA h6(2000000, APHash,2);
    HashMap_OA h7(2000000, PJWHash,2);
    int dicSize;
    std::cin >> dicSize;
    for (int i = 0; i < dicSize; ++i)
    {
        std::string key, value;
        std::cin >> key >> value;
        h1.insert(key, value);
        h2.insert(key, value);
        h3.insert(key, value);
        h4.insert(key, value);
        h5.insert(key, value);
        h6.insert(key, value);
        h7.insert(key, value);
    }
    std::cout << h1.getExecutionTimes() << ' ' << h1.getCollisionTimes() << '\n' << h1.getTime() << "ms\n";
    std::cout << h2.getExecutionTimes() << ' ' << h2.getCollisionTimes() << '\n' << h2.getTime() << "ms\n";
    std::cout << h3.getExecutionTimes() << ' ' << h3.getCollisionTimes() << '\n' << h3.getTime() << "ms\n";
    std::cout << h4.getExecutionTimes() << ' ' << h4.getCollisionTimes() << '\n' << h4.getTime() << "ms\n";
    std::cout << h5.getExecutionTimes() << ' ' << h5.getCollisionTimes() << '\n' << h5.getTime() << "ms\n";
    std::cout << h6.getExecutionTimes() << ' ' << h6.getCollisionTimes() << '\n' << h6.getTime() << "ms\n";
    std::cout << h7.getExecutionTimes() << ' ' << h7.getCollisionTimes() << '\n' << h7.getTime() << "ms\n";
}

void increment()
{
    HashMap_OA h1(4000000, RSHash, 1);
    HashMap_OA h2(4000000, RSHash, 2);
    HashMap_OA h3(4000000, RSHash, 3);
    HashMap_OA h4(4000000, RSHash, 4);
    int dicSize;
    std::cin >> dicSize;
    for (int i = 0; i < dicSize; ++i)
    {
        std::string key, value;
        std::cin >> key >> value;
        h1.insert(key, value);
        h2.insert(key, value);
        h3.insert(key, value);
        h4.insert(key, value);
    }
    std::cout << h1.getExecutionTimes() << ' ' << h1.getCollisionTimes() << '\n' << h1.getTime() << "ms\n";
    std::cout << h2.getExecutionTimes() << ' ' << h2.getCollisionTimes() << '\n' << h2.getTime() << "ms\n";
    std::cout << h3.getExecutionTimes() << ' ' << h3.getCollisionTimes() << '\n' << h3.getTime() << "ms\n";
    std::cout << h4.getExecutionTimes() << ' ' << h4.getCollisionTimes() << '\n' << h4.getTime() << "ms\n";
}

void oa_vs_ch()
{
    HashMap_OA h1(2000000, RSHash, 2);
    HashMap_Chaining h2(2000000, RSHash);
    int dicSize;
    std::cin >> dicSize;
    for (int i = 0; i < dicSize; ++i)
    {
        std::string key, value;
        std::cin >> key >> value;
        h1.insert(key, value);
        h2.insert(key, value);
    }
    std::cout << h1.getExecutionTimes() << ' ' << h1.getCollisionTimes() << '\n' << h1.getTime() << "ms\n";
    std::cout << h2.getExecutionTimes() << ' ' << h2.getCollisionTimes() << '\n' << h2.getTime() << "ms\n";
    h1.clearTime();
    h2.clearTime();
    int querySize;
    std::cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        std::string key, value;
        std::cin >> key;
        h1.find(key, value);
        h2.find(key, value);
    }
    std::cout  << h1.getTime() << "ms\n";
    std::cout  << h2.getTime() << "ms\n";
}

void cap()
{
    HashMap_OA h1(1010000, RSHash, 2);
    HashMap_OA h2(1100000, RSHash, 2);
    HashMap_OA h3(1500000, RSHash, 2);
    HashMap_OA h4(3000000, RSHash, 2);
    HashMap_OA h5(5000000, RSHash, 2);
    HashMap_OA h6(10000000, RSHash, 2);
    HashMap_Chaining h7(100000, RSHash);
    HashMap_Chaining h8(500000, RSHash);
    HashMap_Chaining h9(1000000, RSHash);
    HashMap_Chaining h10(3000000, RSHash);
    HashMap_Chaining h11(5000000, RSHash);
    HashMap_Chaining h12(10000000, RSHash);
    int dicSize;
    std::cin >> dicSize;
    for (int i = 0; i < dicSize; ++i)
    {
        std::string key, value;
        std::cin >> key >> value;
        h1.insert(key, value);
        h2.insert(key, value);
        h3.insert(key, value);
        h4.insert(key, value);
        h5.insert(key, value);
        h6.insert(key, value);
        h7.insert(key, value);
        h8.insert(key, value);
        h9.insert(key, value);
        h10.insert(key, value);
        h11.insert(key, value);
        h12.insert(key, value);
    }
    std::cout << h1.getExecutionTimes() << ' ' << h1.getCollisionTimes() << ' ' << h1.getTime() << "ms\n";
    std::cout << h2.getExecutionTimes() << ' ' << h2.getCollisionTimes() << ' ' << h2.getTime() << "ms\n";
    std::cout << h3.getExecutionTimes() << ' ' << h3.getCollisionTimes() << ' ' << h3.getTime() << "ms\n";
    std::cout << h4.getExecutionTimes() << ' ' << h4.getCollisionTimes() << ' ' << h4.getTime() << "ms\n";
    std::cout << h5.getExecutionTimes() << ' ' << h5.getCollisionTimes() << ' ' << h5.getTime() << "ms\n";
    std::cout << h6.getExecutionTimes() << ' ' << h6.getCollisionTimes() << ' ' << h6.getTime() << "ms\n";
    std::cout  << h7.getTime() << "ms\n";
    std::cout  << h8.getTime() << "ms\n";
    std::cout  << h9.getTime() << "ms\n";
    std::cout  << h10.getTime() << "ms\n";
    std::cout  << h11.getTime() << "ms\n";
    std::cout  << h12.getTime() << "ms\n";
    h1.clearTime();
    h2.clearTime();
    h3.clearTime();
    h4.clearTime();
    h5.clearTime();
    h6.clearTime();
    h7.clearTime();
    h8.clearTime();
    h9.clearTime();
    h10.clearTime();
    h11.clearTime();
    h12.clearTime();
    int querySize;
    std::cin >> querySize;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0; 
    for (int i = 0; i < querySize; ++i)
    {
        std::string key, value;
        std::cin >> key;
        if (!h1.find(key, value)) count1++;
        if (!h2.find(key, value)) count2++;
        if (!h3.find(key, value)) count3++;
        if (!h4.find(key, value)) count4++;
        if (!h5.find(key, value)) count5++;
        if (!h6.find(key, value)) count6++;
        h7.find(key, value);
        h8.find(key, value);
        h9.find(key, value);
        h10.find(key, value);
        h11.find(key, value);
        h12.find(key, value);
    }
    std::cout << h1.getExecutionTimes() << ' ' << h1.getCollisionTimes() << ' ' << h1.getTime() << "ms " << count1 << '\n';
    std::cout << h2.getExecutionTimes() << ' ' << h2.getCollisionTimes() << ' ' << h2.getTime() << "ms " << count2 << '\n';
    std::cout << h3.getExecutionTimes() << ' ' << h3.getCollisionTimes() << ' ' << h3.getTime() << "ms " << count3 << '\n';
    std::cout << h4.getExecutionTimes() << ' ' << h4.getCollisionTimes() << ' ' << h4.getTime() << "ms " << count4 << '\n';
    std::cout << h5.getExecutionTimes() << ' ' << h5.getCollisionTimes() << ' ' << h5.getTime() << "ms " << count5 << '\n';
    std::cout << h6.getExecutionTimes() << ' ' << h6.getCollisionTimes() << ' ' << h6.getTime() << "ms " << count6 << '\n';
    std::cout  << h7.getTime() << "ms\n";
    std::cout  << h8.getTime() << "ms\n";
    std::cout  << h9.getTime() << "ms\n";
    std::cout  << h10.getTime() << "ms\n";
    std::cout  << h11.getTime() << "ms\n";
    std::cout  << h12.getTime() << "ms\n";
}

void del()
{
    HashMap_OA h1(10000, RSHash, 2);
    HashMap_Chaining h2(10000, RSHash);
    int dicSize;
    std::cin >> dicSize;
    for (int i = 0; i < dicSize; ++i)
    {
        std::string key, value;
        std::cin >> key >> value;
        h1.insert(key, value);
        h2.insert(key, value);
    }
    std::cout << h1.getExecutionTimes() << ' ' << h1.getCollisionTimes() << '\n' << h1.getTime() << "ms\n";
    std::cout << h2.getExecutionTimes() << ' ' << h2.getCollisionTimes() << '\n' << h2.getTime() << "ms\n";
    h1.clearTime();
    h2.clearTime();
    int delSize;
    std::cin >> delSize;
    for (int i = 0; i < delSize; ++i)
    {
        std::string key;
        std::cin >> key;
        h1.erase(key);
        h2.erase(key);
    }
    std::cout  << h1.getTime() << "ms\n";
    std::cout  << h2.getTime() << "ms\n";
    int querySize;
    std::cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        std::string key, value;
        std::cin >> key;
        h1.find(key, value);
        h2.find(key, value);
    }
    std::cout  << h1.getTime() << "ms\n";
    std::cout  << h2.getTime() << "ms\n";
}

void size()
{
    HashMap_OA h1(6000000, RSHash, 2);
    HashMap_Chaining h2(6000000, RSHash);
    int dicSize;
    std::cin >> dicSize;
    for (int i = 0; i < dicSize; ++i)
    {
        std::string key, value;
        std::cin >> key >> value;
        h1.insert(key, value);
        h2.insert(key, value);

    }
    std::cout  << h1.getTime() << "ms\n";
    std::cout  << h2.getTime() << "ms\n";

}


int main(int argc, const char * argv[])
{
//    hashFunc();
//  increment();
//  oa_vs_ch();
//   cap();
//    del();
//    size();
    return 0;
}
