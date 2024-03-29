#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "pstat.h"

int sys_fork(void)
{
  return fork();
}

int sys_exit(void)
{
  exit();
  return 0; // not reached
}

int sys_exit2(void)
{
  int exit_status;
  if (argint(0, &exit_status) < 0)
    return -1;
  return exit2(exit_status);
}

int sys_wait(void)
{
  return wait();
}

int sys_wait2(void)
{
  int *exit_status;
  if (argptr(0, (char **)&exit_status, sizeof(int)) < 0)
    return -1;
  return wait2(exit_status);
}

// these two functions are based on how switchuvm is used for growproc in proc.c and sys_sbreak
int sys_settickets(void)
{
  int tickets;
  if (argint(0, &tickets) < 0)
    return -1;
  // Set the number of tickets
  myproc()->tickets = tickets;
  return 0;
}

int sys_getpinfo(void)
{
  struct pstat *p;
  if (argptr(0, (char **)&p, sizeof(struct pstat)) < 0)
    return -1;
  getpinfo(p);
  return 0;
}

int sys_kill(void)
{
  int pid;

  if (argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int sys_getpid(void)
{
  return myproc()->pid;
}

int sys_freemem(void)
{
  // return myproc()->pid;
  return freemem();
}

int sys_sbrk(void)
{
  int addr;
  int n;

  if (argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if (growproc(n) < 0)
    return -1;
  return addr;
}

int sys_sleep(void)
{
  int n;
  uint ticks0;

  if (argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while (ticks - ticks0 < n)
  {
    if (myproc()->killed)
    {
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
