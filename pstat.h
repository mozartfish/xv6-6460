#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

struct pstatentry {
  int inuse;   // whether this slot of the process table is in use (1 or 0)
  int tickets; // the number of tickets this process has
  int pid;     // the PID of each process 
  int ticks;   // the number of times this process was preempted while running
};

struct pstat {
  struct pstatentry proc[NPROC];
};

#endif // _PSTAT_H_