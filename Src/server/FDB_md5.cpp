/*************************************************************************
	> File Name: md5.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年05月01日 星期日 17时03分00秒
 ************************************************************************/

#include<iostream>
#include <cstdio> 
#include "FDB_md5.h"

using namespace std;
// Constants for MD5Transform routine.
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21
 
/* F, G, H ,I分别表示1，2，3，4 轮循环用到的非线性函数*/
inline MD5::uint4 MD5::F(uint4 x, uint4 y, uint4 z) { return x&y | ~x&z; } 
inline MD5::uint4 MD5::G(uint4 x, uint4 y, uint4 z) { return x&z | y&~z; } 
inline MD5::uint4 MD5::H(uint4 x, uint4 y, uint4 z) { return x^y^z; } 
inline MD5::uint4 MD5::I(uint4 x, uint4 y, uint4 z) { return y ^ (x | ~z); }
 
/*循环左移位*/
inline MD5::uint4 MD5::rotate_left(uint4 x, int n) {
	return (x << n) | (x >> (32-n));
}
 
/* 四轮主循环函数 FF, GG, HH, II*/
inline void MD5::FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
	a = rotate_left(a + F(b,c,d) + x + ac, s) + b;
}
 
inline void MD5::GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
	a = rotate_left(a + G(b,c,d) + x + ac, s) + b;
}
 
inline void MD5::HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
	a = rotate_left(a + H(b,c,d) + x + ac, s) + b;
}
 
inline void MD5::II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
	a = rotate_left(a + I(b,c,d) + x + ac, s) + b;
}
 
/*构造函数*/
MD5::MD5()
{
	init();
}
 
/*构造函数*/
MD5::MD5(const std::string &text)
{
	init();
	update(text.c_str(), text.length());
	finalize();
}

void MD5::init()
{
	finalized=false;
 
	count[0] = 0;
	count[1] = 0;
 
	/*主循环的初始值*/
	state[0] = 0x67452301;
	state[1] = 0xefcdab89;
	state[2] = 0x98badcfe;
	state[3] = 0x10325476;
}

/*
 * output[]里面的一个整数大小的空间存储四个字节
 * 将char[]类型的input里面的所有数据存入int[]类型的output里面
 *
*/
void MD5::decode(uint4 output[], const uint1 input[], size_type len)
{
	for (unsigned int i = 0, j = 0; j < len; i++, j += 4)
	    output[i] = ((uint4)input[j]) | (((uint4)input[j+1]) << 8) |
		(((uint4)input[j+2]) << 16) | (((uint4)input[j+3]) << 24);
}
 
 /* 将int[]类型的input里面的所有数据存入char[]类型的output里面*/
 /*假定长度是四的倍数*/
void MD5::encode(uint1 output[], const uint4 input[], size_type len)
{
	for (size_type i = 0, j = 0; j < len; i++, j += 4) {
	    output[j] = input[i] & 0xff;
	    output[j+1] = (input[i] >> 8) & 0xff;
	    output[j+2] = (input[i] >> 16) & 0xff;
	    output[j+3] = (input[i] >> 24) & 0xff;
    }
}
 
