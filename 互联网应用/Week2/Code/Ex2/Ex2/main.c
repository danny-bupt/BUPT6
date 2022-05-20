//
//  main.c
//  Ex2
//
//  Created by 赵君川 on 2021/3/24.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, const char * argv[]) {
    pid_t t;
    
//    获取当前PID的值(父进程的进程号)
    printf("Original program, pid=%d\n", getpid());
//    t与PID不一样只是返回值
    t = fork();
    if (t == 0) {
        printf("In child process, pid=%d, ppid=%d\n"
               , getpid(), getppid());
    } else {
//        父进程中的t返回值是子进程的进程号
        printf("In parent, pid=%d, fork returned=%d\n", getpid(), t);
    }
}
