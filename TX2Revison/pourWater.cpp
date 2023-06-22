#include <iostream>

using namespace std;

int algo(int C[], int m, int n, int *S)
{
    for (int i = 0; i < m; i++)
    {
        S[i] = 0;
    }
    int i = m - 1;
    int count = 0;
    while (n > 0 && i >= 0)
    {
        if (n - C[i] > 0)
        {
            S[i]++;
            n -= C[i];
            count++;
            i--;
        }
        else
        {
            break;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int m = 5;
    int C[5] = {8, 5, 4, 3, 2};
    int *S = new int[m];
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> C[i];
    // }
    cout << algo(C, m, n, S);
    for (int i = 0; i < m; i++)
    {
        cout << S[i] << ": " << C[i] << endl;
    }

    return 0;
}
