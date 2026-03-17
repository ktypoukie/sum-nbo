#include <iostream>
#include <stdint.h>
#include "sum.h"
using namespace std;

int main(int argc, char *argv[]){
	if(argc < 2){
		cerr << "1개 이상의 파일을 입력해주세요.\n";
		return 1;
	}
	else{
		uint32_t num = 0;
		for(int i=1;i<argc;i++){
			FILE* file = fopen(argv[i],"rb");
			if(file == NULL){
				cerr << argv[i] <<  ": 존재하지 않는 파일입니다.\n";
				return 1;
			}
			unsigned char bytes[4];
			if(!fread(bytes,4,1,file)){
				cerr << argv[i] << ": 파일의 크기가 4바이트보다 작습니다.\n";
				return 1;
			}
			fclose(file);
			num = sum(num,conversion(bytes,4));
		}

		for(int i=1;i<argc;i++){
			FILE* file = fopen(argv[i],"rb");
			unsigned char bytes[4];
			fread(bytes,4,1,file);
			fclose(file);
			cerr << dec << conversion(bytes,4);
			hex32(conversion(bytes,4));
			if(i < argc-1) cerr << " + ";
			else cerr << " = ";
		}
		cerr << dec << num;
		hex32(num);
		cerr << "\n";
	}
}
