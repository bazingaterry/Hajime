//
//  main.cpp
//  PolynomialArithmetic
//
//  Created by terrychan on 15/10/21.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <deque>
#include <stack>
#include "Polynomial.hpp"

int main(int argc, char const *argv[])
{
    std::string input;
    std::deque<Polynomial> myDeque;
    std::stack<Polynomial> myStack;
    std::cout << "Please input degree and coefficient separate by a space in one line\n";
    std::cout << "Please input one operation (+ - *) in one line\n";
    std::cout << "Please end you input by EOF\n";

    /* transform infix expression into postfix expression */
    while (std::getline(std::cin, input))
    {
        if (input.size() > 0) // ignore the empty input
        {
            if (input[0] == '+' || input[0] == '-' || input[0] == '*')
            {
                if (input[0] == '*')
                {
                    myStack.push(Polynomial(true, '*'));
                }
                else
                {
                    while (!myStack.empty() && !(myStack.top() == Polynomial(true, '(')))
                    {
                        myDeque.push_back(myStack.top());
                        myStack.pop();
                    }
                    myStack.push(Polynomial(true, input[0]));
                }
            }
            else if (input[0] == '(' || input[0] == ')')
            {
                if (input[0] == '(')
                {
                    myStack.push(Polynomial(true, '('));
                }
                else if (input[0] == ')')
                {
                    while (myStack.top() != Polynomial(true, '('))
                    {
                        myDeque.push_back(myStack.top());
                        myStack.pop();
                    }
                    myStack.pop();
                }
            }
            else if ('0' <= input[0] && input[0] <= '9')
            {
                Polynomial p;
                int degree;
                double coefficient;
                std::stringstream inputSS(input);
                while (inputSS >> degree >> coefficient)
                    p.setCoefficient(degree, coefficient);
                myDeque.push_back(p);
            }
            else
                std::cout << "input is invalid, please try again\n";
        }
        else
            std::cout << "input is invalid, please try again\n";
    }
    while (!myStack.empty())
    {
        myDeque.push_back(myStack.top());
        myStack.pop();
    }
    /*  endl transform  */
    
    /*  print postfix expression  */
    std::cout << "The postfix expression is : \n";
    for (auto it = myDeque.begin(); it != myDeque.end(); it++)
    {
        std::cout << '(' << *it << ')';
    }
    std::cout << std::endl;
    
    /*  calculate Result  */
    for (auto it = myDeque.begin(); it != myDeque.end(); it++)
    {
        if (it->isOperator)
        {
            if (it->getOperation() == '+')
            {
                Polynomial p1 = myStack.top();
                myStack.pop();
                Polynomial p2 = myStack.top();
                myStack.pop();
                myStack.push(p1 + p2);
            }
            else if (it->getOperation() == '-')
            {
                Polynomial p1 = myStack.top();
                myStack.pop();
                Polynomial p2 = myStack.top();
                myStack.pop();
                myStack.push(p1 - p2);
            }
            else if (it->getOperation() == '*')
            {
                Polynomial p1 = myStack.top();
                myStack.pop();
                Polynomial p2 = myStack.top();
                myStack.pop();
                myStack.push(p1 * p2);
            } 
        }
        else
        {
            myStack.push(*it);
        }
    }

    /*  print the Result  */
    std::cout << "The result is : \n" << myStack.top() << std::endl;
    
    return 0;
}
