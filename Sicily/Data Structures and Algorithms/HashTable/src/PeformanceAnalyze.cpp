//
//  PeformanceAnalyze.cpp
//  HashTable
//
//  Created by terrychan on 15/12/4.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "PeformanceAnalyze.hpp"

PeformanceAnalyze::PeformanceAnalyze(const HashMap* hm) : func(hm)
{
    begin = clock();
}

PeformanceAnalyze::~PeformanceAnalyze()
{
    func->count += clock() - begin;
}