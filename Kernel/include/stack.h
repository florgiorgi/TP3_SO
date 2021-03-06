#ifndef STACK_H
#define STACK_H

#include "types.h"

/* Stack frame structure taken from RowDaBoat */
typedef struct StackFrame{
  qword gs;
  qword fs;
  qword r15;
  qword r14;
  qword r13;
  qword r12;
  qword r11;
  qword r10;
  qword r9;
  qword r8;
  qword rsi;
  qword rdi;
  qword rbp;
  qword rdx;
  qword rcx;
  qword rbx;
  qword rax;

  qword rip;
  qword cs;
  qword eflags;
  qword rsp;
  qword ss;
  qword base;
} StackFrame;

/* Fills all registers of the stackframe structure with it's values */
void * fillStackFrame(void *, void *);

#endif
