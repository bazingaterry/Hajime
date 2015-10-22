//
//  main.cpp
//  LifeGame
//
//  Created by terrychan on 15/10/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include <iostream>
#include <string>
#include "LifeGame.hpp"


int main(int argc, const char * argv[])
{
    std::cout << "Please input test case address: ";
    std::string testCaseAddress;
    std::cin >> testCaseAddress;
    std::cout << "Please input output data address: ";
    std::string outPutAddress;
    std::cin >> outPutAddress;
    std::cout << "Please input times of generation: ";
    unsigned int times;
    std::cin >> times;
    std::cout << "Enable debug mode?\n";
    bool isDebug;
    std::cin >> isDebug;
    LifeGame myGame(testCaseAddress, outPutAddress, isDebug);
    myGame.run(times);
    return 0;
}