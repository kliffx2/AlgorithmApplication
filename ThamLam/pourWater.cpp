#include <iostream>

using namespace std;

// C chua gia tri {8 5 4 3 2}
// m la so gia tri cua C
// S mang gia tri 0
// n la so nuoc
int algo(int C[], int m, int n, int S[])
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
    int m, n;
    int S[10];
    int C[10];
    // int *C = new int[m];
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> C[i];
    }
    cout << "So binh chua day nuoc la: " << algo(C, m, n, S) << endl;
    for (int i = 0; i < m; i++)
    {
        cout << C[i] << ": " << S[i] << endl;
    }

    return 0;
}
