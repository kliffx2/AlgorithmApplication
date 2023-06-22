#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string &s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

string findLongestPalindrome(const string &s, int k)
{
    int maxLength = 1;
    int start = k;

    // Find the longest palindrome to the left of s[k]
    int left = k - 1;
    int right = k + 1;

    while (left >= 0 && right < s.length())
    {
        if (s[left] != s[right])
        {
            break;
        }

        int currentLength = right - left + 1;
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
            start = left;
        }

        left--;
        right++;
    }

    // Find the longest palindrome to the right of s[k]
    left = k;
    right = k + 1;

    while (left >= 0 && right < s.length())
    {
        if (s[left] != s[right])
        {
            break;
        }

        int currentLength = right - left + 1;
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
            start = left;
        }

        left--;
        right++;
    }

    return s.substr(start, maxLength);
}

int main()
{
    string s = "memoomem";

    if (isPalindrome(s))
    {
        cout << "Xau \"" << s << "\" la mot xau doi xung." << endl;
    }
    else
    {
        int k;
        cout << "Xau \"" << s << "\" khong la mot xau doi xung." << endl;
        cout << "Nhap vao mot so nguyen k: ";
        cin >> k;

        if (k >= 0 && k < s.length())
        {
            string longestPalindrome = findLongestPalindrome(s, k);
            cout << "Xau con doi xung dai nhat co tam la s[" << k << "]: " << longestPalindrome << endl;
        }
        else
        {
            cout << "Gia tri k khong hop le." << endl;
        }
    }

    return 0;
}
