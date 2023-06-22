#include <iostream>

using namespace std;

int n[4] = {1, 2, 3, 5};
int c = 4;
int l[4] = {0, 0, 0, 0};
int m = 14;

int select()
{
    int i = c - 1;
    int count = 0;
    while (m > 0 && i >= 0)
    {
        l[i] = m / n[i];
        m -= n[i] * l[i];
        count++;
        i--;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    cout << "Can " << select() << " xe tai" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << n[i] << ": " << l[i] << " xe" << endl;
    }

    return 0;
}
