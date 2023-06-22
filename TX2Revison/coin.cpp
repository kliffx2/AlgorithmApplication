#include <iostream>

using namespace std;

bool algo(int C[], int m, int n, int *S)
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
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main(int argc, char const *argv[])
{
    int C[5] = {10, 7, 3};
    int m = 3;
    int n = 12;
    int *S = new int[m];
    if (algo(C, m, n, S))
    {
        for (int i = 0; i < m; i++)
        {
            cout << "Co " << S[i] << " to menh gia " << C[i] << endl;
        }
    }
    else
    {
        cout << "No solution";
    }
    return 0;
}
