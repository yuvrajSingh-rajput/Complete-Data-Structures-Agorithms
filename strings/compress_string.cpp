#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string getCompressedString(string &input)
{
    string result = "";
    int start = 0, count = 0;
    for (int i = start + 1; i < input.length(); i++) // Fix loop condition
    {
        if (input[start] == input[i])
        {
            count++;
        }
        else
        {
            result.push_back(input[start]);
            if (count > 0)
            {
                char ch = count + '1'; // Fix count calculation
                result.push_back(ch);
            }
            count = 0;
            start = i;
        }
    }
    result.push_back(input[start]); // Handle the last character
    if (count > 0)
    {
        char ch = count + '1';
        result.push_back(ch);
    }
    return result;
}

int main()
{
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}