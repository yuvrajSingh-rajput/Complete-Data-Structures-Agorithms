#include<string>
class Solution {
public:
    string addBinary(string a, string b) {
        int sum = 0, carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int num1 = (i >= 0) ? a[i] - '0' : 0;
            int num2 = (j >= 0) ? b[j] - '0' : 0;

            sum = num1 + num2 + carry;
            carry = sum / 2;
            sum %= 2;

            result = to_string(sum) + result;

            i--;
            j--;
        }

        return result;
    }
};