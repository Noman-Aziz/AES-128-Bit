#include<iostream>
#include<math.h>
using namespace std;

// substitutes a byte
unsigned char substitute(unsigned char byte) {

	static unsigned char sbox[256] = {
	   0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
	   0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
	   0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
	   0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
	   0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
	   0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
	   0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
	   0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
	   0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
	   0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
	   0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
	   0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
	   0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
	   0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
	   0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
	   0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
	};

	return sbox[byte];
}

unsigned char reverse_substitute(unsigned char byte) {
	static unsigned char rsbox[256] = {
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb
	, 0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb
	, 0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e
	, 0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25
	, 0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92
	, 0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84
	, 0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06
	, 0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b
	, 0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73
	, 0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e
	, 0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b
	, 0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4
	, 0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f
	, 0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef
	, 0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61
	, 0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };

	return rsbox[byte];
}

void SubBytes(unsigned char* state) 
{
	for (int i = 0; i < 16; i++)
		state[i] = substitute(state[i]);
}

void rotate_left(unsigned char* byte_array)
{
	unsigned char temp[16];

	temp[0] = byte_array[0];
	temp[1] = byte_array[4];
	temp[2] = byte_array[8];
	temp[3] = byte_array[12];
	temp[4] = byte_array[1];
	temp[5] = byte_array[5];
	temp[6] = byte_array[9];
	temp[7] = byte_array[13];
	temp[8] = byte_array[2];
	temp[9] = byte_array[6];
	temp[10] = byte_array[10];
	temp[11] = byte_array[14];
	temp[12] = byte_array[3];
	temp[13] = byte_array[7];
	temp[14] = byte_array[11];
	temp[15] = byte_array[15];

	for (int i = 0; i < 16; i++)
		byte_array[i] = temp[i];
}

void InvSubBytes(unsigned char* state)
{
	for (int i = 0; i < 16; i++)
		state[i] = reverse_substitute(state[i]);
}

void InvShiftRows(unsigned char* state)
{
	unsigned char swap, swap1;

	//Row2
	swap = state[7];
	for (int i = 7; i > 4; i--)
	{
		state[i] = state[i - 1];
	}
	state[4] = swap;

	//Row3
	swap = state[11];
	swap1 = state[10];
	for ( int i=11 ; i>9 ; i--)
		state[i] = state[i-2];
	state[8] = swap1;
	state[9] = swap;

	//Row4
	swap = state[15];
	state[15] = state[12];
	swap1 = state[14];
	state[14] = swap;
	swap = state[13];
	state[13] = swap1;
	state[12] = swap;
}

void ShiftRows(unsigned char* state) 
{
	unsigned char swap,swap1,swap2;

	//Row2
	swap = state[4];
	for (int i = 4; i < 7; i++)
	{
		state[i] = state[i + 1];
	}
	state[7] = swap;

	//Row3
	swap = state[8];
	swap1 = state[9];
	for (int i = 8; i < 10; i++)
	{
		state[i] = state[i + 2];
	}
	state[10] = swap;
	state[11] = swap1;

	//Row4
	swap = state[12];
	swap1 = state[13];
	swap2 = state[14];
	state[12] = state[15];
	state[13] = swap;
	state[14] = swap1;
	state[15] = swap2;
}

void addRoundKey(unsigned char* state, unsigned char* roundKey)
{
	for (int i = 0; i < 16; i++)
		state[i] ^= roundKey[i];
}

