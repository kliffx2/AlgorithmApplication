#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

int f[MAX];
int s[MAX];

void coin_changing(int n, int c[], int m)
{
    f[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        int min = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            if (c[j] <= i && f[i - c[j]] + 1 < min)
            {
                min = f[i - c[j]] + 1;
                s[i] = j;
            }
        }
        f[i] = min;
    }
}

void result(int n, int c[], int m)
{
    cout << "Minimum number of coins: " << f[m] << endl;
    cout << "Denominations used: ";
    while (m > 0)
    {
        cout << c[s[m]] << " ";
        m -= c[s[m]];
    }
    cout << endl;
}

int main()
{
    int n = 4;  // Số loại tiền mệnh giá
    int c[MAX]; // Mảng chứa mệnh giá của các loại tiền
    c[1] = 1;
    c[2] = 2;
    c[3] = 5;
    c[4] = 10;

    int m; // Số tiền cần chi trả
    cout << "Enter the amount of money to be paid: ";
    cin >> m;

    coin_changing(n, c, m);
    result(n, c, m);

    return 0;
}
