//
//  main.c
//  Ex1
//
//  Created by 赵君川 on 2021/3/24.
//

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, const char * argv[]) {
    pid_t t;
    t = fork();
    printf("fork returned %d\n", t);
    exit(0);
}
