#include <iostream>

using namespace std;

void view_config(int x[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void next_config(int x[], int n, int i)
{
    int k = n;
    while (x[k] <= x[i])
    {
        k--;
    }
    swap(x[i], x[k]);
    int j = n;
    i++;
    while (i < j)
    {
        swap(x[i], x[j]);
        i++;
        j--;
    }
}

void listing_configs(int n)
{
    int i;
    int *x = new int[n + 1];
    for (int i = 1; i <= n + 1; i++)
    {
        x[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        x[i] = i;
    }
    do
    {
        view_config(x, n);
        i = n - 1;
        while (i > 0 && x[i] > x[i + 1])
        {
            i--;
        }
        if (i > 0)
        {
            next_config(x, n, i);
        }
    } while (i > 0);
}
int main(int argc, char const *argv[])
{
    listing_configs(3);
    return 0;
}
