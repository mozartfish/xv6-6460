#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main(int argc, char *argv[])
{
    // check more than 2 args
    if (argc > 2)
    {
        return -1;
        exit();
    }

    struct pstat *p_info = (struct pstat *)malloc(sizeof(struct pstat)); // allocate a process info struct - REMEMBER TO FREE

    // ps
    if (argc == 1)
    {
        getpinfo(p_info); // get process info
        //printf(1, "Hello, World\n");
       // getpinfo(p_info);
        //printf(1, "getpinfo\n");
        // free(p_info);
        // exit();

        printf(1, "PID TICKETS TICKS\n");
        int i;
        for (i = 0; i < NPROC; ++i)
        {
            if (p_info->proc[i].inuse)
            {
                printf(1, "%d %d %d\n", p_info->proc[i].pid, p_info->proc[i].tickets, p_info->proc[i].ticks);
            }
        }
        // free(p_info);
        // exit();
    }

    // ps -r
    if (argc == 2)
    {
        if (strcmp(argv[1], "-r") == 0)
        {
            while (1)
            {
                getpinfo(p_info); // get process info
                printf(1, "PID TICKETS TICKS\n");
                int i;
                for (i = 0; i < NPROC; ++i)
                {
                    if (p_info->proc[i].inuse)
                    {
                        printf(1, "%d %d %d\n", p_info->proc[i].pid, p_info->proc[i].tickets, p_info->proc[i].ticks);
                    }
                }
                sleep(100); // sleep every 100 ticks
            }
        }
    }
    free(p_info);
    exit();
}