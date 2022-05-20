//
//  main.c
//  byteorder
//
//  Created by 赵君川 on 2021/3/25.
//

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
//    互相共用
    union {
        //short --> 两个字节
        short s;
        //char c[2]
        char c[sizeof(short)];
    }un;
    
    //两种情况,big,little:
    //c[0]=1,c[1]=2 --> big;
    //c[0]=2,c[1]=1 --> little;
    //c[0]在低地址，c[1]在高地址
    un.s=0x0102;
    if (sizeof(short)==2){
        if (un.c[0]==1 &&un.c[1]==2) printf("big-endian\n");
        else if (un.c[0]==2 &&un.c[1]==1) printf("little-endian\n");
        else printf("Unknow\n");
    }
    else {
        printf("sizeof(short)=%d\n",sizeof(short));
    }
    exit(0);
}
