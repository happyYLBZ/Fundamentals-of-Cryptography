#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
/*------------------------Miller-Rabin----------------*/
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
//Miller-Rabin算法
int MillerRabin(unsigned long long n) {
	//随机生成a
	unsigned long long a = (rand() % (n - 1)) + 1;
	//把n-1表示成2^k*m
	unsigned long long m = n - 1;
	int k = 0;
	while (!(m & 1)) {
		m >>= 1;
		k++;
	}
	unsigned long long b = Quick_Power(a, m, n);
	if (b == 1 || b == 1 - n)return 1;
	for (int i = 0; i <= k - 1; i++) {
		if (b == -1 || b == n - 1)return 1;
		b = Quick_Multiply(b, b, n);
	}
	return 0;
}
int main() {
	unsigned long long int n;
	cin >> n;
	int count[2];
	count[0] = 0;
	count[1] = 0;
	srand(time(0));
	for (int i = 1; i <= 5; i++) {
		count[MillerRabin(n)]++;
	}
	//对合数偏是
	if (count[0] == 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}