void KeyExpansion(unsigned char* cipherkey, unsigned char* expandedkey)
{
	int start = 16;
	int end = 32;
	int prevstart = 0;
	int prevend = 16;
	int last4 = 0;
	unsigned char temp;

	//TempCol3
	unsigned char gw[4];

	//RoundConstant
	static unsigned char roundconstant[10] = {
	0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1B,0x36
	};

	//Initialzing Key 0
	for (int i = 0; i < 16; i++)
		expandedkey[i] = cipherkey[i];

	//Initializing Other Keys
	for (int i = 0; i < 10; i++)
	{
		last4 = start ;

		//Initializing gw
		for (int j = 4, k = 0;j > 0; j--, k++)
			gw[k] = expandedkey[start - j];

		//Storing Previous Key
		for (int j = start,k=0; j<end ; j++,k++)
			expandedkey[j] = expandedkey[prevstart+k];

		//Circular Left Shift of Column 3
		temp = gw[0];

		for (int j = 0; j < 3; j++)
			gw[j] = gw[j + 1];

		gw[3] = temp;

		//Byte Subsitution From SBox of Column 3
		for (int j = 0; j < 4; j++)
			gw[j] =	substitute(gw[j]);

		//Adding Round Constant
		gw[0] ^= roundconstant[i];

		//XORING COLUMNS WITH PREVIOUS ANSWER
		for (int j = start,	k = 0 ; j < end; j++)
		{
			if (j <= start + 3)
			{
				expandedkey[j] ^= gw[k];
				k++;
			}

			else
			{
				expandedkey[j] ^= expandedkey[last4];
				last4++;
			}
		}

		prevstart = start;
		prevend = end;
		start = end;
		end = start + 16;

	}
}

void MixColumn(unsigned char* state)
{
	/*
	The Matrix Would be
	2 3 1 1
	1 2 3 1
	1 1 2 3
	3 1 1 2
	*/

	//Previous State of Matrix
	unsigned char prevstat[16];
	//This State Contains the Answer of Elements of State Matrix multiplied by 2 
	//x * 3 = (x*2) * 2
	//In case of multiplied by 1, nothing will happen
	unsigned char mul2stat[4];
	//Variable to Check Highest Bit
	unsigned char highestbit;

	//Copying State Matrix into PrevStat Matrix
	for (int i = 0; i < 16; i++)
		prevstat[i] = state[i];

	//Initializing mul2stat matrix for column1
	for (int i = 0,j=0; i < 4; i++)
	{
		//highest bit is equal to 0xff if the msb of state[j] is 1, otherwise its equal to 0
		highestbit = (unsigned char)((signed char)state[j] >> 7);

		mul2stat[i] = state[j] << 1;
		mul2stat[i] ^= 0x1B & highestbit; //0x1B come from Rijndael's Galois field
		j += 4;
	}

	//(a0*2) + (3*a1) + a2 + a3
	state[0] = mul2stat[0] ^ (mul2stat[1] ^ prevstat[4]) ^ prevstat[8] ^ prevstat[12];
	//a0 + (2*a1) + (3*a2) + a3
	state[4] = prevstat[0] ^ mul2stat[1] ^ (mul2stat[2] ^ prevstat[8]) ^ prevstat[12];
	//a0 + a1 + (2*a2) + (3*a3)
	state[8] = prevstat[0] ^ prevstat[4] ^ mul2stat[2] ^ (mul2stat[3] ^ prevstat[12]);
	//(3*a0) + a1 + a2 + (2*a3)
	state[12] = (mul2stat[0] ^ prevstat[0]) ^ prevstat[4] ^ prevstat[8] ^ mul2stat[3];

	//Initializing mul2stat matrix for column2
	for (int i = 0,j=1; i < 4; i++)
	{
		//highest bit is equal to 0xff if the msb of state[j] is 1, otherwise its equal to 0
		highestbit = (unsigned char)((signed char)state[j] >> 7);

		mul2stat[i] = state[j] << 1;
		mul2stat[i] ^= 0x1B & highestbit; //0x1B come from Rijndael's Galois field
		j += 4;
	}

	//(a0*2) + (3*a1) + a2 + a3
	state[1] = mul2stat[0] ^ (mul2stat[1] ^ prevstat[5]) ^ prevstat[9] ^ prevstat[13];
	//a0 + (2*a1) + (3*a2) + a3
	state[5] = prevstat[1] ^ mul2stat[1] ^ (mul2stat[2] ^ prevstat[9]) ^ prevstat[13];
	//a0 + a1 + (2*a2) + (3*a3)
	state[9] = prevstat[1] ^ prevstat[5] ^ mul2stat[2] ^ (mul2stat[3] ^ prevstat[13]);
	//(3*a0) + a1 + a2 + (2*a3)
	state[13] = (mul2stat[0] ^ prevstat[1]) ^ prevstat[5] ^ prevstat[9] ^ mul2stat[3];

	//Initializing mul2stat matrix for column3
	for (int i = 0, j = 2; i < 4; i++)
	{
		//highest bit is equal to 0xff if the msb of state[j] is 1, otherwise its equal to 0
		highestbit = (unsigned char)((signed char)state[j] >> 7);

		mul2stat[i] = state[j] << 1;
		mul2stat[i] ^= 0x1B & highestbit; //0x1B come from Rijndael's Galois field
		j += 4;
	}

	//(a0*2) + (3*a1) + a2 + a3
	state[2] = mul2stat[0] ^ (mul2stat[1] ^ prevstat[6]) ^ prevstat[10] ^ prevstat[14];
	//a0 + (2*a1) + (3*a2) + a3
	state[6] = prevstat[2] ^ mul2stat[1] ^ (mul2stat[2] ^ prevstat[10]) ^ prevstat[14];
	//a0 + a1 + (2*a2) + (3*a3)
	state[10] = prevstat[2] ^ prevstat[6] ^ mul2stat[2] ^ (mul2stat[3] ^ prevstat[14]);
	//(3*a0) + a1 + a2 + (2*a3)
	state[14] = (mul2stat[0] ^ prevstat[2]) ^ prevstat[6] ^ prevstat[10] ^ mul2stat[3];

	//Initializing mul2stat matrix for column4
	for (int i = 0, j = 3; i < 4; i++)
	{
		//highest bit is equal to 0xff if the msb of state[j] is 1, otherwise its equal to 0
		highestbit = (unsigned char)((signed char)state[j] >> 7);

		mul2stat[i] = state[j] << 1;
		mul2stat[i] ^= 0x1B & highestbit; //0x1B come from Rijndael's Galois field
		j += 4;
	}

	//(a0*2) + (3*a1) + a2 + a3
	state[3] = mul2stat[0] ^ (mul2stat[1] ^ prevstat[7]) ^ prevstat[11] ^ prevstat[15];
	//a0 + (2*a1) + (3*a2) + a3
	state[7] = prevstat[3] ^ mul2stat[1] ^ (mul2stat[2] ^ prevstat[11]) ^ prevstat[15];
	//a0 + a1 + (2*a2) + (3*a3)
	state[11] = prevstat[3] ^ prevstat[7] ^ mul2stat[2] ^ (mul2stat[3] ^ prevstat[15]);
	//(3*a0) + a1 + a2 + (2*a3)
	state[15] = (mul2stat[0] ^ prevstat[3]) ^ prevstat[7] ^ prevstat[11] ^ mul2stat[3];
}

