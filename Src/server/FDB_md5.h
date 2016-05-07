// md5.h

#ifndef _MD5_H
#define _MD5_H
 
#include <cstring>
#include <iostream> 
 
class MD5
{
public:
	typedef unsigned int size_type; 
 
	MD5();
	MD5(const std::string& text);
	void update(const unsigned char *buf, size_type length);
	void update(const char *buf, size_type length);
	MD5& finalize();
	std::string hexdigest() const;
	friend std::ostream& operator<<(std::ostream&, MD5 md5);
 
private:
	void init();
	typedef unsigned char uint1; /*  8bit 1个字节*/
	typedef unsigned int uint4;  /*  32bit 4 个字节 */
	enum {blocksize = 64}; 
 
	void transform(const uint1 block[blocksize]);
	void decode(uint4 output[], const uint1 input[], size_type len);
	void encode(uint1 output[], const uint4 input[], size_type len);
 
	bool finalized;
	uint1 buffer[blocksize];  
	uint4 count[2];           /*64位的高低位计数器*/
	uint4 state[4];           /*md5计算后尚未转换为字符的md5值*/
	uint1 digest[16];         /*结果*/
 
	/*底层逻辑运算*/
	inline uint4 F(uint4 x, uint4 y, uint4 z);
	inline uint4 G(uint4 x, uint4 y, uint4 z);
	inline uint4 H(uint4 x, uint4 y, uint4 z);
	inline uint4 I(uint4 x, uint4 y, uint4 z);
	inline uint4 rotate_left(uint4 x, int n);
	inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
	inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
	inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
	inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
};
 
std::string md5(const std::string str);
 
#endif
