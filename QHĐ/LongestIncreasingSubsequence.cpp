#include <iostream>
using namespace std;

const int MAX = 100;

int a[MAX];
int L[MAX];
int T[MAX];

void algorithm(int n)
{
    a[0] = -2147483648;
    a[n + 1] = 2147483647;
    L[n + 1] = 1;
    for (int i = n; i >= 0; i--)
    {
        int jmax = n + 1;
        for (int j = i + 1; j <= n + 1; j++)
        {
            if (a[j] > a[i] && L[j] > L[jmax])
            {
                jmax = j;
            }
        }
        L[i] = L[jmax] + 1;
        T[i] = jmax;
    }
}

void result(int n)
{
    int k = T[0];
    cout << "Length of the longest increasing subsequence: " << L[0] - 1 << endl;
    cout << "Increasing subsequence: ";
    while (k != n + 1)
    {
        cout << "a[" << k << "]: " << a[k] << " ";
        k = T[k];
    }
    cout << endl;
}

int main()
{
    int n = 15; // Số lượng phần tử trong dãy
    // Khởi tạo dãy gồm tối thiểu 15 số thực
    a[1] = 1.5;
    a[2] = 2.3;
    a[3] = 0.8;
    a[4] = 3.7;
    a[5] = 1.2;
    a[6] = 4.9;
    a[7] = 2.1;
    a[8] = 3.5;
    a[9] = 0.6;
    a[10] = 2.6;
    a[11] = 5.2;
    a[12] = 3.9;
    a[13] = 4.1;
    a[14] = 1.9;
    a[15] = 2.8;

    algorithm(n);
    result(n);

    return 0;
}
