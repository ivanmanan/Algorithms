class Solution {
public:
    bool isUgly(int num) {

        // Divide the number by 2, 3, 5 as many times as possible
        for (int i = 2; i < 6 && num; i++) {
            while (num % i == 0) {
                num /= i;
            }
        }
        return num == 1;
    }
};