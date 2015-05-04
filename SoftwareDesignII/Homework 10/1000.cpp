/*
class GeometricObject
{
public:
    GeometricObject() 
    {
        color = "white";
        filled = false;
    }
    
    GeometricObject(string color, bool filled)
    {
        this->color = color;
        this->filled = filled;
    }
 
    string getColor()
    { 
		return color; 
	}
 
    void setColor(string color)
    {
		this->color = color;
	}
 
    bool isFilled()
    {
		return filled;
	}
 
    void setFilled(bool filled)
    { 
		this->filled = filled;
	}
 
    string toString()
    {
        return "Geometric object color "+color +
               " filled " + ((filled) ? "true" : "false");
    }
    
private:
    string color;
    bool filled;
};

*/

#include "cmath"
#include "cstdio"

class Triangle:public GeometricObject
{
public: 
    Triangle(double side1 = 1.0, double side2 = 1.0, double side3 = 1.0)
    {
        if(side1 + side2 > side3 && abs(side1 - side2) < side3 && side1 > 0 && side2 > 0 && side3 > 0)
        {
            this->side1 = side1;
            this->side2 = side2;
            this->side3 = side3;
        }
        else
        {
            this->side1 = this->side2 = this->side3 = 1.0;
            printf("%s", "illegal sides!\n");
        }
    }
    
    double getArea()
    {
        double halfPerimeter = getPerimeter() / 2;
        return sqrt((halfPerimeter - side1) * (halfPerimeter - side2) * 
                    (halfPerimeter - side3) * halfPerimeter);
    }
    
    double getPerimeter()
    {
        return side1 + side2 + side3;
    }
    
    double getside1() const
    {
        return side1;
    }
    
    double getside2() const
    {
        return side2;
    }
    
    double getside3() const
    {
        return side3;
    }
    
private:
    double side1, side2, side3;
};                                 