/*使用md5算法的地方*/
void MD5::transform(const uint1 block[blocksize])
{
	uint4 a = state[0], b = state[1], c = state[2], d = state[3], x[16];

    /*md5 以512位 为一个分组来处理输入的信息*/
	decode (x, block, blocksize);           /*用x存储16个32位的子分组即用x存储一个512位的分组*/
 
	/* 第一轮循环 */
	FF (a, b, c, d, x[ 0], S11, 0xd76aa478); /* 1 */
	FF (d, a, b, c, x[ 1], S12, 0xe8c7b756); /* 2 */
	FF (c, d, a, b, x[ 2], S13, 0x242070db); /* 3 */
	FF (b, c, d, a, x[ 3], S14, 0xc1bdceee); /* 4 */
	FF (a, b, c, d, x[ 4], S11, 0xf57c0faf); /* 5 */
	FF (d, a, b, c, x[ 5], S12, 0x4787c62a); /* 6 */
	FF (c, d, a, b, x[ 6], S13, 0xa8304613); /* 7 */
	FF (b, c, d, a, x[ 7], S14, 0xfd469501); /* 8 */
	FF (a, b, c, d, x[ 8], S11, 0x698098d8); /* 9 */
	FF (d, a, b, c, x[ 9], S12, 0x8b44f7af); /* 10 */
	FF (c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
	FF (b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
	FF (a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
	FF (d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
	FF (c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
	FF (b, c, d, a, x[15], S14, 0x49b40821); /* 16 */
 
	/* 第二轮循环 */
	GG (a, b, c, d, x[ 1], S21, 0xf61e2562); /* 17 */
	GG (d, a, b, c, x[ 6], S22, 0xc040b340); /* 18 */
	GG (c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
	GG (b, c, d, a, x[ 0], S24, 0xe9b6c7aa); /* 20 */
	GG (a, b, c, d, x[ 5], S21, 0xd62f105d); /* 21 */
	GG (d, a, b, c, x[10], S22,  0x2441453); /* 22 */
	GG (c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
	GG (b, c, d, a, x[ 4], S24, 0xe7d3fbc8); /* 24 */
	GG (a, b, c, d, x[ 9], S21, 0x21e1cde6); /* 25 */
	GG (d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
	GG (c, d, a, b, x[ 3], S23, 0xf4d50d87); /* 27 */
	GG (b, c, d, a, x[ 8], S24, 0x455a14ed); /* 28 */
	GG (a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
	GG (d, a, b, c, x[ 2], S22, 0xfcefa3f8); /* 30 */
	GG (c, d, a, b, x[ 7], S23, 0x676f02d9); /* 31 */
	GG (b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */
 
	/* 第三轮循环*/
	HH (a, b, c, d, x[ 5], S31, 0xfffa3942); /* 33 */
	HH (d, a, b, c, x[ 8], S32, 0x8771f681); /* 34 */
	HH (c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
	HH (b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
	HH (a, b, c, d, x[ 1], S31, 0xa4beea44); /* 37 */
	HH (d, a, b, c, x[ 4], S32, 0x4bdecfa9); /* 38 */
	HH (c, d, a, b, x[ 7], S33, 0xf6bb4b60); /* 39 */
	HH (b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
	HH (a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
	HH (d, a, b, c, x[ 0], S32, 0xeaa127fa); /* 42 */
	HH (c, d, a, b, x[ 3], S33, 0xd4ef3085); /* 43 */
	HH (b, c, d, a, x[ 6], S34,  0x4881d05); /* 44 */
	HH (a, b, c, d, x[ 9], S31, 0xd9d4d039); /* 45 */
	HH (d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
	HH (c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
	HH (b, c, d, a, x[ 2], S34, 0xc4ac5665); /* 48 */
 
	/* 第四轮循环 */
	II (a, b, c, d, x[ 0], S41, 0xf4292244); /* 49 */
	II (d, a, b, c, x[ 7], S42, 0x432aff97); /* 50 */
	II (c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
	II (b, c, d, a, x[ 5], S44, 0xfc93a039); /* 52 */
	II (a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
	II (d, a, b, c, x[ 3], S42, 0x8f0ccc92); /* 54 */
	II (c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
	II (b, c, d, a, x[ 1], S44, 0x85845dd1); /* 56 */
	II (a, b, c, d, x[ 8], S41, 0x6fa87e4f); /* 57 */
	II (d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
	II (c, d, a, b, x[ 6], S43, 0xa3014314); /* 59 */
	II (b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
	II (a, b, c, d, x[ 4], S41, 0xf7537e82); /* 61 */
	II (d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
	II (c, d, a, b, x[ 2], S43, 0x2ad7d2bb); /* 63 */
	II (b, c, d, a, x[ 9], S44, 0xeb86d391); /* 64 */
 
	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
 
	/*清零信息*/
	memset(x, 0, sizeof x);
}
 
void MD5::update(const unsigned char input[], size_type length)
{
	/*计算已有的信息字节数模64后的值*/
	size_type index = count[0] / 8 % blocksize;
 
	/*更新高低位,每次都要加上新增加的信息长度*/
	if ((count[0] += (length << 3)) < (length << 3))
		count[1]++;
	count[1] += (length >> 29);
 
	/*与512位的整数倍所相差的字节数*/
	size_type firstpart = 64 - index;
 
	size_type i;
 
	/* 当信息达到512位的整数倍时就可以运用md5算法了*/
	if (length >= firstpart)
	{
		memcpy(&buffer[index], input, firstpart);
		transform(buffer);
 
		for (i = firstpart; i + blocksize <= length; i += blocksize)
			transform(&input[i]);
 
		index = 0;
	}
	else
		i = 0;
 
	memcpy(&buffer[index], &input[i], length-i);
}

/*为了方便提供一个符号文本*/
void MD5::update(const char input[], size_type length)
{

	update((const unsigned char*)input, length);
}

MD5& MD5::finalize()
{
	unsigned char padding[64] = {
		0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
	if (!finalized) {

		unsigned char bits[8];
		encode(bits, count, 8);       /*把count数组的8个字节数按位存入bits里bits里面*/
 
		size_type index = count[0] / 8 % 64;
		size_type padLen = (index < 56) ? (56 - index) : (120 - index);
		update(padding, padLen);     /*对信息填充，使其位长对512求余的结果是448*/
 
		/*增加信息长度使之为512位的整数倍*/
		update(bits, 8);
 
        encode(digest, state, 16);   /*将state中的int型数按位放到char型数组digest里面用于级联整合*/
 
		/*清零*/
		memset(buffer, 0, sizeof buffer);
		memset(count, 0, sizeof count);
 
		finalized=true;
	}
 
	return *this;
}

//以string的形式返回级联后的16进制最终结果数
std::string MD5::hexdigest() const
{
	if (!finalized) return "";
 
	char buf[33];
	for (int i=0; i<16; i++)
		sprintf(buf+i*2, "%02x", digest[i]);
	buf[32]=0;
 
	return std::string(buf);
}

/*重载输出运算符*/
std::ostream& operator<<(std::ostream& out, MD5 md5)
{
	return out << md5.hexdigest();
} 

