#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Initialize an English text, no more than 50 words.
    string text = "The child is playing with the other children.";
    string substring = "child";
    string replacement = "children";
    int substring_length = substring.length();
    int replacement_length = replacement.length();
    for (int i = 0; i < text.length(); i++)
    {
        if (text.substr(i, substring_length) == substring)
        {
            if ((i == 0 || !isalpha(text[i - 1])) && (i + substring_length == text.length() || !isalpha(text[i + substring_length])))
            {
                text.replace(i, substring_length, replacement);
                i += replacement_length - 1;
            }
        }
    }
    cout << text;
    return 0;
}
