#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#include <unistd.h>
#include <stdio.h>
#include <termios.h>

void terminalInit();
void terminalCleanup();

#endif