void InvMixColumn(unsigned char* state)
{
	/*
	The Matrix To Multiply Will be
	14 11 13  9
	 9 14 11 13
	13  9 14 11
	11 13  9 14
	*/

	/*
	x*9  = ( ( (x*2) * 2 ) * 2 ) + x
	x*11 = ( ( ( (x*2) * 2 ) + x ) * 2 ) + x
	x*13 = ( ( ( (x*2) + x ) * 2 ) * 2 ) + x
	x*14 = ( ( ( (x*2) + x ) * 2 ) + x ) * 2
	*/

	//Previous State of Matrix
	unsigned char prevstat[16];

	//Variable to Store x*2
	unsigned char mul2stat[4];
	//Variable to Check Highest Bit
	unsigned char highestbit;

	//Copying State Matrix into PrevStat Matrix
	for (int i = 0; i < 16; i++)
		prevstat[i] = state[i];

	//Some Variables
	unsigned char mul9stat;
	unsigned char mul11stat;
	unsigned char mul13stat;
	unsigned char mul14stat;

	//Initializing mul2stat matrix for column1
	for (int i = 0, j = 0; i < 4; i++)
	{
		//highest bit is equal to 0xff if the msb of state[j] is 1, otherwise its equal to 0
		highestbit = (unsigned char)((signed char)state[j] >> 7);

		mul2stat[i] = state[j] << 1;
		mul2stat[i] ^= 0x1B & highestbit; //0x1B come from Rijndael's Galois field
		j += 4;
	}

	//(a0*14) + (a1*11) + (a2*13) +	(a3*9)
	
	/////////////////////////////////////////////
	mul14stat = mul2stat[0];
	mul14stat ^= prevstat[0];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[0];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////
	
	mul11stat = mul2stat[1];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[4];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[4];
	
	/////////////////////////////////////////////
	mul13stat = mul2stat[2];
	mul13stat ^= prevstat[8];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[8];
	//////////////////////////////////////////////

	mul9stat = mul2stat[3];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[12];

	//////////////////////////////////////////////
	
	state[0] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*9) + (a1*14) + (a2*11) +	(a3*13)
	
	/////////////////////////////////////////////
	mul9stat = mul2stat[0];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[0];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[1];
	mul14stat ^= prevstat[4];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[4];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul11stat = mul2stat[2];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[8];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[8];
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul13stat = mul2stat[3];
	mul13stat ^= prevstat[12];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[12];
	//////////////////////////////////////////////

	state[4] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*13) + (a1*9) + (a2*14) +	(a3*11)

	/////////////////////////////////////////////
	mul13stat = mul2stat[0];
	mul13stat ^= prevstat[0];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[0];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul9stat = mul2stat[1];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[4];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[2];
	mul14stat ^= prevstat[8];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[8];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul11stat = mul2stat[3];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[12];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[12];
	/////////////////////////////////////////////

	state[8] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*11) + (a1*13) + (a2*9) +	(a3*14)

	/////////////////////////////////////////////
	mul11stat = mul2stat[0];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[0];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[0];
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul13stat = mul2stat[1];
	mul13stat ^= prevstat[4];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[4];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul9stat = mul2stat[2];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[8];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[3];
	mul14stat ^= prevstat[12];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[12];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	state[12] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//Initializing mul2stat matrix for column2
	for (int i = 0, j = 1; i < 4; i++)
	{
		//highest bit is equal to 0xff if the msb of state[j] is 1, otherwise its equal to 0
		highestbit = (unsigned char)((signed char)state[j] >> 7);

		mul2stat[i] = state[j] << 1;
		mul2stat[i] ^= 0x1B & highestbit; //0x1B come from Rijndael's Galois field
		j += 4;
	}

	//(a0*14) + (a1*11) + (a2*13) +	(a3*9)

	/////////////////////////////////////////////
	mul14stat = mul2stat[0];
	mul14stat ^= prevstat[1];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[1];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	mul11stat = mul2stat[1];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[5];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[5];

	/////////////////////////////////////////////
	mul13stat = mul2stat[2];
	mul13stat ^= prevstat[9];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[9];
	//////////////////////////////////////////////

	mul9stat = mul2stat[3];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[13];

	//////////////////////////////////////////////

	state[1] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*9) + (a1*14) + (a2*11) +	(a3*13)

	/////////////////////////////////////////////
	mul9stat = mul2stat[0];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[1];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[1];
	mul14stat ^= prevstat[5];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[5];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul11stat = mul2stat[2];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[9];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[9];
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul13stat = mul2stat[3];
	mul13stat ^= prevstat[13];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[13];
	//////////////////////////////////////////////

	state[5] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*13) + (a1*9) + (a2*14) +	(a3*11)

	/////////////////////////////////////////////
	mul13stat = mul2stat[0];
	mul13stat ^= prevstat[1];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[1];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul9stat = mul2stat[1];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[5];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[2];
	mul14stat ^= prevstat[9];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[9];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul11stat = mul2stat[3];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[13];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[13];
	/////////////////////////////////////////////

	state[9] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*11) + (a1*13) + (a2*9) +	(a3*14)

	/////////////////////////////////////////////
	mul11stat = mul2stat[0];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[1];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[1];
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul13stat = mul2stat[1];
	mul13stat ^= prevstat[5];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[5];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul9stat = mul2stat[2];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[9];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[3];
	mul14stat ^= prevstat[13];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[13];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	state[13] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//Initializing mul2stat matrix for column3
	for (int i = 0, j = 2; i < 4; i++)
	{
		//highest bit is equal to 0xff if the msb of state[j] is 1, otherwise its equal to 0
		highestbit = (unsigned char)((signed char)state[j] >> 7);

		mul2stat[i] = state[j] << 1;
		mul2stat[i] ^= 0x1B & highestbit; //0x1B come from Rijndael's Galois field
		j += 4;
	}

	//(a0*14) + (a1*11) + (a2*13) +	(a3*9)

	/////////////////////////////////////////////
	mul14stat = mul2stat[0];
	mul14stat ^= prevstat[2];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[2];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	mul11stat = mul2stat[1];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[6];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[6];

	/////////////////////////////////////////////
	mul13stat = mul2stat[2];
	mul13stat ^= prevstat[10];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[10];
	//////////////////////////////////////////////

	mul9stat = mul2stat[3];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[14];

	//////////////////////////////////////////////

	state[2] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*9) + (a1*14) + (a2*11) +	(a3*13)

	/////////////////////////////////////////////
	mul9stat = mul2stat[0];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[2];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[1];
	mul14stat ^= prevstat[6];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[6];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul11stat = mul2stat[2];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[10];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[10];
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul13stat = mul2stat[3];
	mul13stat ^= prevstat[14];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[14];
	//////////////////////////////////////////////

	state[6] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*13) + (a1*9) + (a2*14) +	(a3*11)

	/////////////////////////////////////////////
	mul13stat = mul2stat[0];
	mul13stat ^= prevstat[2];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[2];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul9stat = mul2stat[1];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[6];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[2];
	mul14stat ^= prevstat[10];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[10];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul11stat = mul2stat[3];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[14];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[14];
	/////////////////////////////////////////////

	state[10] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*11) + (a1*13) + (a2*9) +	(a3*14)

	/////////////////////////////////////////////
	mul11stat = mul2stat[0];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[2];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[2];
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul13stat = mul2stat[1];
	mul13stat ^= prevstat[6];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[6];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul9stat = mul2stat[2];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[10];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[3];
	mul14stat ^= prevstat[14];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[14];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	state[14] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//Initializing mul2stat matrix for column4
	for (int i = 0, j = 3; i < 4; i++)
	{
		//highest bit is equal to 0xff if the msb of state[j] is 1, otherwise its equal to 0
		highestbit = (unsigned char)((signed char)state[j] >> 7);

		mul2stat[i] = state[j] << 1;
		mul2stat[i] ^= 0x1B & highestbit; //0x1B come from Rijndael's Galois field
		j += 4;
	}

	//(a0*14) + (a1*11) + (a2*13) +	(a3*9)

