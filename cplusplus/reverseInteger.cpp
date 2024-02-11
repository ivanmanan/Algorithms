#include <iostream>

using namespace std;

int reverse(int x) {

    int rev = 0;

    while (x != 0) {
        //pop operation:
        int pop = x % 10;
        x /= 10;

        //push operation:
        rev = rev * 10 + pop;
    }
    return rev;

}

int main() {
    int ans = reverse(5124);

    cout << ans << endl; // prints 5215
}