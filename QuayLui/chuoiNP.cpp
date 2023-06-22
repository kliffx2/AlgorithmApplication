#include <iostream>

using namespace std;

int x[100], n;

void view_config()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        x[k] = i;
        if (k == n)
        {
            view_config();
        }
        else
        {
            Try(k + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    n = 3;
    Try(1);
    return 0;
}
