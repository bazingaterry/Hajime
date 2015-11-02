//
//  Polynomial.cpp
//  PolynomialArithmetic
//
//  Created by terrychan on 15/10/21.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "Polynomial.hpp"
#include <cmath>

Polynomial::Polynomial(bool isOperator, char operation)
{
    maxDegree = 0;
    minDegree = 0;
    this->isOperator = isOperator;
    if (isOperator) this->operation = operation;
}

double Polynomial::getCoefficient(const int& degree) const
{
    auto iterator = storedPolynomial.find(degree);
    if (iterator == storedPolynomial.end())
        return 0;
    else
        return iterator->second;
}

void Polynomial::setCoefficient(const int& degree, const double& coefficient)
{
    storedPolynomial[degree] = coefficient;
    if (degree > maxDegree) maxDegree = degree;
    if (degree < minDegree) minDegree = degree;
    maxDegree = updateMaxDegree();
    minDegree = updateMinDegree();
}

int Polynomial::getMaxDegree() const
{
    return maxDegree;
}

int Polynomial::getMinDegree() const
{
    return minDegree;
}

char Polynomial::getOperation() const
{
    return operation;
}

Polynomial Polynomial::operator+(const Polynomial& polynomial)
{
    Polynomial result;
    for (int degree = std::min(this->getMinDegree(), polynomial.getMinDegree()); degree <= std::max(this->getMaxDegree(), polynomial.getMaxDegree()); ++degree)
    {
        if (this->getCoefficient(degree) != 0.0 || polynomial.getCoefficient(degree) != 0.0)
        {
            result.setCoefficient(degree, this->getCoefficient(degree) + polynomial.getCoefficient(degree));
        }
    }
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& polynomial)
{
    Polynomial result;
    for (int degree = std::min(this->getMinDegree(), polynomial.getMinDegree()); degree <= std::max(this->getMaxDegree(), polynomial.getMaxDegree()); ++degree)
    {
        if (this->getCoefficient(degree) != polynomial.getCoefficient(degree))
        {
            result.setCoefficient(degree, this->getCoefficient(degree) - polynomial.getCoefficient(degree));
        }
    }
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& polynomial)
{
    Polynomial result;
    for (int degree0 = this->getMinDegree(); degree0 <= this->getMaxDegree(); ++degree0)
    {
        for (int degree1 = polynomial.getMinDegree(); degree1 <= polynomial.getMaxDegree(); ++degree1)
        {
            result.setCoefficient(degree0 + degree1, this->getCoefficient(degree0) * polynomial.getCoefficient(degree1) + result.getCoefficient(degree0 + degree1));
        }
    }
    return result;
}

bool Polynomial::operator==(const Polynomial& polynomial)
{
    if (this->isOperator != polynomial.isOperator)
    {
        return false;
    }
    else
    {
        if (this->isOperator)
        {
            return this->operation == polynomial.getOperation();
        }
        else
        {
            for (int degree = std::min(this->getMinDegree(), polynomial.getMinDegree()); degree <= std::max(this->getMaxDegree(), polynomial.getMaxDegree()); ++degree)
            {
                if (this->getCoefficient(degree) != polynomial.getCoefficient(degree))
                    return false;
            }
            return true;
        }
    }
}

bool Polynomial::operator!=(const Polynomial& polynomial)
{
    return !(*this == polynomial);
}

std::ostream& operator<<(std::ostream& os, Polynomial polynomial)
{
    if (polynomial.isOperator)
    {
        os << polynomial.operation;
    }
    else
    {
        if (polynomial.getMaxDegree() == 0 && polynomial.getMinDegree() == 0)
        {
            os << polynomial.getCoefficient(0);
        }
        else
        {
            for (int degree = polynomial.getMaxDegree(); degree >= polynomial.getMinDegree(); --degree)
            {
                if (polynomial.getCoefficient(degree) != 0)
                {
                	if (polynomial.getCoefficient(degree) >= 0) 
                        os << "+";
            		else os << "-";

                	if (degree == 0)
                    {
                        os << std::abs(polynomial.getCoefficient(degree));
                        return os;
                    }
                    else
                    {
                        if (std::abs(polynomial.getCoefficient(degree)) != 1)
                            os << std::abs(polynomial.getCoefficient(degree));
                        if (degree == 1)
                            os << "x";
                        else
                            os << "x^" << degree;
                    }
                }
            }
        }
    }
    return os;
}

int Polynomial::updateMaxDegree()
{
	for (int i = maxDegree; i >= minDegree; --i)
	{
		if (storedPolynomial[i] != 0) return i;
	}
	return 0;
}

int Polynomial::updateMinDegree()
{
	for (int i = minDegree; i <= maxDegree; ++i)
	{
		if (storedPolynomial[i] != 0) return i;
	}
	return 0;
}