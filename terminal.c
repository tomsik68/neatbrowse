#include "terminal.h"

static struct termios oldt;

void terminalInit(){
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void terminalCleanup(){
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
