#include <iostream>
#include <cstring>
using namespace std;

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

string Q = "This is the first sentence child.";
string P = "abcabdefg";
string S1 = "abc";

char s[10] = "abcabdefg";
char p[5] = "abc";

int sum(int a[], int l, int r)
{
    if (l == r)
        return a[l];
    else
    {
        int m = (l + r) / 2;
        int l_sum = sum(a, l, m);
        int r_sum = sum(a, m + 1, r);
        return l_sum + r_sum;
    }
}

int algo(int a[], int n, int C, int *S)
{
    for (int i = 0; i < n; i++)
    {
        S[i] = 0;
    }
    int i = 0;
    int count = 0;
    while (i < n && C > 0)
    {
        if (C - a[i] >= 0)
        {
            S[i]++;
            C -= a[i];
            i++;
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

int char_in_string(char c, char *p)
{
    for (int i = 0; i < strlen(p); i++)
    {
        if (p[i] == c)
            return i;
    }
    return -1;
}

int Boyer_Moore_Horspool()
{
    int dem = 0, i = strlen(p), v = strlen(p);
    while (i < strlen(s))
    {
        int x = v - 1, j = i - 1;
        while (s[j] == p[x] && x > -1)
        {
            j--;
            x--;
        }
        if (x < 0)
        {
            dem++;
            i = i + v;
        }
        else
        {
            x = char_in_string(s[j], p);
            if (x < 0)
                i = i + v;
            else
                i = i + v - x - 1;
        }
    }
    return dem;
}

bool zAlgo(string &T, string &P)
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
            {
                R++;
            }
            Z[i] = R - L;
            R--;
        }
        else
        {
            int k = i - L;
            if (Z[k] < R - i + 1)
            {
                Z[i] = Z[k];
            }
            else
            {
                L = i;
                while (R < n && concat[R - L] == concat[R])
                {
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
        if (Z[i] == m)
            return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int n = 10;
    int C = 16;
    int *S = new int[n];
    cout << "Tong: " << sum(a, 0, 9) << endl;
    cout << "Lay duoc nhieu nhat " << algo(a, n, C, S) << " so" << endl;
    for (int i = 0; i < n; i++)
    {
        if (S[i] == 1)
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    if (Boyer_Moore_Horspool() == 0)
    {
        cout << p << " khong co trong " << s;
    }
    else
    {
        cout << p << " xuat hien " << Boyer_Moore_Horspool() << " lan trong " << s;
    }
    cout << endl;
    if (zAlgo(P, S1))
    {
        cout << S1 << " co nam trong " << P;
    }

    return 0;
}
