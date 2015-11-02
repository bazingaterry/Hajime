//
//  Polynomial.hpp
//  PolynomialArithmetic
//
//  Created by terrychan on 15/10/21.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include "map"
#include <iostream>

class Polynomial
{
public:
	Polynomial(bool isOperator = false, char operation = 0);
    double getCoefficient(const int& degree) const;
    void setCoefficient(const int& degree, const double& coefficient);
    int getMaxDegree() const;
    int getMinDegree() const;
    bool isOperator;
    char getOperation() const;
    Polynomial operator+(const Polynomial& polynomial);
    Polynomial operator-(const Polynomial& polynomial);
    Polynomial operator*(const Polynomial& polynomial);
    bool operator==(const Polynomial& polynomial);
    bool operator!=(const Polynomial& polynomial);
    friend std::ostream& operator<<(std::ostream& os, Polynomial polynomial);

private:
    int maxDegree;
    int minDegree;
    int updateMaxDegree();
    int updateMinDegree();
    std::map<int, double> storedPolynomial;
    char operation;
};

#endif /* Polynomial_hpp */
