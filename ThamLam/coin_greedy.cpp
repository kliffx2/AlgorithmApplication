#include <iostream>

using namespace std;

bool algo(int C[], int m, long n, int *S)
{
    for (int i = 0; i < m; i++)
    {
        S[i] = 0;
    }
    int i = 0;
    while (n > 0 && i < m)
    {
        S[i] = n / C[i];
        n -= S[i] * C[i];
        i++;
    }
    if (n > 0)
        return false;
    else
        return true;
}

int main(int argc, char const *argv[])
{
    int n = -5;
    int m = 5;
    int C[] = {100, 25, 10, 5, 1};
    int *S = new int[m];
    if (algo(C, m, n, S))
    {
        for (int i = 0; i < m; i++)
        {
            cout << "Co " << S[i] << " dong menh gia " << C[i] << endl;
        }
    }
    else
    {
        cout << "No solution";
    }
    return 0;
}
