//
//  main.c
//  Ex4
//
//  Created by 赵君川 on 2021/3/24.
//

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char buf1[]="abcdefghij";
char buf2[]="ABCDEFGHIJ";
#define FILE_MODE 0644

int main(int argc, const char * argv[]) {
//    fd：表示文件描述符
    int fd;
    
    if ((fd=creat("file.hole",FILE_MODE))<0)
    {
        printf("creat error\n");
//        异常退出
        exit(1);
    }
    
    if (write(fd,buf1,10)!=10)
    {
        printf("buf1 write error\n");
        exit(1);
    }
//    offset now = 10
    
//    改变写入的位置
    if (lseek(fd,40,SEEK_SET)==-1)
    {
        printf("lseek error\n");
        exit(1);
    }
//    offset now = 40
    
    if (write(fd,buf2,10)!=10)
    {
        printf("buf2 write error\n");
        exit(1);
    }
//    offset now = 50
    
    exit(0);
}
