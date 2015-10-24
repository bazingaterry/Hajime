//
//  main.cpp
//  PolynomialArithmetic
//
//  Created by terrychan on 15/10/21.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Polynomial.hpp"

int main(int argc, const char * argv[])
{
    Polynomial p1;
    {
    	int degree;
	    double coefficient;
	    std::string inputString;
	    std::cout << "Please input degree and coefficient separate by a space in one line\n";
	    std::getline(std::cin, inputString);
	    std::stringstream inputStringStream(inputString);
	    while (inputStringStream >> degree >> coefficient)
	    	p1.setCoefficient(degree, coefficient);
	}

    char operation;
    std::cout << "Please input operation ( + - * ) : ";
    std::cin >> operation;

    getchar();	//	remove the '\n' int buffer

	Polynomial p2;
    {

    	int degree;
	    double coefficient;
	    std::string inputString;
	    std::cout << "Please input degree and coefficient separate by a space in one line\n";
	    std::getline(std::cin, inputString);
	    std::stringstream inputStringStream(inputString);
	    while (inputStringStream >> degree >> coefficient)
    		p2.setCoefficient(degree, coefficient);
    }

    std::cout << "Result : \n" << "(" << p1 << " ) " << operation << " (" << p2 << " ) = " << std::endl;
    switch(operation)
    {
        case '+':
        {
            std::cout << p1 + p2 << std::endl;
            break;
        }
        case '-':
        {
            std::cout << p1 - p2 << std::endl;
            break;
        }
        case '*':
        {
            std::cout << p1 * p2 << std::endl;
            break;
        }
    }
    return 0;
}
