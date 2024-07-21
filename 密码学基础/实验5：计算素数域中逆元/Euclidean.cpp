#include<iostream>
using namespace std;
// 求解 a 和 b 的最大公约数及对应的 x 和 y
int extended_gcd(int a, int b, int& x, int& y) {
    if (a < 0) {
        a += b;
    }
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extended_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main() {
    int a, b, x, y;
    cin >> a >> b;
    extended_gcd(a, b, x, y);
    if (x < 0) {
        cout << x + b;
    }
    else {
        cout << x;
    }
    return 0;
}