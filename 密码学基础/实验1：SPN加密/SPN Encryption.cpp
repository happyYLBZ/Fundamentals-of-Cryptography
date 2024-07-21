#include<iostream>
#include<cstring>
using namespace std;
//16进制的2进制表示
char B0[5] = "0000";
char B1[5] = "0001";
char B2[5] = "0010";
char B3[5] = "0011";
char B4[5] = "0100";
char B5[5] = "0101";
char B6[5] = "0110";
char B7[5] = "0111";
char B8[5] = "1000";
char B9[5] = "1001";
char B10[5] = "1010";
char B11[5] = "1011";
char B12[5] = "1100";
char B13[5] = "1101";
char B14[5] = "1110";
char B15[5] = "1111";
//S盒
void S(char A[], int n) {
	if (strcmp(A, B0) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B14[i];
		}
		return;
	}
	if (strcmp(A, B1) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B4[i];
		}
		return;
	}
	if (strcmp(A, B2) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B13[i];
		}
		return;
	}
	if (strcmp(A, B3) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B1[i];
		}
		return;
	}
	if (strcmp(A, B4) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B2[i];
		}
		return;
	}
	if (strcmp(A, B5) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B15[i];
		}
		return;
	}
	if (strcmp(A, B6) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B11[i];
		}
		return;
	}
	if (strcmp(A, B7) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B8[i];
		}
		return;
	}
	if (strcmp(A, B8) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B3[i];
		}
		return;
	}
	if (strcmp(A, B9) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B10[i];
		}
		return;
	}
	if (strcmp(A, B10) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B6[i];
		}
		return;
	}
	if (strcmp(A, B11) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B12[i];
		}
		return;
	}
	if (strcmp(A, B12) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B5[i];
		}
		return;
	}
	if (strcmp(A, B13) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B9[i];
		}
		return;
	}
	if (strcmp(A, B14) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B0[i];
		}
		return;
	}
	if (strcmp(A, B15) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B7[i];
		}
		return;
	}
}
//置换
void P(char* A, int n) {
	char* B = new char[n];
	for (int i = 0; i <= n - 1; i++) {
		B[i] = A[i];
	}
	A[0] = B[0];
	A[1] = B[4];
	A[2] = B[8];
	A[3] = B[12];
	A[4] = B[1];
	A[5] = B[5];
	A[6] = B[9];
	A[7] = B[13];
	A[8] = B[2];
	A[9] = B[6];
	A[10] = B[10];
	A[11] = B[14];
	A[12] = B[3];
	A[13] = B[7];
	A[14] = B[11];
	A[15] = B[15];
}
//密钥
char K[][17] = { "0011101010010100","1010100101001101","1001010011010110","0100110101100011","1101011000111111" };
//SPN
char* SPN(char* x, int Nr, int l, int m) {
	//状态
	char** w = new char* [Nr];
	for (int i = 0; i <= Nr - 1; i++) {
		w[i] = new char[l * m + 1];
	}
	//S盒的输入
	char* u = new char[l * m + 1];
	//S盒的输出
	char* v = new char[l * m + 1];
	//初始化状态
	for (int i = 0; i <= l * m - 1; i++) {
		w[0][i] = x[i];
	}
	//Nr-1次循环
	for (int i = 1; i <= Nr - 1; i++) {
		//与轮密钥异或
		for (int j = 0; j <= l * m - 1; j++) {
			if (w[i - 1][j] == K[i - 1][j]) {
				u[j] = '0';
			}
			else {
				u[j] = '1';
			}
		}
		u[l * m] = '\0';
		//m次代换
		int k = 0;
		char* tmp = new char[l + 1];
		for (int j = 0; j <= l * m - 1; ) {
			for (int n = 0; n <= l - 1; n++, j++) {
				tmp[n] = u[j];
			}
			tmp[l] = '\0';
			S(tmp, l);
			for (int n = 0; n <= l - 1; n++, k++) {
				v[k] = tmp[n];
			}
			if (k == l * m) {
				v[k] = '\0';
			}
		}
		//一次置换
		P(v, l * m);
		for (int j = 0; j <= l * m - 1; j++) {
			w[i][j] = v[j];
		}
		w[i][l * m] = '\0';
	}
	//最后一轮
	//与轮密钥异或
	for (int j = 0; j <= l * m - 1; j++) {
		if (w[Nr - 1][j] == K[Nr - 1][j]) {
			u[j] = '0';
		}
		else {
			u[j] = '1';
		}
	}
	u[l * m] = '\0';
	//m次代换
	int k = 0;
	char* tmp = new char[l + 1];
	for (int j = 0; j <= l * m - 1; ) {
		for (int n = 0; n <= l - 1; n++, j++) {
			tmp[n] = u[j];
		}
		tmp[l] = '\0';
		S(tmp, l);
		for (int n = 0; n <= l - 1; n++, k++) {
			v[k] = tmp[n];
		}
		if (k == l * m) {
			v[k] = '/0';
		}
	}
	//最后一次与密钥异或
	char* y = new char[l * m + 1];
	for (int j = 0; j <= l * m - 1; j++) {
		if (v[j] == K[Nr][j]) {
			y[j] = '0';
		}
		else {
			y[j] = '1';
		}
	}
	y[l * m] = '\0';
	return y;
}
int main() {
	char x[18];
	char k[34];
	cin >> x;
	cin >> k;
	int j = 0;
	for (int i = 0; i <= 15; i++, j++) {
		K[0][i] = k[j];
	}
	K[0][16] = '\0';
	j = 4;
	for (int i = 0; i <= 15; i++, j++) {
		K[1][i] = k[j];
	}
	K[1][16] = '\0';
	j = 8;
	for (int i = 0; i <= 15; i++, j++) {
		K[2][i] = k[j];
	}
	K[2][16] = '\0';
	j = 12;
	for (int i = 0; i <= 15; i++, j++) {
		K[3][i] = k[j];
	}
	K[3][16] = '\0';
	j = 16;
	for (int i = 0; i <= 15; i++, j++) {
		K[4][i] = k[j];
	}
	K[4][16] = '\0';
	cout << SPN(x, 4, 4, 4);
	return 0;
}