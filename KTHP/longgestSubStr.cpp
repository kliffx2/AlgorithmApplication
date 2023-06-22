#include <iostream>
#include <cstring>
using namespace std;

int longestCommonSubstring(const string &a, const string &b)
{
    int m = a.length();
    int n = b.length();
    int maxLength = 0;
    int end = 0;

    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                if (L[i][j] > maxLength)
                {
                    maxLength = L[i][j];
                    end = i - 1;
                }
            }
            else
                L[i][j] = 0;
        }
    }

    if (maxLength == 0)
        return 0;

    string lcs = a.substr(end - maxLength + 1, maxLength);
    cout << "Xau con chung dai nhat: " << lcs << endl;
    return maxLength;
}

int main()
{
    string a = "kakatae shindeiru 200";
    string b = "omae wa moushinde 100";
    int length = longestCommonSubstring(a, b);
    cout << "Do dai xau con chung dai nhat: " << length << endl;
    return 0;
}
