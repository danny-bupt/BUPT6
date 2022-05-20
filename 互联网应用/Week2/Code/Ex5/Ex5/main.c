//
//  main.c
//  Ex5
//
//  Created by 赵君川 on 2021/3/24.
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    char quit='.';
    char buf[10];
    int fd;
    if((fd = open("out.out",O_RDWR | O_CREAT,0))==-1)
        printf("Error in opening\n");
    while(buf[0]!=quit)
    {
        //0 --> 标准输入，键盘去读1个字节
        read(0,buf,1);
        //buf写到文件描述符里
        write(fd,buf,1);
        //1 --> 标准输出，向屏幕输出
        write(1,buf,1);
    }
    close(fd);
}
