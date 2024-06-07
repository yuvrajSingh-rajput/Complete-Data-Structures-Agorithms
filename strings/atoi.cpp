#include<iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int start = 0;
        while (start < s.length() && isspace(s[start]))
        {
            start++;
        }

        int sign = 1;
        if (start < s.length() && (s[start] == '+' || s[start] == '-'))
        {
            sign = (s[start] == '-') ? -1 : 1;
            start++; // Increment start to move past the sign character

            // Check if there is another sign character immediately after the first one
            if (start < s.length() && (s[start] == '+' || s[start] == '-'))
            {
                return 0; // Return 0 for invalid input like "+-12" or "--12"
            }
        }

        long long result = 0;
        while (start < s.length() && isdigit(s[start]))
        {
            result = result * 10 + (s[start] - '0');

            if (result * sign < INT_MIN)
            {
                return INT_MIN;
            }
            else if (result * sign > INT_MAX)
            {
                return INT_MAX;
            }

            start++;
        }

        return static_cast<int>(result * sign);
    }
};
