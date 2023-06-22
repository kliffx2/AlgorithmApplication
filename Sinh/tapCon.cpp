#include <iostream>

using namespace std;

string s[6] = {"tam", "toan", "trang", "cong", "trung", "tu"};

void view_config(int x[], int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << s[x[i] - 1] << " ";
    }
    cout << endl;
}

// void next_config(int x[], int k, int i)
// {
//     x[i]++;
//     i++;
//     while (i <= k)
//     {
//         x[i] = x[i - 1] + 1;
//         i++;
//     }
// }

// void listing_configs(int k, int n)
// {
//     int i;
//     int *x = new int[k + 1];
//     for (int i = 1; i <= k + 1; i++)
//     {
//         x[i] = 0;
//     }
//     for (int i = 1; i <= k; i++)
//     {
//         x[i] = i;
//     }

//     do
//     {
//         view_config(x, k);
//         i = k;
//         while (i > 0 && x[i] == n - k + i)
//         {
//             i--;
//         }
//         if (i > 0)
//         {
//             next_config(x, k, i);
//         }
//     } while (i > 0);
// }

void next_config(int x[], int k, int i)
{
    x[i] += 1;
    i++;
    while (i <= k)
    {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

void listing_configs(int k)
{
    int i, n = 6;
    int *x = new int[k + 1];
    for (int i = 1; i <= k + 1; i++)
    {
        x[i] = 0;
    }
    for (int i = 1; i <= k; i++)
    {
        x[i] = i;
    }
    do
    {
        view_config(x, k);
        i = k;
        while (i > 0 && x[i] == n - k + i)
        {
            i--;
        }
        if (i > 0)
        {
            next_config(x, k, i);
        }
    } while (i > 0);
}
int main(int argc, char const *argv[])
{
    listing_configs(4);
    return 0;
}
