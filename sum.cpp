#include <iostream>
#include <stdint.h>
using namespace std;

uint32_t sum(uint32_t a, uint32_t b){
	return a+b;
}

uint32_t conversion(unsigned char* bytes, int len){
	uint32_t n = 0;
	for(int i=0;i<len;i++){
		n <<= 8;
		n += bytes[i];
	}
	return n;
}

void hex32(uint32_t n){
	cerr << "(0x";
	for(int i=7;i>=0;i--){
		uint32_t digits = 0xF << (4*i);
		cerr << hex << ((n & digits) >> (4 * i));
	}
	cerr << ")";
}