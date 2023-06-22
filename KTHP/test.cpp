#include <iostream>

using namespace std;

int MAX = 100;
int a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int min(int a[], int l, int r, int k)
{
    if (l == r)
    {
        return (a[l] > k) ? a[l] : MAX;
    }
    else
    {
        int m = (l + r) / 2;
        int l_min = min(a, l, m, k);
        int r_min = min(a, m + 1, r, k);
        return (l_min < r_min) ? l_min : r_min;
    }
}

int main(int argc, char const *argv[])
{
    cout << min(a, 0, 14, 10);
    return 0;
}