/////////////////////////////////////////////
	mul14stat = mul2stat[0];
	mul14stat ^= prevstat[3];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[3];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	mul11stat = mul2stat[1];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[7];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[7];

	/////////////////////////////////////////////
	mul13stat = mul2stat[2];
	mul13stat ^= prevstat[11];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[11];
	//////////////////////////////////////////////

	mul9stat = mul2stat[3];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[15];

	//////////////////////////////////////////////

	state[3] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*9) + (a1*14) + (a2*11) +	(a3*13)

	/////////////////////////////////////////////
	mul9stat = mul2stat[0];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[3];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[1];
	mul14stat ^= prevstat[7];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[7];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul11stat = mul2stat[2];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[11];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[11];
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul13stat = mul2stat[3];
	mul13stat ^= prevstat[15];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[15];
	//////////////////////////////////////////////

	state[7] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*13) + (a1*9) + (a2*14) +	(a3*11)

	/////////////////////////////////////////////
	mul13stat = mul2stat[0];
	mul13stat ^= prevstat[3];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[3];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul9stat = mul2stat[1];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[7];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[2];
	mul14stat ^= prevstat[11];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[11];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul11stat = mul2stat[3];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[15];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[15];
	/////////////////////////////////////////////

	state[11] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;

	//(a0*11) + (a1*13) + (a2*9) +	(a3*14)

	/////////////////////////////////////////////
	mul11stat = mul2stat[0];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[3];

	highestbit = (unsigned char)((signed char)mul11stat >> 7);
	mul11stat = mul11stat << 1;
	mul11stat ^= 0x1B & highestbit;

	mul11stat ^= prevstat[3];
	/////////////////////////////////////////////

	/////////////////////////////////////////////
	mul13stat = mul2stat[1];
	mul13stat ^= prevstat[7];

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul13stat >> 7);
	mul13stat = mul13stat << 1;
	mul13stat ^= 0x1B & highestbit;

	mul13stat ^= prevstat[7];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul9stat = mul2stat[2];

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	highestbit = (unsigned char)((signed char)mul9stat >> 7);
	mul9stat = mul9stat << 1;
	mul9stat ^= 0x1B & highestbit;

	mul9stat ^= prevstat[11];
	//////////////////////////////////////////////

	/////////////////////////////////////////////
	mul14stat = mul2stat[3];
	mul14stat ^= prevstat[15];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;

	mul14stat ^= prevstat[15];

	highestbit = (unsigned char)((signed char)mul14stat >> 7);
	mul14stat = mul14stat << 1;
	mul14stat ^= 0x1B & highestbit;
	/////////////////////////////////////////////

	state[15] = mul9stat ^ mul11stat ^ mul13stat ^ mul14stat;
}

