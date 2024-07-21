#include<iostream>
#include<cstring>
#include<iomanip>
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
//逆S盒
void NS(char A[], int n) {
	if (strcmp(A, B0) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B14[i];
		}
		return;
	}
	if (strcmp(A, B1) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B3[i];
		}
		return;
	}
	if (strcmp(A, B2) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B4[i];
		}
		return;
	}
	if (strcmp(A, B3) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B8[i];
		}
		return;
	}
	if (strcmp(A, B4) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B1[i];
		}
		return;
	}
	if (strcmp(A, B5) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B12[i];
		}
		return;
	}
	if (strcmp(A, B6) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B10[i];
		}
		return;
	}
	if (strcmp(A, B7) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B15[i];
		}
		return;
	}
	if (strcmp(A, B8) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B7[i];
		}
		return;
	}
	if (strcmp(A, B9) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B13[i];
		}
		return;
	}
	if (strcmp(A, B10) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B9[i];
		}
		return;
	}
	if (strcmp(A, B11) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B6[i];
		}
		return;
	}
	if (strcmp(A, B12) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B11[i];
		}
		return;
	}
	if (strcmp(A, B13) == 0) {
		for (int i = 0; i <= n - 1; i++) {
			A[i] = B2[i];
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
			A[i] = B5[i];
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
	//明文
	char** x1 = new char* [3000];
	char** x2 = new char* [3000];
	for (int i = 0; i <= 2999; i++) {
		x1[i] = new char[17];
	}
	for (int i = 0; i <= 2999; i++) {
		x2[i] = new char[17];
	}
	char A[5] = "0000";
	char B[9] = "00000000";
	bool a = false;
	bool b = false;
	for (int i = 0; i <= 2999; i++) {
		//明文前四位
		for (int k = 0; k <= 3; k++) {
			if (a) {
				if (A[k] == '0') {
					A[k] = '1';
					a = false;
				}
				else {
					A[k] = '0';
				}
			}
			x1[i][k] = x2[i][k] = A[k];
		}
		//明文后八位
		for (int k = 0; k <=7; k++) {
			if (b) {
				if (B[k] == '0') {
					B[k] = '1';
					b = false;
				}
				else {
					B[k] = '0';
				}
			}
			x1[i][8 + k] = x2[i][8 + k] = B[k];
		}
		//明文的5-8位
		x1[i][5] = x2[i][5] = '0';
		x1[i][4] = x1[i][6] = x1[i][7] = '1';
		x2[i][4] = x2[i][6] = x2[i][7] = '0';
		x1[i][16] = x2[i][16] = '\0';
		if ((i + 1) % 256 == 0) {
			a = true;
		}
		b = true;
	}
	//密文
	char** y1 = new char* [3000];
	char** y2 = new char* [3000];
	for (int i = 0; i <= 2999; i++) {
		y1[i] = new char[17];
	    y1[i] = SPN(x1[i], 4, 4, 4);
	}
	for (int i = 0; i <= 2999; i++) {
		y2[i] = new char[17];
		y2[i] = SPN(x2[i], 4, 4, 4);
	}
	//密钥
	char** k = new char* [256];
	int count[256];
	for (int i = 0; i <= 255; i++) {
		k[i] = new char[9];
		count[i] = 0;
	}
	for (int i = 0; i <= 7; i++) {
		k[0][i] = '0';
	}
	k[0][8] = '\0';
	for (int i = 1; i <= 255; i++) {
		for (int j = 0; j <= 7; j++) {
				if (k[i-1][j] == '0') {
					k[i][j] = '1';
					k[i][8] = '\0';
					for (j++;;j++) {
						if (j > 7) {
							break;
						}
						k[i][j] = k[i - 1][j];
					}
					break;
				}
				else {
					k[i][j] = '0';
				}
		}
		k[i][8] = '\0';
	}
	///////////////////////////////////////
	for (int i = 0; i <= 2999; i++) {
		bool t = true;
		for (int j = 0,m=8; j <= 3; j++,m++) {
			if (y1[i][j] == y2[i][j] && y1[i][m] == y2[i][m]) {}
			else {
				t = false;
				break;
			}
		}
		
		if (t) {
			for (int j = 0; j <= 255; j++) {
				char v2[2][5];
				char v4[2][5];
				char u2[3][5];
				char u4[3][5];
				for (int m = 4, n = 12, h = 0; h <= 3; m++, n++, h++) {
					if (y1[i][m] == k[j][h]) {
						v2[0][h] = '0';
					}
					else {
						v2[0][h] = '1';
					}
					if (y1[i][n] == k[j][h+4]) {
						v4[0][h] = '0';
					}
					else {
						v4[0][h] = '1';
					}
				}
				v2[0][4] = '\0';
				v4[0][4] = '\0';
				NS(v2[0], 4);
				NS(v4[0], 4);
				for (int n = 0; n <= 3; n++) {
					u2[0][n] = v2[0][n];
					u4[0][n] = v4[0][n];
				}
				u2[0][4] = '\0';
				u4[0][4] = '\0';
				////////////////////////
				for (int m = 4, n = 12, h = 0; h <= 3; m++, n++, h++) {
					if (y2[i][m] == k[j][h]) {
						v2[1][h] = '0';
					}
					else {
						v2[1][h] = '1';
					}
					if (y2[i][n] == k[j][h + 4]) {
						v4[1][h] = '0';
					}
					else {
						v4[1][h] = '1';
					}
				}
				v2[1][4] = '\0';
				v4[1][4] = '\0';
				NS(v2[1], 4);
				NS(v4[1], 4);
				for (int n = 0; n <= 3; n++) {
					u2[1][n] = v2[1][n];
					u4[1][n] = v4[1][n];
				}
				u2[1][4] = '\0';
				u4[1][4] = '\0';
				for (int n = 0; n <= 3; n++) {
					if (u2[0][n] == u2[1][n]) {
						u2[2][n] = '0';
					}
					else {
						u2[2][n] = '1';
					}
					if (u4[0][n] == u4[1][n]) {
						u4[2][n] = '0';
					}
					else {
						u4[2][n] = '1';
					}
				}
				u2[2][4] = '\0';
				u4[2][4] = '\0';
				if (strcmp(u2[2], "0110") == 0 && strcmp(u4[2], "0110") == 0) {
					count[j]++;
				}
			}

		}
		else {
			continue;
		}
	}
	int max = -1;
	int index=0;
	for (int i = 0; i <= 255; i++) {
		if (count[i] > max) {
			max = count[i];
			index = i;
		}
	}
	for (int i = 0; i <= 7; i++) {
		cout << k[index][i];
		if (i == 3) {
			cout << "  ";
		}
	}
	system("pause");
	return 0;
}