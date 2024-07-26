// 3. To write a C++ program to manipulate complex numbers using operator
// overloading. (addition,subtraction,multiplication,division)
#include <iostream>
using namespace std;
class complex
{
public:
    double real, img;
    void setdata()
    {
        cout << "Enter the real number:";
        cin >> real;
        cout << "Enter the imaginary number:";
        cin >> img;
    }
};
complex operator+(complex &c1, complex &c2)
{
    complex after;
    after.real = c1.real + c2.real;
    after.img = c1.img + c2.img;
    return after;
}
complex operator-(complex &c1, complex &c2)
{
    complex after;
    after.real = c1.real - c2.real;
    after.img = c1.img - c2.img;
    return after;
}
complex operator/(complex &c1, complex &c2)
{
    complex after;
    after.real = c1.real / c2.real;
    after.img = c1.img / c2.img;
    return after;
}
complex operator*(complex &c1, complex &c2)
{
    complex after;
    after.real = c1.real * c2.real;
    after.img = c1.img * c2.img;
    return after;
}
int main()
{
    complex first, second, result;
    first.setdata();
    second.setdata();
    cout << "The first complex number is:" << first.real << "+" << first.img << "i" << endl;
    cout << "The second complex number is:" << second.real << "+" << second.img << "i" << endl;
    result = first + second;
    cout << "After addition: " << result.real << "+" << result.img << "i" << endl;
    result = first - second;
    if (result.img >= 0)
    {
        cout << "After subtraction: " << result.real << "+" << result.img << "i" << endl;
    }
    else
        cout << "After subtraction: " << result.real << result.img << "i" << endl;
    result = first * second;
    cout << "After multiplication: " << result.real << "+" << result.img << "i" << endl;
    result = first / second;
    cout << "After division: " << result.real << "+" << result.img << "i" << endl;

    return 0;
}