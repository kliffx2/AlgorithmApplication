#include <iostream>

using namespace std;

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int odd_sum(int a[], int n)
{
    if (n == 0)
        return 0;
    int sum = odd_sum(a, n - 1);
    if (a[n - 1] % 2 != 0)
    {
        sum += a[n - 1];
    }
    return sum;
}

int algo(int a[], int n, int C, int *S)
{
    for (int i = 0; i < n; i++)
    {
        S[i] = 0;
    }
    int i = n - 1;
    int count = 0;
    while (i > 0 && C >= 0)
    {

        S[i]++;
        C -= a[i];
        i--;
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int C = 18;
    int *S = new int[n];
    cout << odd_sum(a, 10) << endl;
    cout << "Can lay it nhat " << algo(a, n, C, S) << endl;
    for (int i = 0; i < n; i++)
    {
        if (S[i] == 1)
        {
            cout << a[i] << " ";
        }
    }

    return 0;
}
