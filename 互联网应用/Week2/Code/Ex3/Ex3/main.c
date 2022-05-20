//
//  main.c
//  Ex3
//
//  Created by 赵君川 on 2021/3/24.
//
#include <unistd.h>
#include <stdio.h>

//exec(),替换子进程中的内容，子进程的PID不会变化，只是代码被新的程序替代
int main(int argc, const char * argv[]) {
    char *arg[] = {"/bin/ls", 0};
    
    if (fork() == 0) {
        printf("In child process:\n");
//        第一个参数：路径，第二个参数：数组的指针
        execv(arg[0], arg);
//        不会打印被覆盖掉，直接运行新的程序
        printf("I will never be called\n");
    }
    printf("Execution continues in parent process\n");
}
