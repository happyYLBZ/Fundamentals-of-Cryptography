#include<iostream>
using namespace std;
//求二进制字符串长度
int binary_length(int a) {
	int count = 0;
	while (a) {
		count++;
		a = a >> 1;
	}
	return count;
}
//求逆元
int extended_gcd(int a, int b, int& x, int& y) {
	while (true) {
		if (a < 0) {
			a += b;
		}
		else {
			break;
		}
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
class ECC {
private:
	int a;
	int b;
	int p;
public:
	ECC() {};
	ECC(int a, int b, int p) {
		this->a = a;
		this->b = b;
		this->p = p;
	}
	//判断是否互相为逆元
	bool isInverse(int y1, int y2) {
		y1 = y1 % p;
		y2 = (-y2) % p;
		if (y1 < 0) {
			y1 += p;
		}
		if (y2 < 0) {
			y2 += p;
		}
		return y1 == y2;
	}
	//点加
	void pointadd(int& x1, int& y1, int x2, int y2) {
		int up = y2 - y1;
		int down = x2 - x1;
		int Inverse0 = 0;
		int Inverse1 = 1;
		extended_gcd(down, p, Inverse1, Inverse0);
		int k = (up * Inverse1) % p;
		int x3 = (k * k - x1 - x2) % p;
		int y3 = (k * (x1 - x3) - y1) % p;
		if (x3 < 0) {
			x3 = x3 + p;
		}
		if (y3 < 0) {
			y3 = y3 + p;
		}
		x1 = x3;
		y1 = y3;
		return;
	}
	//倍加
	void doubleadd(int& x, int& y) {
		//求k
		int up = 3 * x * x + a;
		int down = 2 * y;
		int Inverse0 = 0;
		int Inverse1 = 1;
		extended_gcd(down, p, Inverse1, Inverse0);
		int k = (up * Inverse1) % p;
		int x3 = (k * k - x - x) % p;
		int y3 = (k * (x - x3) - y) % p;
		x = x3;
		y = y3;
		if (x3 < 0) {
			x3 = x3 + p;
		}
		if (y3 < 0) {
			y3 = y3 + p;
		}
		return;
	}
	//求点的倍积
	void DoubleAndAdd(int& x, int& y, int n) {
		int x0 = x;
		int y0 = y;
		int len = binary_length(n);
		int* A = new int[len];
		for (int i = len - 1; i >= 0; i--) {
			A[i] = n % 2;
			n = n / 2;
		}
		bool zero = false;
		for (int i = 0; i <= len - 1; i++) {
			if (i == 0) {
				continue;
			}
			if (A[i] == 1) {
				if (isInverse(y, y)) {
					zero = true;
				}
				else {
					if (zero) {

					}
					else {
						doubleadd(x, y);
					}
				}
				if (zero) {
					x = x0;
					y = y0;
					zero = false;
				}
				else {
					if (x == x0 && isInverse(y, y0)) {
						zero = true;
					}
					else {
						pointadd(x, y, x0, y0);
					}
				}
			}
			if (A[i] == 0) {
				if (isInverse(y, y)) {
					zero = true;
				}
				else {
					if (zero) {

					}
					else {
						doubleadd(x, y);
					}
				}
			}
		}
		if (zero) {
			cout << "等于无穷远点" << endl;
			return;
		}
		if (x < 0) {
			x += p;
		}
		if (y < 0) {
			y += p;
		}
	}

};
//快速积取模
unsigned long long Quick_Multiply(unsigned long long a, unsigned long long b, unsigned long long mod) {
	unsigned long long result = 0;
	while (b) {
		if (b & 1) {
			result = (result % mod) + (a % mod);
		}
		a = (a * 2) % mod;
		b >>= 1;
	}
	return result % mod;
}
//快速幂取模
unsigned long long Quick_Power(unsigned long long a, unsigned long long n, unsigned long long mod) {
	unsigned long long result = 1;
	while (n) {
		if (n & 1) {
			result = Quick_Multiply(a, result, mod);//result=(result*a)%mod
		}
		a = Quick_Multiply(a, a, mod);//a=(a*a)%mod
		n >>= 1;
	}
	return result % mod;
}
int main() {
	int q = 13;
	int x0, y0;//椭圆曲线上的点
	int m, x, k;
	cin >> x0 >> y0;
	cin >> m >> x >> k;
	ECC ecc(1, 6, 11);
	ecc.DoubleAndAdd(x0, y0, k);
	int r;
	int s;
	r = x0;
	int Inverse0, Inverse1;
	extended_gcd(k, q, Inverse0, Inverse1);
	s = Inverse0 * (Quick_Power(2, x, q) + m * r);
	s = s % q;
	while (s < 0) {
		s += q;
	}
	while (r < 0) {
		r += q;
	}
	cout << r << " " << s;
	return 0;
}