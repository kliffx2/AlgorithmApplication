#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n = 5; // Số lượng xâu ký tự trong danh sách d
string d[5] = {
    "This is the first sentence child.",
    "And this is the second one child.",
    "Here comes the third sentence child.",
    "The fourth sentence is here child.",
    "Finally, the fifth sentence child."};

int boyerMooreHorspool(const string &T, const string &P)
{
    int n = T.length();
    int m = P.length();

    if (m > n)
        return -1;

    int badShift[256];
    memset(badShift, m, sizeof(badShift));

    for (int i = 0; i < m - 1; i++)
        badShift[P[i]] = m - 1 - i;

    int i = 0;
    while (i <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && P[j] == T[i + j])
            j--;

        if (j < 0)
            return i;

        i += badShift[T[i + m - 1]];
    }

    return -1;
}

// Thuật toán Z để kiểm tra xâu P có xuất hiện trong xâu T hay không
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

string greedyString(int k, string d[], int n)
{
    string result;
    int remaining = k;

    while (remaining > 0)
    {
        int longestMatch = 0;
        string longestString;

        for (int i = 0; i < n; i++)
        {
            if (d[i].length() > longestMatch)
            {
                longestMatch = d[i].length();
                longestString = d[i];
            }
        }

        if (longestMatch <= remaining)
        {
            result += longestString;
            remaining -= longestMatch;
        }
        else
        {
            result += longestString.substr(0, remaining);
            remaining = 0;
        }

        // Loại bỏ xâu đã được sử dụng khỏi danh sách
        for (int i = 0; i < n; i++)
        {
            if (d[i].find(longestString) != string::npos)
            {
                d[i] = d[i].substr(d[i].find(longestString) + longestString.length());
            }
        }
    }

    return result;
}

int countOccurrences(const string &word, string d[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (boyerMooreHorspool(d[i], word) != -1)
        {
            count++;
            cout << "Xuat hien tu 'child' trong xau " << i + 1 << ": " << d[i] << endl;
        }
    }

    return count;
}

void findSubstring(const string &substr, string d[], int n)
{
    cout << "Xau con d[0] trong cac xau:" << endl;

    for (int i = 1; i < n; i++)
    {
        if (zAlgorithm(d[i], d[0]))
        {
            int count = 0;
            size_t pos = d[i].find(d[0]);
            while (pos != string::npos)
            {
                count++;
                pos = d[i].find(d[0], pos + 1);
            }

            cout << "Xau " << i + 1 << ": " << d[i] << ", so lan xuat hien: " << count << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    int k = 20;

    string greedy = greedyString(k, d, n);
    cout << "Xau ky tu moi co chieu dai " << k << ": " << greedy << endl;

    string word = "child";
    int occurrenceCount = countOccurrences(word, d, n);
    cout << "So lan tu 'child' xuat hien: " << occurrenceCount << endl;

    findSubstring(d[0], d, n);

    return 0;
    return 0;
}
