#include "types.h"
#include "stat.h"
#include "user.h"
#include <stddef.h>
int main(int argc, char *argv[])
{
    int pid;
    printf(1, "exit status test");
    pid = fork();
    if (pid < 0)
    {
        printf(1, "fork failed %d\n", pid);
    }
    else if (pid == 0)
    {
        // child process
        printf(1, "child process. (pid: %d)\n", (int)getpid());
        exit2(0);
    }
    else
    {
        // parent process
        int wait = wait2(NULL);
        printf(1, "parent process of child %d (wait:%d)(pid:%d)\n", pid, wait, (int)getpid());
    }
    exit2(0);
}
