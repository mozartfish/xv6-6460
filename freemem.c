#include "types.h"
#include "stat.h"
#include "user.h"
#include "memlayout.h"
int main(int argc, char *argv[])
{
    //int i;
    //printf(1, "freemem()%d\n", freemem());
    //printf(1, "PHYSTOP: %d\n", PHYSTOP);
    printf(1, "%d\n", freemem());
    exit();
}
