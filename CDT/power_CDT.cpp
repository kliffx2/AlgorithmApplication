#include <iostream>

using namespace std;

double pow(double a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    double tmp = pow(a, n / 2);
    return (n & 1) ? tmp * tmp * a : tmp * tmp;
}

int main(int argc, char const *argv[])
{
    cout << pow(3, 4);
    cout << 0 % 2;
}
