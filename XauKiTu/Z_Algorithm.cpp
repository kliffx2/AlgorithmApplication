#include <iostream>
#include <string>

using namespace std;

bool zAlgorithm(const string &T, const string &P)
{
    string concat = P + "$" + T;
    int n = concat.length();
    int m = P.length();
    int *Z = new int[n];
    memset(Z, 0, sizeof(Z));

    int L = 0, R = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && concat[R - L] == concat[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            int k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else
            {
                L = i;
                while (R < n && concat[R - L] == concat[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
        if (Z[i] == m)
            return true;
    }
    return false;
}
int main()
{
    if (zAlgorithm())
    {
    }
}
