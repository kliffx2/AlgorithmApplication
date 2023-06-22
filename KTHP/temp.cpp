#include <iostream>
#include <cstring>
#define NO_OF_CHAR 256
using namespace std;

const int MAX = 100;
int F[MAX][MAX];
class Class
{
private:
    string maLop;
    int siSo;
    int soNu;

public:
    Class(string maLop, int siSo, int soNu);
    ~Class();
    string getMaLop();
    int getSiSo();
    int getSoNu();
};

Class::Class(string maLop, int siSo, int soNu)
{
    this->maLop = maLop;
    this->siSo = siSo;
    this->soNu = soNu;
}

Class::~Class()
{
}

string Class::getMaLop()
{
    return this->maLop;
}

int Class::getSiSo()
{
    return this->siSo;
}

int Class::getSoNu()
{
    return this->soNu;
}

int greedy(Class d[], int m, int n, int *S)
{
    for (int i = 0; i < m; i++)
    {
        S[i] = 0;
    }
    int i = 0;
    int count = 0;
    while (i < m && n > 0)
    {
        if (n - d[i].getSiSo() >= 0)
        {
            S[i]++;
            n -= d[i].getSiSo();
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

void qhd(Class p[], int k, int m)
{
    for (int i = 0; i <= m; i++)
    {
        F[i][0] = 0;
    }
    for (int j = 0; j <= k; j++)
    {
        F[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (p[i - 1].getSiSo() <= j)
            {
                int temp = F[i - 1][j - p[i - 1].getSiSo()] + p[i - 1].getSoNu();
                F[i][j] = max(F[i - 1][j], temp);
            }
            else
            {
                F[i][j] = F[i - 1][j];
            }
        }
    }
}

void result(Class p[], int k, int m)
{
    cout << "Max value: " << F[m][k] << endl;
    int i = m, j = k;
    while (i > 0 && j > 0)
    {
        if (F[i][j] != F[i - 1][j])
        {
            cout << p[i - 1].getMaLop() << ": " << p[i - 1].getSoNu() << endl;
            j -= p[i - 1].getSoNu();
        }
        i--;
    }
}
int char_in_string(char k, char p[])
{
    int len = strlen(p);
    for (int i = len - 1; i >= 0; i--)
    {
        if (p[i] == k)
            return i;
    }
    return -1;
}

int Boyer_Moore_Horspool(char t[], char p[])
{
    int dem = 0;
    int i = strlen(p), v = i = strlen(p);
    int len = strlen(t);
    while (i < len)
    {
        int x = v - 1;
        int j = i - 1;
        while (t[j] == p[x] && x > -1)
        {
            x--;
            j--;
        }
        if (x < 0)
        {
            dem++;
            i = i + v;
        }
        else
        {
            x = char_in_string(t[j], p);
            if (x < 0)
                i = i + v;
            else
                i = i + v - x - 1;
        }
    }
    return dem;
}

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

int main(int argc, char const *argv[])
{
    Class d[7] = {
        Class("IT01", 20, 12),
        Class("IT02", 18, 8),
        Class("KTPM03", 16, 6),
        Class("KHMT04", 14, 5),
        Class("MKT05", 12, 8),
        Class("IT06", 10, 6),
        Class("MKT07", 8, 7)};
    int m = 7;
    int n = 39;
    int *S = new int[m];
    // cout << "Can lay it nhat " << greedy(d, m, n, S) << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     if (S[i] == 1)
    //     {
    //         cout << d[i].getMaLop() << ": " << d[i].getSiSo() << endl;
    //     }
    // }
    // int k = 20;
    // qhd(d, k, m);
    // result(d, k, m);
    char p[] = "IT";
    // for (int i = 0; i < 7; i++)
    // {
    //     if (Boyer_Moore_Horspool(const_cast<char *>(d[i].getMaLop().c_str()), p) > 0)
    //     {
    //         cout << d[i].getMaLop() << endl;
    //     }
    // }
    for (int i = 0; i < 7; i++)
    {
        if (zAlgorithm(d[i].getMaLop(), p))
        {
            cout << d[i].getMaLop() << endl;
        }
    }
}
