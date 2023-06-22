#include <iostream>
#include <string>

using namespace std;

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

int main()
{
    char p[] = "";
    string s = "kliffx2";
    if (Boyer_Moore_Horspool(const_cast<char *>(s.c_str()), p) > 0)
    {
        cout << endl;
    }
}
