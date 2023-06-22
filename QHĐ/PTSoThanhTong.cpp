#include <iostream>

using namespace std;
const int MAX = 100;
int a[MAX][MAX];
int f(int m, int n)
{
    if (m == 0)
    {
        if (n == 0)
        {
            a[m][n] = 1;
        }
        else
            a[m][n] = 0;
    }
    else
    {
        if (m > n)
            a[m][n] = f(m - 1, n);
        else
            a[m][n] = f(m - 1, n) + f(m, n - m);
    }
    return a[m][n];
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    cout << "So cach phan tich" << f(m, n);
    return 0;
}
