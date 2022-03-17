
#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

// User program to test lottery scheduler
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf(1, "Error: Invalid number of arguments for lottery scheduler\n");
        exit();
    }

    // negative number check
    if (argv[1][0] == '-')
    {
        printf(1, "Error: Invalid number of tickets. Negative tickets passed as argument\n");
        exit();
    }

    int num_tickets = atoi(argv[1]); // the number of tickets the process should run with
    settickets(num_tickets);
    exec(argv[2], &argv[2]);
    exit();
}