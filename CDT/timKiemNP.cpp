#include <iostream>

using namespace std;

int a[] = {1, 3, 4, 5, 7, 8, 9, 10, 12};

int TKNP(int c, int l, int r)
{
    int m = (l + r) / 2;
    if (a[m] == c)
        return m;
    if (a[m] < c)
        return TKNP(c, m + 1, r);
    else
        return TKNP(c, l, m);
}

int main(int argc, char const *argv[])
{
    cout << TKNP(10, 0, 8);
    return 0;
}