void Encrypt(unsigned char* plaintext, unsigned char* cipherkey, unsigned char* ciphertext)
{
	//Some Variables
	unsigned char expandedkey[176];
	unsigned char roundkey[16];
	int newkey = 16;

	//Expanding Keys
	KeyExpansion(cipherkey, expandedkey);

	//Copying PlainText to CipherText
	for (int i = 0; i < 16; i++)
		ciphertext[i] = plaintext[i];

	//Adding Round Key 0
	addRoundKey(ciphertext,expandedkey);

	//For Round 1 to 10
	for (int i = 0; i < 10; i++)
	{
		//Substituting Bytes
		SubBytes(ciphertext);

		//Transforming Rows into Columns For Shifting Rows Step
		rotate_left(ciphertext);

		//Shifting Rows
		ShiftRows(ciphertext);

		//Mixing Columns if Not Round 10
		if (i != 9)
			MixColumn(ciphertext);

		//Again Rotating Matrix to Transform to Original Position
		rotate_left(ciphertext);

		//Copying Roundkey for this round
		for (int j = newkey, k = 0; k < 16; j++, k++)
			roundkey[k] = expandedkey[j];

		//Adding Round Key
		addRoundKey(ciphertext, roundkey);

		newkey += 16;
	}

}	

void Decrypt(unsigned char* ciphertext, unsigned char* cipherkey, unsigned char* plaintext)
{
	//Some Variables
	unsigned char expandedkey[176];
	unsigned char roundkey[16];
	int newkey = 160 ;

	//Expanding Keys
	KeyExpansion(cipherkey, expandedkey);

	//Copying Ciphertext to PlainText
	for (int i = 0; i < 16; i++)
		plaintext[i] = ciphertext[i] ;

	//Copying For Round Key 10
	for (int i = newkey, j = 0; i < 176; i++, j++)
		roundkey[j] = expandedkey[i];

	//Adding Round Key 10
	addRoundKey(plaintext, roundkey);

	newkey -= 16;

	//For Round 1 to 10
	for (int i = 0; i < 10; i++)
	{
		//Transforming Rows into Columns For Shifting Rows Step
		rotate_left(plaintext);

		//Inverse Shifting Rows
		InvShiftRows(plaintext);

		//Inverse Substituting Bytes
		InvSubBytes(plaintext);

		//Again Rotating Matrix to Transform to Original Position
		rotate_left(plaintext);

		//Copying Roundkey for this round
		for (int j = newkey, k = 0; k < 16; j++, k++)
			roundkey[k] = expandedkey[j];

		//Adding Round Key
		addRoundKey(plaintext, roundkey);

		//Inverse Mixing Columns if Not Round 10
		if (i != 9)
		{
			rotate_left(plaintext);

			InvMixColumn(plaintext);

			rotate_left(plaintext);
		}

		newkey -= 16;
	}
}