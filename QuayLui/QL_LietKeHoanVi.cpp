#include <iostream>

using namespace std;

int x[50], n, dd[50];

void show()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (dd[i] == 0)
        {
            x[k] = i;
            if (k == n)
            {
                show();
            }
            else
            {
                dd[i] = 1;
                Try(k + 1);
                dd[i] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    n = 3;

    for (int i = 1; i <= n; i++)
    {
        dd[i] = 0;
    }

    Try(1);
    return 0;
}
