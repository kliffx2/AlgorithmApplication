#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;
int F[MAX][MAX];
// 1.3
//  int a[10] = {-4, -3, -2, -1, 0, 1, 2, 3, 4};

// int sum(int a[], int l, int r)
// {
//     if (l == r)
//     {
//         return (a[l] > 0) ? a[l] : 0;
//     }
//     else
//     {
//         int m = (l + r) / 2;
//         int l_sum = sum(a, l, m);
//         int r_sum = sum(a, m + 1, r);
//         return l_sum + r_sum;
//     }
// }

class Package
{
private:
    int w;
    int v;

public:
    Package(int w, int n);
    ~Package();
    int getW();
    int getV();
};

Package::Package(int w, int v)
{
    this->w = w;
    this->v = v;
}

Package::~Package()
{
}

int Package::getW()
{
    return this->w;
}

int Package::getV()
{
    return this->v;
}

int algo(Package a[], int n, int C, int *S)
{
    for (int i = 0; i < n; i++)
    {
        S[i] = 0;
    }
    int i = 0;
    int count = 0;
    while (i < n && C - a[i].getV() >= 0)
    {
        S[i]++;
        C -= a[i].getV();
        i++;
        count++;
    }

    return count;
}

void qhd(Package a[], int M, int n)
{
    for (int i = 0; i <= n; i++)
    {
        F[i][0] = 0;
    }
    for (int j = 0; j <= M; j++)
    {
        F[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (a[i - 1].getW() <= j)
            {
                int temp = F[i - 1][j - a[i - 1].getW()] + a[i - 1].getV();
                F[i][j] = max(F[i - 1][j], temp);
            }
            else
            {
                F[i][j] = F[i - 1][j];
            }
        }
    }
}

void result(Package a[], int M, int n)
{
    cout << "Max value: " << F[n][M] << endl;
    int i = n;
    int j = M;
    while (i > 0 && j > 0)
    {
        if (F[i][j] != F[i - 1][j])
        {
            cout << a[i - 1].getW() << " -$" << a[i - 1].getV() << endl;
            j -= a[i - 1].getW();
        }
        i--;
    }
}

int main(int argc, char const *argv[])
{
    // cout << sum(a, 0, 10);
    Package a[5] = {
        Package(1, 5),
        Package(2, 3),
        Package(4, 7),
        Package(2, 2),
        Package(5, 8)};
    int n = 5;
    int C = 7;
    int *S = new int[n];
    // cout << algo(a, n, C, S) << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     if (S[i] == 1)
    //     {
    //         cout << a[i].getW() << ": " << a[i].getV() << endl;
    //     }
    // }
    int M = 8;
    qhd(a, M, n);
    result(a, M, n);
    return 0;
}
