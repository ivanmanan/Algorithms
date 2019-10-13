class Solution {
public:
    string addBinary(string a, string b) {


        string s = "";

        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry == 1) {

            int a1 = 0;
            int b1 = 0;
            int result = 0;

            // a[] and b[] are still valid
            if (j >= 0 && i >= 0) {

                // convert to int
                a1 = a[i] - '0';
                b1 = b[j] - '0';
                result = a1 + b1 + carry;
            }
            // Only b[] is valid
            else if (j >= 0) {
                result = (b[j] - '0') + carry;
            }
            // Only a[] is valid
            else if (i >= 0) {
                result = (a[i] - '0') + carry;
            }
            else {
                result = carry;
            }

            j--;
            i--;

            if (result == 2) {
                carry = 1;
                result = 0;
            }
            else if (result <= 1) {
                carry = 0;
            }
            else {
                // result == 3
                result = 1;
                carry = 1;
            }

            char res = result + '0';
            s = res + s;

        }

        return s;
    }
};