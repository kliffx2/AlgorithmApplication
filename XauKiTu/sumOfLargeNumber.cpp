#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string m, string n)
{
    string result = "";
    int carry = 0;
    int i = m.length() - 1;
    int j = n.length() - 1;
    while (i >= 0 || j >= 0 || carry != 0)
    {
        int x = i >= 0 ? m[i] - '0' : 0;
        int y = j >= 0 ? n[j] - '0' : 0;
        int sum = x + y + carry;
        result += to_string(sum % 10);
        carry = sum / 10;
        i--;
        j--;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string m, n;
    cout << "Enter two positive integers: ";
    cin >> m >> n;
    cout << "The sum of " << m << " and " << n << " is: " << add(m, n) << endl;
    return 0;
}
