class Double
{
private:
    double data;

public:
    Double();
    Double(double data);
    double getDouble() const;
    void setDouble(double data);
    void add(const Double &other);
    void sub(const Double &other);
    void mul(const Double &other);
    bool div(const Double &other);
};

Double::Double()
{
	data = 0;
}

Double::Double(double data)
{
	this->data = data;
}

double Double::getDouble() const
{
	return data;
}

void Double::setDouble(double newData)
{
	data = newData;
}

void Double::add(const Double &other)
{
	data += other.getDouble();
}

void Double::sub(const Double &other)
{
	data -= other.getDouble();
}

void Double::mul(const Double &other)
{
	data *= other.getDouble();
}

bool Double::div(const Double &other)
{
	if (other.getDouble() == 0)
    {
        return false;
    }
    else
    {
        data /= other.getDouble();
        return true;
    }
}

int main(int argc, char const *argv[])
{
	Double d;
	return 0;
}