#include <iostream>
using namespace std;

class complex_num
{
private:
    int a;
    int b;

public:
    void setData(int v1, int v2);
    void setDataBySum(complex_num &o1, complex_num &o2);
    void printSum(void);
};
void complex_num::setData(int v1, int v2)
{
    a = v1;
    b = v2;
}
void complex_num::setDataBySum(complex_num &o1, complex_num &o2)
{
    a = o1.a + o2.a;
    b = o1.b + o2.b;
}
void complex_num::printSum(void)
{
    cout << "Your complex number is: " << a << " + " << b << "i" << endl;
}
int main()
{
    complex_num c1, c2, c3;
    c1.setData(2, 3);
    c1.printSum();

    c2.setData(3, 4);
    c2.printSum();

    c3.setDataBySum(c1, c2);
    c3.printSum();
    return 0;
}