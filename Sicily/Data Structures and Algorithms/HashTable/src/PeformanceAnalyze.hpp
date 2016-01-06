//
//  PeformanceAnalyze.hpp
//  HashTable
//
//  Created by terrychan on 15/12/4.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef PeformanceAnalyze_hpp
#define PeformanceAnalyze_hpp

#include <ctime>
#include "HashMap.hpp"

class HashMap;

class PeformanceAnalyze
{
private:
    clock_t begin;
    const HashMap* func;

public:
    PeformanceAnalyze(const HashMap*);
    ~PeformanceAnalyze();
};

#endif /* PeformanceAnalyze_hpp */