#include <iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
//字节
typedef unsigned char byte;
//字
class Word {
public:
	byte word[4];
};
//S盒
const byte SBox[16][16] = {
	{0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
	{0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
	{0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
	{0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
	{0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
	{0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
	{0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
	{0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
	{0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
	{0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
	{0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
	{0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08},
	{0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
	{0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
	{0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
	{0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}
};
//MixColumn中的矩阵
const byte mixColumnMatrix[4][4] = {
	{0x02, 0x03, 0x01, 0x01},
	{0x01, 0x02, 0x03, 0x01},
	{0x01, 0x01, 0x02, 0x03},
	{0x03, 0x01, 0x01, 0x02}
};
//SubBytes函数
void SubBytes(Word State[4]) {
	for (int i = 0; i <= 15; i++) {
		int X = (State[i / 4].word[i % 4]) / 16;
		int Y = (State[i / 4].word[i % 4]) % 16;
		State[i / 4].word[i % 4] = SBox[X][Y];
	}
}
//SubWord函数
void SubWord(Word& temp) {
	for (int i = 0; i <= 3; i++) {
		int X = (temp.word[i]) / 16;
		int Y = (temp.word[i]) % 16;
		temp.word[i] = SBox[X][Y];
	}
}
//KeyExpansion函数
void KeyExpansion(byte key[16], Word RoundKey[11][4]) {
	//RCon
	Word RCon[10];
	for (int i = 0; i <= 9; i++) {
		for (int j = 1; j <= 3; j++) {
			RCon[i].word[j] = 0x0;
		}
	}
	RCon[0].word[0] = 0x01;
	RCon[1].word[0] = 0x02;
	RCon[2].word[0] = 0x04;
	RCon[3].word[0] = 0x08;
	RCon[4].word[0] = 0x10;
	RCon[5].word[0] = 0x20;
	RCon[6].word[0] = 0x40;
	RCon[7].word[0] = 0x80;
	RCon[8].word[0] = 0x1B;
	RCon[9].word[0] = 0x36;
	//生成轮密钥
	Word w[44];
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			w[i].word[j] = key[4 * i + j];
		}
	}
	for (int i = 4; i <= 43; i++) {
		Word temp = w[i - 1];
		if (i % 4 == 0) {
			//RotWord
			byte tmp = temp.word[0];
			for (int j = 0; j <= 3; j++) {
				temp.word[j] = temp.word[j + 1];
				if (j == 3) {
					temp.word[j] = tmp;
				}
			}
			//SubWord
			SubWord(temp);
			//与RCon[i/4]异或
			for (int j = 0; j <= 3; j++) {
				temp.word[j] = temp.word[j] ^ RCon[(i / 4) - 1].word[j];
			}
		}
		///////////////////////////////
		for (int j = 0; j <= 3; j++) {
			w[i].word[j] = w[i - 4].word[j] ^ temp.word[j];
		}
	}
	//将w赋值给轮密钥
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 3; j++) {
			for (int k = 0; k <= 3; k++) {
				RoundKey[i][j].word[k] = w[i * 4 + j].word[k];
			}
		}
	}
}
//AddRoundKey函数
void AddRoundKey(Word State[4], Word RoundKey[4]) {
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			State[j].word[i] ^= RoundKey[i].word[j];
		}
	}
}
//ShiftRows函数
void ShiftRows(Word State[4]) {
	Word tmp[4];
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			tmp[i].word[j] = State[i].word[j];
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 0, k = 1; k <= 4; j++, k++) {
			State[i].word[j] = tmp[i].word[(i + j) % 4];
		}
	}
}
//域上的多项式乘法
byte XTIME(byte x) {
	return ((x << 1) ^ ((x & 0x80) ? 0x1b : 0x00));
}
byte multiply(byte a, byte b) {
	byte temp[8] = { a };
	byte tempmultiply = 0x00;
	int i = 0;
	for (i = 1; i < 8; i++) {
		temp[i] = XTIME(temp[i - 1]);
	}
	tempmultiply = (b & 0x01) * a;
	for (i = 1; i <= 7; i++) {
		tempmultiply ^= (((b >> i) & 0x01) * temp[i]);
	}
	return tempmultiply;
}
//MixColumns函数
void MixColumns(Word State[4]) {
	Word result[4];
	int i, j, k;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			bool first = true;
			for (k = 0; k < 4; k++) {
				if (first) {
					result[i].word[j] = multiply(mixColumnMatrix[i][k], State[k].word[j]);
					first = false;
				}
				else {
					result[i].word[j] ^= multiply(mixColumnMatrix[i][k], State[k].word[j]);
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			State[i].word[j] = result[i].word[j];
		}
	}
}
//将32个16进制数转换成16个字节的函数
void transform(char* x, byte* plaintext) {
	int power = 1;
	byte sum = 0;
	for (int i = 0; i <= 31; i++) {
		if (x[i] >= 'a' && x[i] <= 'f') {
			sum += (x[i] - 87) * pow(16, power);
			power -= 1;
		}
		if (x[i] >= '0' && x[i] <= '9') {
			sum += (x[i] - 48) * pow(16, power);
			power -= 1;
		}
		if ((i + 1) % 2 == 0) {
			plaintext[i / 2] = sum;
			power = 1;
			sum = 0;
		}
	}
}
int main() {
	//轮数
	const int Nr = 10;
	//密钥
	char* k = new char[33];
	cin >> k;
	//明文
	char* x = new char[33];
	cin >> x;
	//将明文和密钥转换成字节存储
	byte plaintext[16];
	byte key[16];
	transform(x, plaintext);
	transform(k, key);
	//密钥编排
	Word RoundKey[11][4];//有11个轮密钥，每个轮密钥由4个字组成
	KeyExpansion(key, RoundKey);
	//将状态初始化为明文
	Word State[4];
	for (int i = 0; i <= 15; i++) {
		State[i % 4].word[i / 4] = plaintext[i];
	}
	//AddRoundKey操作
	AddRoundKey(State, RoundKey[0]);
	//
	for (int i = 0; i <= Nr - 2; i++) {
		SubBytes(State);
		ShiftRows(State);
		MixColumns(State);
		AddRoundKey(State, RoundKey[i + 1]);
	}
	SubBytes(State);
	ShiftRows(State);
	AddRoundKey(State, RoundKey[10]);
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (State[j].word[i] <= 0x0f) {
				printf("%X", 0);
				printf("%X", State[j].word[i]);
			}
			else {
				printf("%X", State[j].word[i]);
			}
		}
	}
	return 0;
}