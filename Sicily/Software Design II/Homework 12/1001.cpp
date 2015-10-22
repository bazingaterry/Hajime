class B : public A, public C
{
public:
    B(int a = 11, int c = 22) : A(a), C(c)
    {}
};                                 