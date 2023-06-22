#include <iostream>

using namespace std;

void next_config(int x[], int n, int i)
{
    x[i] = 1;
    i++;
    while (i <= n)
    {
        x[i] = 0;
        i++;
    }
}

void view_config(int x[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void listing_configs(int n)
{
    int i;
    // int x[n + 1] = {0};
    int *x = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
    do
    {
        view_config(x, n);
        i = n;
        while (i > 0 && x[i] == 1)
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
