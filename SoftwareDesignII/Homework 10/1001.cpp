class MyPoint
{
protected:
    double x, y;
    
public:
    // The no-arg constructor that contruccts a point with coordinates(0,0)
    MyPoint();
 
    MyPoint(double x, double y);
    double getX() const;
    double getY() const;
 
    //display the distance between two podoubles in two-dimensional space.
    double distance(const MyPoint& point);
};

MyPoint::MyPoint()
{
	x = 0.0;
	y = 0.0;
}

MyPoint::MyPoint(double x, double y)
{
	this->x= x;
	this->y= y;
}

double MyPoint::getX() const
{
	return x;
}

double MyPoint::getY() const
{
	return y;
}

double MyPoint::distance(const MyPoint& point)
{
	return sqrt(pow(point.x - this->x, 2) + pow(point.y - this->y, 2));
}

class ThreeDPoint : public MyPoint
{
private:
    double z;
    
public:
    // The no-arg constructor that contruccts a point with coordinates(0,0,0) 
    ThreeDPoint();
 
    ThreeDPoint(double x, double y, double z);
    double getZ() const;
 
    //display the distance between two points in Three-dimensional space.
    double distance(const ThreeDPoint& point); 
};

ThreeDPoint::ThreeDPoint()
{
	z = 0.0;
}

ThreeDPoint::ThreeDPoint(double x, double y, double z):MyPoint(x, y)
{
	this->z = z;
}

double ThreeDPoint::getZ() const
{
	return z;
}

double ThreeDPoint::distance(const ThreeDPoint& point)
{
	return sqrt(pow(point.x-this->x, 2) + pow(point.y - this->y, 2) + pow(point.z - this->z, 2));
}
